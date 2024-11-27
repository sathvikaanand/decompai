import sys

import pyhidra
from pyhidra.launcher import HeadlessPyhidraLauncher
from api_key import BASE_URL, API_KEY
from openai import OpenAI

# Change what prompt to import
from gpt_prompt import gpt_prompt_better as gpt_prompt

GHIDRA_OUTPUT_FILE = './output/ghidra_output.c'
GPT_OUTPUT_FILE = './output/gpt_output.c'

def ghidra_decomp(input_file: str) -> bool:

    print(f'Running pyhidra on {input_file}')

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
                with open(GHIDRA_OUTPUT_FILE, "a") as output_file:
                    output_file.write(pseudocode)
                status = True
            else:
                print(f"ghidra: Failed to decompile function: {function.getName()}", file=sys.stderr)

        # Cleanup
        decompiler.dispose()
    return status

def call_gpt(file_name: str, model='oai-gpt-4o-mini', n_choices=1) -> bool:
    
    text_input = ''
    with open(GHIDRA_OUTPUT_FILE, 'r') as input_file:
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
    print(f'Saving gpt response to {GPT_OUTPUT_FILE}')
    with open(GPT_OUTPUT_FILE, "w") as output_file:
        output_file.write(response)
    return True


def main():
    status = ghidra_decomp(sys.argv[1])
    if not status:
        print("Failed ghidra processing")
        return
    status = call_gpt(GHIDRA_OUTPUT_FILE)
    if not status:
        print("Failed gpt processing")
        return
    print("Finished decompiling and gpt processing")


if __name__ == '__main__':
    main()



