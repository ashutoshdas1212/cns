#include <iostream>
using namespace std;

// This function receives text and shift and returns the encrypted text
string encrypt(string text, int s)
{
    string result = "";

    // traverse text
    for (int i = 0; i < text.length(); i++) {
        // apply transformation to each character
        // Encrypt Uppercase letters
        if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);
        // Encrypt Lowercase letters
        else
            result += char(int(text[i] + s - 97) % 26 + 97);
    }

    // Return the resulting string
    return result;
}

// This function receives encrypted text and shift and returns the decrypted text
string decrypt(string encryptedText, int s)
{
    string result = "";

    // traverse encrypted text
    for (int i = 0; i < encryptedText.length(); i++) {
        // apply transformation to each character
        // Decrypt Uppercase letters
        if (isupper(encryptedText[i]))
            result += char(int(encryptedText[i] - s - 65 + 26) % 26 + 65);
        // Decrypt Lowercase letters
        else
            result += char(int(encryptedText[i] - s - 97 + 26) % 26 + 97);
    }

    // Return the resulting string
    return result;
}

int main()
{
    string text;
    cout << "Enter the text: ";
    cin >> text;

    int s;
    cout << "Enter the shift value: ";
    cin >> s;

    cout << "Text: " << text;
    cout << "\nShift: " << s;

    string encryptedText = encrypt(text, s);
    cout << "\nEncrypted Cipher: " << encryptedText;

    string decryptedText = decrypt(encryptedText, s);
    cout << "\nDecrypted Text: " << decryptedText;

    return 0;
}
