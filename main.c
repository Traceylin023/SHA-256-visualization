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
    // u_int64_t * split = split_l_r(initial_permutation(5216694956355245935ULL));

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
    // pbin(input_key_xor(e(12492240UL), key_schedule(3759860997584293892ULL, 1)), 48);
    // pbin(s_box_substitution(input_key_xor(e(12492240UL), key_schedule(3759860997584293892ULL, 1))), 32);
    // pbin(p(s_box_substitution(input_key_xor(e(12492240UL), key_schedule(3759860997584293892ULL, 1)))), 32);

    // uint64_t l = 3745570514UL;
    // uint64_t r = p(s_box_substitution(input_key_xor(e(12492240UL), key_schedule(3759860997584293892ULL, 1))));
    // uint64_t r = f(12492240UL, key_schedule(3759860997584293892ULL, 1));

    // pbin(l, 32);
    // pbin(r, 32);
    // pbin(l_r_xor(l, r), 32);

    // if (strcmp(argv[1], "encrypt") == 0) {

    // }


    // else if (strcmp(argv[1], "decrypt") == 0) {

    // }

    char c[] = "hello";
    uint32_t *d = pad(c, 1);
    for (int i = 0; i < 5; i++) {
        // pbin(c[i], 32);
        pbin(d[i], 32);
        printf("\n");
    }


}
