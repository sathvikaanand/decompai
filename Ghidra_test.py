import pyhidra

with pyhidra.open_program("binary_file.exe", analyze=False) as flat_api:
    from ghidra.program.util import GhidraProgramUtilities

    program = flat_api.getCurrentProgram()
    if GhidraProgramUtilities.shouldAskToAnalyze(program):
        flat_api.analyzeAll(program)