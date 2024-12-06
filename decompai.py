import sys

import pyhidra
from pyhidra.launcher import HeadlessPyhidraLauncher
from api_key import BASE_URL, API_KEY
from openai import OpenAI
import os

# Change what prompt to import
from gpt_prompts import gpt_prompt_example as gpt_prompt


def generate_output_filename(input_file: str, output_dir: str, suffix: str) -> str:
    """
    Generate an output file path based on the input file name and suffix.
    """
    base_name = os.path.splitext(os.path.basename(input_file))[0]
    return os.path.join(output_dir, f"{base_name}_{suffix}.c")



def ghidra_decomp(input_file: str, output_dir: str) -> bool:

    ghidra_output_file = generate_output_filename(input_file, output_dir, "ghidra_output")

    print(f'Running pyhidra on {input_file}, outputting to {ghidra_output_file}')

    status = False
    with pyhidra.open_program(input_file) as flat_api:
        program = flat_api.getCurrentProgram()
        listing = program.getListing()
        function_manager = program.getFunctionManager()
        print(listing.getCodeUnitAt(flat_api.toAddr(0x1234)))

        # We are also free to import ghidra while in this context to do more advanced things.
        from ghidra.app.decompiler import DecompInterface
        # Initialize the decompiler interface
        decompiler = DecompInterface()
        decompiler.openProgram(program)

        # Iterate through the functions
        functions = function_manager.getFunctions(True)  # Retrieve all functions
        for function in functions:
            print(f"ghidra: Decompiling function: {function.getName()}", file=sys.stderr)

            # Decompile the current function
            results = decompiler.decompileFunction(function, 60, flat_api.monitor)
            if results and results.decompiledFunction:
                pseudocode = results.getDecompiledFunction().getC()

                # Print the pseudocode
                # print('ghidra pseudocode')
                # print(pseudocode)

                # Save pseudocode to a file
                with open(ghidra_output_file, "a") as output_file:
                    output_file.write(pseudocode)
                status = True
            else:
                print(f"ghidra: Failed to decompile function: {function.getName()}", file=sys.stderr)

        # Cleanup
        decompiler.dispose()
    return status, ghidra_output_file

def call_gpt(input_file: str, ghidra_output_file: str, output_dir: str, model='oai-gpt-4o', n_choices=1) -> bool:
    
    text_input = ''
    gpt_output_file = generate_output_filename(input_file, output_dir, "gpt_output")

    print(f"Connecting to GPT and saving output to {gpt_output_file}")

    with open(ghidra_output_file, 'r') as input_file:
        text_input = input_file.read()
    print(text_input)

    client = OpenAI(api_key=API_KEY, base_url=BASE_URL)

    # use client as usual
    # see https://platform.openai.com/docs/guides/text-generation?lang=python
    # print(client.models.list())

    print(f"Connecting to chatgpt {model}")
    completion = client.chat.completions.create(
        model=model,
        messages=[
            {"role": "system", "content": gpt_prompt},
            {
                "role": "user",
                "content": text_input
            }
        ]
    )

    response = completion.choices[0].message.content
    if response is None:
        print('call_gpt: gpt response is None', file=sys.stderr)
        return False
    print(f'Saving gpt response to {gpt_output_file}')
    with open(gpt_output_file, "w") as output_file:
        output_file.write(response)
    return True


def main():
    if len(sys.argv) != 3:
        print("Usage: python script.py <input_file> <output_dir>")
        return

    input_file = sys.argv[1]
    output_dir = sys.argv[2]
    os.makedirs(output_dir, exist_ok=True)

    status, ghidra_output_file = ghidra_decomp(input_file, output_dir)
    if not status:
        print("Failed Ghidra processing")
        return

    if not call_gpt(input_file, ghidra_output_file, output_dir):
        print("Failed GPT processing")
        return

    print("Finished decompiling and GPT processing")


if __name__ == '__main__':
    main()



