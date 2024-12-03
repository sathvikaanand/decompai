```c
#include <stdio.h>
#include <string.h>

void obfuscate_and_print(unsigned long param) {
    unsigned long obfuscated_result;
    int i;

    obfuscated_result = (param ^ 0xdeadbeefcafebabe) * 0x1337;
    for (i = 0; i < 5; i++) {
        obfuscated_result ^= obfuscated_result >> ((unsigned char)i + (char)param & 7);
        unsigned long temp = obfuscated_result + 0xabcdef;

        if (((long)(1 << ((unsigned char)i & 0x1f)) & temp) == 0) {
            obfuscated_result += 0xdeadbeefcbaa88ad;
        } else {
            obfuscated_result = temp ^ 0xdeadbeefcafebabe;
        }
    }
    printf("Obfuscated result: %llx\n", obfuscated_result);
}

void main_function(void) {
    unsigned long computed_value = 0;
    unsigned int i;
    char key[5];

    strncpy(key, "Z\x1f;,\x1d", 5);
    for (i = 0; i < 5; i++) {
        computed_value = (long)(i * 0x42 ^ (int)key[i]) | computed_value << 8;
    }
    obfuscate_and_print(computed_value);
}

int main() {
    main_function();
    return 0;
}
```