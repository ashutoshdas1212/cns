#include <iostream>
#include <string>

std::string vigenereEncrypt(const std::string& plaintext, const std::string& key) {
    std::string ciphertext;
    int keyIndex = 0;

    for (char c : plaintext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char encryptedChar = (c - base + (toupper(key[keyIndex]) - 'A')) % 26 + base;
            ciphertext += encryptedChar;

            keyIndex = (keyIndex + 1) % key.length();
        } else {
            ciphertext += c;
        }
    }

    return ciphertext;
}

std::string vigenereDecrypt(const std::string& ciphertext, const std::string& key) {
    std::string plaintext;
    int keyIndex = 0;

    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char decryptedChar = (c - base - (toupper(key[keyIndex]) - 'A') + 26) % 26 + base;
            plaintext += decryptedChar;

            keyIndex = (keyIndex + 1) % key.length();
        } else {
            plaintext += c;
        }
    }

    return plaintext;
}

int main() {
    std::string plaintext;
    std::string key;

    std::cout << "Enter the plaintext: ";
    std::getline(std::cin, plaintext);

    std::cout << "Enter the key: ";
    std::getline(std::cin, key);

    std::string encrypted = vigenereEncrypt(plaintext, key);
    std::cout << "Encrypted text: " << encrypted << std::endl;

    std::string decrypted = vigenereDecrypt(encrypted, key);
    std::cout << "Decrypted text: " << decrypted << std::endl;

    return 0;
}
