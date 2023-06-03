#include <openssl/des.h>
#include <iostream>
#include <iomanip>
#include <string>

// Function to perform DES encryption
std::string desEncrypt(const std::string& plaintext, const std::string& key) {
    DES_cblock desKey;
    DES_key_schedule keySchedule;
    DES_string_to_key(key.c_str(), &desKey);
    DES_set_key_unchecked(&desKey, &keySchedule);

    std::string ciphertext;
    size_t blocks = plaintext.length() / 8;

    for (size_t i = 0; i < blocks; i++) {
        DES_cblock inputBlock;
        DES_cblock outputBlock;

        std::memcpy(inputBlock, plaintext.c_str() + (i * 8), 8);
        DES_ecb_encrypt(&inputBlock, &outputBlock, &keySchedule, DES_ENCRYPT);

        ciphertext.append(reinterpret_cast<const char*>(&outputBlock), 8);
    }

    return ciphertext;
}

// Function to perform DES decryption
std::string desDecrypt(const std::string& ciphertext, const std::string& key) {
    DES_cblock desKey;
    DES_key_schedule keySchedule;
    DES_string_to_key(key.c_str(), &desKey);
    DES_set_key_unchecked(&desKey, &keySchedule);

    std::string plaintext;
    size_t blocks = ciphertext.length() / 8;

    for (size_t i = 0; i < blocks; i++) {
        DES_cblock inputBlock;
        DES_cblock outputBlock;

        std::memcpy(inputBlock, ciphertext.c_str() + (i * 8), 8);
        DES_ecb_encrypt(&inputBlock, &outputBlock, &keySchedule, DES_DECRYPT);

        plaintext.append(reinterpret_cast<const char*>(&outputBlock), 8);
    }

    return plaintext;
}

int main() {
    std::string plaintext;
    std::string key;

    std::cout << "Enter plaintext (64-bit block): ";
    std::getline(std::cin, plaintext);

    std::cout << "Enter key (64-bit): ";
    std::getline(std::cin, key);

    // Ensure the plaintext and key are exactly 64 bits (8 bytes)
    plaintext.resize(8, ' ');
    key.resize(8, ' ');

    std::string ciphertext = desEncrypt(plaintext, key);
    std::string decryptedText = desDecrypt(ciphertext, key);

    std::cout << "\nCiphertext (hex): ";
    for (unsigned char c : ciphertext)
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c);
    std::cout << std::dec << std::endl;

    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
}
