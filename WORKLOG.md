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

### 2024-05-27

 - Update pbin function to accept size to create a variable-length array
 - Fixed the length of padding loop to work properly

### 2024-05-28

- Add simple C/C++ continuous integration using Github Actions
- Add test automation for already implemented steps of the DES algorithm
- Add `make test` command to Makefile
- Tried to fix the key schedule generation

### 2024-05-29

- Properly implemented the key schedule generation for all 16 rounds
- Update the gh action to actually run `make test` and prettify the output
- Fix the improperly shifted bits of c and d in the key schedule generation
- Added tests for key schedule generation
- Added code that implements the DES algorithm for all 16 rounds for a 64 bit block
- Reordered the functions in the des.c file to be more organized
- Added tests for the DES algorithm
- Added a function to reverse the initial permutation (inverse)
- Read through how the decryption for DES works
- Implement DES decryption for a 64 bit block
- Added tests for the DES decryption
- Added working functions for DES encryption and decryption on entire files
    - Runs encryption and write on every 64 bit block of a file
    - Runs decryption and write on every 64 bit block of a file
    - Added padding to the end of the file to make sure the last block is 64 bits
    - Properly encrypts and decrypts with padding

### 2024-05-30

- Looking into SHA-256 encryption to help others
- Fix how a file is read into `n` length char array in sha.c
- Add triple DES encryption and decryption for files
- Cleaned and updated main and makefile to include triple DES support
- Read about DES modes
- Looking into multi-threading for DES

## EDMUND CHIN
 
### 2024-05-23  

- researched the sha-256 algorithm  

### 2024-05-24    

- researched more of the sha-256 algorithm
- started the sha-256 logic

### 2024-05-27  

- worked on more of the sha-256 algorithm logic
- added the first initial 8 hash values and 64 constants
- implemented the right rotate logic
- implemented the first 2 functions used in hash computation
  
### 2024-05-28  
- more sha logic  

### 2024-05-29  
- hash calculations + read being funny(broken)

### 2024-05-30  
- tried implementing fread but couldn't make it work

### 2024-05-31    
- finished message schedule code  

### 2024-06-01   
- finished the logic for sha-256 but is broken  

### 2024-06-03  
- started working on the presentation in docs

### 2024-06-05  
- started making a flow chart to explain

### 2024-06-07  
- continued with the flowchart

### 2024-06-09  
- scrapped the flowchart
- finished the presentation.md for sha256 I think

## CLEMENS LI
- 
### 2024-05-23

 - Continued research on the SHA-256 hash
 - Added the sha.h and sha.c files and updated the Makefile
 - Started the bit padding step of the hash.
 - Added hash constants to the repository.

### 2024-05-24

 - Continued research
 - Changed padding function to use an array of 32-bit integers
 - Finished appending plaintext into 32-bit ints

### 2024-05-25

 - Fixed pointers and appended plaintext into 32-bit ints for n chunks instead of just one
 - Padding function appends the bit of 1

### 2024-05-28

 - Fixed padding for appending the plaintext
 - Added 0 padding for 448mod512 bits
 - Added plaintext length at the end of message as a 64-bit integer

### 2024-05-29

 - Began rotation encryption
 - Put constant arrays in sha.h rather than sha.c, turned hashes into binary and left the rest as hexes

 ### 2024-05-30

 - Implemented padding into the main encryption function
 - Finished the second step of encryption (funct0 & funct1)

 ### 2024-05-31

 - Fixed funct1
 - Implemented padding chunks into separate 512 bit sections

 ### 2024-06-03
 
 - Created a new sha_256 function that returns the encrypted output as an array of 4 64-bit integers

 ### 2024-06-05

 - Worked on PRESENTATION.md




## TRACEY LIN

### date x

info

### date y

info

