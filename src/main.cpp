
#include <iostream>
#include <fstream>
#include <vector>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/err.h>

// Function to read a binary file into a vector of unsigned char
std::vector<unsigned char> readBinaryFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);  // Open file in binary mode
    if (!file) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    // Read the file content into a vector
    return std::vector<unsigned char>(std::istreambuf_iterator<char>(file), {});
}

// Function to decrypt data using AES-256-CBC
std::vector<unsigned char> aes256Decrypt(const std::vector<unsigned char>& encryptedData, 
                                         const std::vector<unsigned char>& key, 
                                         const std::vector<unsigned char>& iv) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        throw std::runtime_error("Failed to create EVP_CIPHER_CTX");
    }

    int outlen, tmplen;
    std::vector<unsigned char> decryptedData(encryptedData.size() + AES_BLOCK_SIZE);

    // Initialize decryption
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key.data(), iv.data())) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("EVP_DecryptInit_ex failed");
    }

    // Provide the data to decrypt
    if (1 != EVP_DecryptUpdate(ctx, decryptedData.data(), &outlen, encryptedData.data(), encryptedData.size())) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("EVP_DecryptUpdate failed");
    }

    // Finalize decryption
    if (1 != EVP_DecryptFinal_ex(ctx, decryptedData.data() + outlen, &tmplen)) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("EVP_DecryptFinal_ex failed");
    }

    outlen += tmplen;
    decryptedData.resize(outlen);

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return decryptedData;
}

int main() {
    try {
        // Read the key, IV, and encrypted data from binary files
        std::vector<unsigned char> key = readBinaryFile("key.bin");
        std::vector<unsigned char> iv = readBinaryFile("iv.bin");
        std::vector<unsigned char> encryptedData = readBinaryFile("encrypted_data.bin");

        // Ensure the key and IV sizes are correct
        if (key.size() != 32) {
            throw std::runtime_error("Invalid key size. AES-256 requires a 32-byte key.");
        }
        if (iv.size() != 16) {
            throw std::runtime_error("Invalid IV size. AES-256-CBC requires a 16-byte IV.");
        }

        // Decrypt the data
        std::vector<unsigned char> decryptedData = aes256Decrypt(encryptedData, key, iv);
        
        std::cout << "Before.." << std::endl;

        // Output decrypted data (as a string or write it to a file)
        std::cout << "Decrypted data: " << std::string(decryptedData.begin(), decryptedData.end()) << std::endl;

        std::cout << "After.." << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
