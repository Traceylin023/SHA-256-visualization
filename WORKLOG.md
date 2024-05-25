# Work Log

## IVAN CHEN

### 2024-05-22

- Continued to work on researching the implementation of DES encryption.
- Set up repository with Makefile and main.c file.

### 2024-05-23

- Continued to work on researching the implementation of DES encryption.
- Added the permutation tables for all stages of DES encryption.
- Added a function to print binary of a 64-bit integer.
- Made that function print in the opposite order of the bits for easier debugging.
- Implemented the initial permutation stage.
- Implemented key-splitting.

### 2024-05-24

- Update pbin function to print n bits
- Implemented key shifting based on round and pc_2
- Implement function E (expansion of last 32 bits in block to 48 bits)
- Implement function which xors the 48 bit key with the 48 bit block
- Add s_boxes function
    - Splits the 48 bit block into 8 6-bit blocks
    - Calculates the row and column of each 6-bit block (row = first and last bit, column = middle 4 bits)
    - Looks up the value in the s-boxes
    - Concatenates the 8 4-bit blocks into a 32-bit block
- Started implementing the P permutation



## EDMUND CHIN

### date x

info

### date y

info


## CLEMENS LI

### 2024-05-23

 - Continued research on the SHA-256 hash
 - Added the sha.h and sha.c files and updated the Makefile
 - Started the bit padding step of the hash.
 - Added hash constants to the repository.

### date y




## TRACEY LIN

### date x

info

### date y

info

