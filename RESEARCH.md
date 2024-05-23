# Research

## DES Algorithm

### General

- Utilizes a 64 bit key.
- Chunk the data to-be-encrypted into 64 bit blocks.
- A block is subjected to an Initial Permutation (IP):

```
{
    58, 50, 42, 34, 26, 18, 10, 2, 
    60, 52, 44, 36, 28, 20, 12, 4, 
    62, 54, 46, 38, 30, 22, 14, 6, 
    64, 56, 48, 40, 32, 24, 16, 8, 
    57, 49, 41, 33, 25, 17,  9, 1, 
    59, 51, 43, 35, 27, 19, 11, 3, 
    61, 53, 45, 37, 29, 21, 13, 5, 
    63, 55, 47, 39, 31, 23, 15, 7
}
```

- A block is then subjected to 16 rounds of Key-Dependent Computation (F) with a Key Schedule (KS) function.
- A block is then subjected to the inverse of the Initial Permutation (IP-1):

```
{
    40, 8, 48, 16, 56, 24, 64, 32, 
    39, 7, 47, 15, 55, 23, 63, 31, 
    38, 6, 46, 14, 54, 22, 62, 30, 
    37, 5, 45, 13, 53, 21, 61, 29, 
    36, 4, 44, 12, 52, 20, 60, 28, 
    35, 3, 43, 11, 51, 19, 59, 27, 
    34, 2, 42, 10, 50, 18, 58, 26, 
    33, 1, 41,  9, 49, 17, 57, 25
}
```

### Key-Dependent Computation

- L is a 32 bit block, R is a 32 bit block, K is a 48 bit block (chosen from 64 bit block)
- L’ = R
- R’ = L (bit by bit addition modulo 2) F(R,K)
- If L’R’ is output of 16th iteration, then R’L’ is preoutput block.
- At each round, a different block of K key bits are chosen from the 64 bit key.
