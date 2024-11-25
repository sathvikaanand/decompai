import pyhidra
# import ghidra
from pyhidra.launcher import HeadlessPyhidraLauncher



with pyhidra.open_program("example") as flat_api:
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
        print(f"Decompiling function: {function.getName()}")

        # Decompile the current function
        results = decompiler.decompileFunction(function, 60, flat_api.monitor)
        if results and results.decompiledFunction:
            pseudocode = results.getDecompiledFunction().getC()

            # Print the pseudocode
            print(pseudocode)

            # Save pseudocode to a file
            with open("decompiled_output.c", "w") as output_file:
                output_file.write(pseudocode)
        else:
            print(f"Failed to decompile function: {function.getName()}")

        break  # Only decompile the first function

    # Cleanup
    decompiler.dispose()
