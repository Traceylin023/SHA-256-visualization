[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/ecp4su41)

# CLEonsTRAntInnoVACHIN

![GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/Stuycs-K/final-project-09-chen-ivan-chin-edmund-li-clemens/c-cpp.yml?style=for-the-badge)

## Group Info 

Group Members: 

- Ivan Chen
- Edmund Chin
- Clemens Li
- Tracey Lin (the leech)

## Research Notes (transfer to this file later)

https://docs.google.com/document/d/1SLU-Vclc7APL3wPdBwLeB8y79mH-YCzmRIgBG8pXz-g/edit?usp=sharing

## Overview

DES (Data Encryption Standard) is a symmetric key algorithm that encrypts data in 64-bit blocks. It uses a 64-bit key to encrypt and decrypt data. The algorithm is based on a Feistel network, which is a symmetric style structure used in the construction of block ciphers. The algorithm consists of an initial permutation, 16 rounds of key-dependent computation, and a final permutation. The key-dependent computation involves splitting the data block into two 32-bit blocks, L and R, and applying a function F to R using a 48-bit key. The key schedule function generates the 16 round keys from the 64-bit key. The algorithm is designed to be secure against differential and linear cryptanalysis.

Triple DES (3DES) is a variant of DES that applies the DES algorithm three times to each data block. It uses three 64-bit keys, K1, K2, and K3, and encrypts the data block with K1, decrypts it with K2, and encrypts it again with K3. This provides a higher level of security than DES, but is approximately 3 times slower due to the increased number of rounds.

To generate each 64 bit key, an implementation of SHA-256 will be used. SHA-256 is a cryptographic hash function that generates a 256-bit hash value from an input message. It is designed to be secure against collision attacks and pre-image attacks. The algorithm consists of several rounds of message expansion, mixing, and compression, and uses a set of constant values and functions to generate the hash value. A truncated hash value is used as the key for this implementation of the DES algorithm.

This project aims to implement the TripleDES algorithm with SHA-256 as the Key Derivation Function (KDF) in C. The implementation of TripleDES was done in reference to the specifications in [FIPS PUB 46-3](https://csrc.nist.gov/files/pubs/fips/46-3/final/docs/fips46-3.pdf). The implementation of SHA-256 was done in reference to the specifications in [FIPS PUB 180-4](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf). Note that TripleDES is not recommended for new applications due to its slow speed and the availability of more secure algorithms such as AES. NIST has deprecated the use of TripleDES for new applications and recommends the use of AES instead.

## Instructions


