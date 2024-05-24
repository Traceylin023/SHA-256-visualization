#include "main.h"
#include "des.h"
#include "sha.h"

int main(int argc, char* argv[]) {

    // Plain: Hello World!
    // Decimal: 5216694956355245935
    // L: 1214606444
    // R: 1864390500
    // KEY: 3759860997584293892

    pbin(5216694956355245935ULL, 64);
    pbin(initial_permutation(5216694956355245935ULL), 64);

    printf("\n");

    pbin(3759860997584293892ULL, 64);
    pbin(pc_1_c(3759860997584293892ULL), 28);
    pbin(pc_1_d(3759860997584293892ULL), 28);

    pbin(key_shift(pc_1_c(3759860997584293892ULL), 1), 28);
    pbin(key_shift(pc_1_d(3759860997584293892ULL), 1), 28);

    pbin(pc_2(key_shift(pc_1_c(3759860997584293892ULL), 1), key_shift(pc_1_d(3759860997584293892ULL), 1)), 48);

    // printf("\n");

    // if (strcmp(argv[1], "encrypt") == 0) {

    // }


    // else if (strcmp(argv[1], "decrypt") == 0) {

    // }

}
