#include <iostream>
#include <fstream>
#include <vector>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

// Function to simulate reading binary file (for key, IV, and data)
std::vector<unsigned char> readBinaryFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file: " << filename << std::endl;
        exit(1);
    }
    return std::vector<unsigned char>(std::istreambuf_iterator<char>(file), {});
}

// Function to write binary file
void writeBinaryFile(const std::string& filename, const std::vector<unsigned char>& data) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file: " << filename << std::endl;
        exit(1);
    }
    file.write(reinterpret_cast<const char*>(data.data()), data.size());
}

// Function to reverse-engineer (de-obfuscate) the encryption key
std::vector<unsigned char> deObfuscateKey(const std::vector<unsigned char>& obfuscatedKey, unsigned char obfuscationByte) {
    std::vector<unsigned char> key = obfuscatedKey;
    for (auto &byte : key) {
        byte ^= obfuscationByte; // XOR again to get the original key
    }
    return key;
}

// Function to obfuscate the key
std::vector<unsigned char> obfuscateKey(const std::vector<unsigned char>& key, unsigned char obfuscationByte) {
    std::vector<unsigned char> obfuscatedKey = key;
    for (auto &byte : obfuscatedKey) {
        byte ^= obfuscationByte; // XOR to obfuscate
    }
    return obfuscatedKey;
}

// Function to decrypt data using AES-256-CBC
std::vector<unsigned char> decryptData(const std::vector<unsigned char>& encryptedData,
                                       const std::vector<unsigned char>& key,
                                       const std::vector<unsigned char>& iv) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    std::vector<unsigned char> decryptedData(encryptedData.size());

    int len;
    int decryptedLen = 0;

    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, key.data(), iv.data());
    EVP_DecryptUpdate(ctx, decryptedData.data(), &len, encryptedData.data(), encryptedData.size());
    decryptedLen = len;
    EVP_DecryptFinal_ex(ctx, decryptedData.data() + len, &len);
    decryptedLen += len;

    EVP_CIPHER_CTX_free(ctx);
    decryptedData.resize(decryptedLen); // Resize to the actual size of decrypted data

    return decryptedData;
}

void printMenu() {
    std::cout << "\n";
    std::cout << "Select an option:\n";
    std::cout << "1. Decrypt \"encrypted_data.bin\" with \"key.bin\"\n";
    std::cout << "2. Obfuscate \"key.bin\" to \"obfuscated_key.bin\"\n";
    std::cout << "3. De-obfuscate \"obfuscated_key.bin\" and decrypt \"encrypted_data.bin\"\n";
    std::cout << " ---------------------------\n";
    std::cout << "Your option: ";
}

int main() {
    const unsigned char obfuscationByte = 0x55; // XOR byte for obfuscation
    int choice;
    
    printMenu();
    std::cin >> choice;

    switch (choice) {
        case 1: {
            // Option 1: Decrypt "encrypted_data.bin" with "key.bin"
            std::vector<unsigned char> key = readBinaryFile("key.bin");
            std::vector<unsigned char> iv = readBinaryFile("iv.bin");
            std::vector<unsigned char> encryptedData = readBinaryFile("encrypted_data.bin");

            std::vector<unsigned char> decryptedData = decryptData(encryptedData, key, iv);

            std::cout << "Decrypted Data: ";
            for (unsigned char c : decryptedData) {
                std::cout << c;
            }
            std::cout << std::endl;
            break;
        }

        case 2: {
            // Option 2: Obfuscate "key.bin" to "obfuscated_key.bin"
            std::vector<unsigned char> key = readBinaryFile("key.bin");
            std::vector<unsigned char> obfuscatedKey = obfuscateKey(key, obfuscationByte);

            writeBinaryFile("obfuscated_key.bin", obfuscatedKey);
            std::cout << "Key obfuscated and saved to \"obfuscated_key.bin\"" << std::endl;
            break;
        }

        case 3: {
            // Option 3: De-obfuscate "obfuscated_key.bin" and decrypt "encrypted_data.bin"
            std::vector<unsigned char> obfuscatedKey = readBinaryFile("obfuscated_key.bin");
            std::vector<unsigned char> iv = readBinaryFile("iv.bin");
            std::vector<unsigned char> encryptedData = readBinaryFile("encrypted_data.bin");

            // De-obfuscate the key
            std::vector<unsigned char> key = deObfuscateKey(obfuscatedKey, obfuscationByte);

            // Decrypt the data using the de-obfuscated key
            std::vector<unsigned char> decryptedData = decryptData(encryptedData, key, iv);

            std::cout << "\nDecrypted Data:\n";
            for (unsigned char c : decryptedData) {
                std::cout << c;
            }
            std::cout << std::endl;
            break;
        }

        default:
            std::cout << "Invalid option. Please run the program again." << std::endl;
            break;
    }

    return 0;
}
