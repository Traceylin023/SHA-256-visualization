#include "main.h"
#include "des.h"
#include "sha.h"

void assert(uint64_t input, uint64_t expected, char *message) {
    if (input != expected) {
        printf("\033[1;31mFailed\033[0m: \033[0;34m%s\033[0m\n\n", message);
        printf("\033[1;36mExpected\033[0m:\033[0;34m");
        pbin(expected, 64);
        printf("\033[0m\033[1;33mReceived\033[0m:\033[0;34m");
        pbin(input, 64);
        printf("\033[0m");
        exit(1);
    }
    else {
        printf("\033[1;32mPassed\033[0m: \033[0;34m%s\033[0m\n", message);
    }
}

void run_tests() {

    uint64_t m = 81985529216486895ULL;
    uint64_t k = 1383827165325090801ULL;

    // Test initial_permutation
    uint64_t ip = initial_permutation(m);
    assert(ip, 14699974583363760298ULL, "initial_permutation");

    // Test split_l_r
    uint64_t *split = split_l_r(ip);
    assert(split[0], 3422604543, "split_l");
    assert(split[1], 4037734570, "split_r");

    // Test pc_1_c
    uint64_t pc1c = pc_1_c(k);
    assert(pc1c, 252496559ULL, "pc_1_c");

    // Test pc_1_d
    uint64_t pc1d = pc_1_d(k);
    assert(pc1d, 89548687ULL, "pc_1_d");

}

int main(int argc, char* argv[]) {

    // Decimal: 81985529216486895
    // L: 19088743
    // R: 2309737967
    // KEY: 1383827165325090801

    if (argc == 2 && strcmp(argv[1], "test") == 0) {
        run_tests();
    }

    // if (strcmp(argv[1], "encrypt") == 0) {

    // }


    // else if (strcmp(argv[1], "decrypt") == 0) {

    // }

    // char c[] = "hello";
    // uint32_t *d;
    // d = pad(c,1);
    // printf("\n");
    // pbin(*d, 32);
    // pbin(*(d+1), 32);

    // des_encrypt("tests/input.txt", "tests/key.txt", "tests/output.txt");
    
    // sha_encrypt("message.txt", "output.txt");
}
