#include <stdio.h>
#include <stdint.h>

void tricky_function(uint64_t input) {
    uint64_t key = 0xdeadbeefcafebabe;
    uint64_t result = (input ^ key) * 0x1337;
    
    // Obfuscated loop with unpredictable control flow
    for (int i = 0; i < 5; i++) {
        result ^= (result >> ((i + input) % 8));
        result += 0xabcdef;
        if (result & (1 << i)) {
            result ^= key;
        } else {
            result += key;
        }
    }
    
    printf("Obfuscated result: %llx\n", result);
}

int main() {
    char obfuscated_input[] = {0x5a, 0x1f, 0x3b, 0x2c, 0x1d};
    uint64_t input = 0;
    
    // XOR deobfuscation loop to make control flow hard to follow
    for (int i = 0; i < sizeof(obfuscated_input); i++) {
        input = (input << 8) | (obfuscated_input[i] ^ (i * 0x42));
    }

    // Inline assembly for added complexity
    __asm__("nop\n\t"
            "xor %%rax, %%rax\n\t"
            "add %0, %%rax\n\t"
            : 
            : "r"(input)
            : "rax");

    tricky_function(input);
    return 0;
}

