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
Install CMake:

bash
Copy code
brew install cmake
Steps to Generate Key, IV, and Encrypt Data
Before you build and run the DataExtractor tool, you'll need to generate a symmetric encryption key, an initialization vector (IV), and encrypted data for testing.

Step 1: Generate AES-256 Key and IV
Use OpenSSL to generate a 256-bit key and a 128-bit IV.

bash
Copy code
# Generate a 32-byte (256-bit) key
openssl rand -out key.bin 32

# Generate a 16-byte (128-bit) IV
openssl rand -out iv.bin 16
Step 2: Encrypt a File Using OpenSSL (AES-256-CBC)
You can encrypt a file (e.g., plaintext.txt) using the key and IV you generated. This creates an encrypted output file, encrypted_data.bin.

bash
Copy code
openssl enc -aes-256-cbc -in plaintext.txt -out encrypted_data.bin -K $(xxd -p -c 32 key.bin) -iv $(xxd -p -c 16 iv.bin)
plaintext.txt: The file you want to encrypt.
encrypted_data.bin: The encrypted output file.
Step 3: Verify Encryption
You can view the contents of the encrypted file with:

bash
Copy code
xxd encrypted_data.bin
Building the Project with CMake
Step 1: Clone the Repository
If you haven't done so already, clone the project repository:

bash
Copy code
git clone <your-repo-url>
cd DataExtractor
Step 2: Configure the Project with CMake
Create a build directory and configure the project using CMake.

bash
Copy code
mkdir build
cd build
cmake ..
Step 3: Build the Project
Run the following command inside the build directory to compile the project:

bash
Copy code
cmake --build .
This will generate an executable named DataExtractor in the build directory.

Running the Program
Once the project is built, navigate to the build directory and run the executable:

bash
Copy code
./DataExtractor
You will be presented with the following menu options:

vbnet
Copy code
Select an option:
1. Decrypt "encrypted_data.bin" with "key.bin"
2. Obfuscate "key.bin" to "obfuscated_key.bin"
3. De-obfuscate "obfuscated_key.bin" and decrypt "encrypted_data.bin"
Option 1: Decrypt encrypted_data.bin Using key.bin
This option decrypts the encrypted data using the original key (key.bin) and the IV (iv.bin).

Make sure that key.bin, iv.bin, and encrypted_data.bin are in the same directory as the executable.
Select option 1 and the program will decrypt the data and display the decrypted content.
Option 2: Obfuscate key.bin to obfuscated_key.bin
This option obfuscates the key (key.bin) using a simple XOR operation and saves the result to obfuscated_key.bin.

Make sure that key.bin is in the same directory as the executable.
Select option 2. The program will create an obfuscated version of the key in obfuscated_key.bin.
Option 3: De-obfuscate obfuscated_key.bin and Decrypt encrypted_data.bin
This option de-obfuscates the key (obfuscated_key.bin), then uses the recovered key to decrypt the encrypted data (encrypted_data.bin).

Ensure that obfuscated_key.bin, iv.bin, and encrypted_data.bin are in the same directory as the executable.
Select option 3 to de-obfuscate the key and decrypt the data.
Example Workflow
Step 1: Obfuscate the Key
Place key.bin in the directory.
Run the program and choose option 2 to obfuscate the key.
The obfuscated key will be saved as obfuscated_key.bin.
Step 2: Decrypt Using De-obfuscated Key
Place obfuscated_key.bin, iv.bin, and encrypted_data.bin in the directory.
Run the program and choose option 3 to de-obfuscate the key and decrypt the data.
Project Structure
python
Copy code
DataExtractor/
│
├── CMakeLists.txt       # CMake configuration file
├── README.md            # This file
├── main.cpp             # Main program logic
├── build/               # Directory for compiled output
├── key.bin              # (Optional) AES key used for encryption (generated)
├── iv.bin               # (Optional) Initialization vector used for encryption (generated)
├── encrypted_data.bin   # (Optional) Encrypted data file (generated)
├── obfuscated_key.bin   # (Optional) Obfuscated key file (generated)
Troubleshooting
Ensure OpenSSL is properly installed and linked. If you encounter OpenSSL-related issues, verify its installation with:

bash
Copy code
brew info openssl
If the program cannot find key.bin, iv.bin, or encrypted_data.bin, make sure these files are in the same directory as the executable.