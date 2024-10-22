# DataExtractor

## Overview

**DataExtractor** is a C++ command-line tool that allows users to:

1. Decrypt an encrypted file (`encrypted_data.bin`) using a provided encryption key (`key.bin`).
2. Obfuscate the encryption key to `obfuscated_key.bin` for added security.
3. De-obfuscate the obfuscated key and use it to decrypt the data.

This project showcases basic cryptographic operations (AES-256-CBC encryption/decryption) and key obfuscation techniques, along with reverse engineering the obfuscated key to decrypt data.

## Features

- **AES-256-CBC decryption** using OpenSSL.
- **XOR-based obfuscation** for key security.
- Ability to decrypt encrypted data after de-obfuscating the key.

---

## Prerequisites

Make sure you have the following installed on your system:

- **C++17** or later
- **OpenSSL** (for cryptographic operations)
- **CMake** (for building the project)

### Installation of Dependencies (macOS with Homebrew)

1. **Install OpenSSL**:

   ```bash
   brew install openssl

2. **Install CMake**:

   ```bash
   brew install cmake

---

### Steps to Generate Key, IV, and Encrypt Data

Before you build and run the DataExtractor tool, you'll need to generate a symmetric encryption key, an initialization vector (IV), and encrypted data for testing.

Use OpenSSL to generate a 256-bit key and a 128-bit IV.

# 1. Generate a 32-byte (256-bit) key

   ```bash
   openssl rand -out key.bin 32
   ```


# 2. Generate a 16-byte (128-bit) IV

```bash
openssl rand -out iv.bin 16
```


# 3. Encrypt a File Using OpenSSL (AES-256-CBC)
You can encrypt a file (e.g., plaintext.txt) using the key and IV you generated. This creates an encrypted output file, encrypted_data.bin
    
    ```bash
    openssl enc -aes-256-cbc -in plaintext.txt -out encrypted_data.bin -K $(xxd -p -c32 key.bin) -iv $(xxd -p -c 16 iv.bin)
    ```


# 4. Running the Program

Once the project is built, navigate to the build directory and run the executable:
    ```bash
    ./DataExtractor

You will be presented with the following menu options:

Select an option:
1. Decrypt "encrypted_data.bin" with "key.bin"
2. Obfuscate "key.bin" to "obfuscated_key.bin"
3. De-obfuscate "obfuscated_key.bin" and decrypt "encrypted_data.bin"

Make sure that key.bin, iv.bin, and encrypted_data.bin are in the same directory as the executable. You can put them in the build folder.