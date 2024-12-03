// Here's a cleaned-up version of your C code. This retains the original logic but removes extraneous code and sections like stack protection, initialization, and other unrelated routines.

```c
#include <stdio.h>
#include <string.h>

void obfuscate_and_print(unsigned long param) {
    unsigned long obfuscated_value = (param ^ 0xdeadbeefcafebabe) * 0x1337;
    for (int i = 0; i < 5; i++) {
        obfuscated_value = obfuscated_value ^ (obfuscated_value >> ((unsigned char)i + (char)param & 7));
        unsigned long temp = obfuscated_value + 0xabcdef;
        if (((long)(1 << ((unsigned char)i & 0x1f)) & temp) == 0) {
            obfuscated_value += 0xdeadbeefcbaa88ad;
        } else {
            obfuscated_value = temp ^ 0xdeadbeefcafebabe;
        }
    }
    printf("Obfuscated result: %llx\n", obfuscated_value);
}

unsigned long calculate_param() {
    const char constant_str[5] = "Z\x1f;,\x1d";
    unsigned long calculated_value = 0;
    for (int i = 0; i < 5; i++) {
        calculated_value = (unsigned long)(i * 0x42 ^ (int)constant_str[i]) | (calculated_value << 8);
    }
    return calculated_value;
}

int main() {
    unsigned long param = calculate_param();
    obfuscate_and_print(param);
    return 0;
}
// ```

// ### Explanation of Changes:
// 1. **Function Consolidation**: The obfuscation logic is handled in a single function `obfuscate_and_print`.
// 2. **Parameter Calculation**: The calculation of the parameter based on the constant string is encapsulated in `calculate_param`.
// 3. **Removed Unused Functions/Variables**: The original initialization and unnecessary functions have been removed to maintain focus on the core functionality.
// 4. **Maintain Naming Conventions**: The function names and variables have been retained with meaningful names.

// This refactored code is concise and directly represents the intended functionality without the noise of unrelated low-level details.