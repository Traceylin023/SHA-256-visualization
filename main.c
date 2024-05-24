#include "main.h"
#include "des.h"
#include "sha.h"

int main(int argc, char* argv[]) {

    // Plain: Hello Wo
    // Decimal: 5216694956355245935
    // L: 1214606444
    // R: 1864390511 (12492240)
    // KEY: 3759860997584293892

    // pbin(5216694956355245935ULL, 64);
    // pbin(initial_permutation(5216694956355245935ULL), 64);

    // printf("\n");

    // pbin(3759860997584293892ULL, 64);
    // pbin(pc_1_c(3759860997584293892ULL), 28);
    // pbin(pc_1_d(3759860997584293892ULL), 28);

    // pbin(key_shift(pc_1_c(3759860997584293892ULL), 1), 28);
    // pbin(key_shift(pc_1_d(3759860997584293892ULL), 1), 28);

    // pbin(pc_2(key_shift(pc_1_c(3759860997584293892ULL), 1), key_shift(pc_1_d(3759860997584293892ULL), 1)), 48);
    // pbin(key_schedule(3759860997584293892ULL, 1), 48);

    // printf("\n");

    // pbin(12492240UL, 64);
    // pbin(e(12492240UL), 48);
    // pbin(in_key_xor(e(12492240UL), key_schedule(3759860997584293892ULL, 1)), 48);

    s_boxes(in_key_xor(e(12492240UL), key_schedule(3759860997584293892ULL, 1)));

    // if (strcmp(argv[1], "encrypt") == 0) {

    // }


    // else if (strcmp(argv[1], "decrypt") == 0) {

    // }

    char *c = "hello";
    for (int i = 0; i < 16; i++) {
        pbin(c, 32);
    }

}
