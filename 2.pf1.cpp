#include <bits/stdc++.h>

using namespace std;

// Function to generate the Playfair matrix
void generateMatrix(string key, char matrix[5][5]) {
    bool used[26] = { false };
    int i = 0, j = 0;
    for (char c : key) {
        if (used[toupper(c) - 'A']) continue; // skip repeated letters
        used[toupper(c) - 'A'] = true;
        matrix[i][j] = toupper(c);
        if (++j == 5) {
            j = 0;
            i++;
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue; // skip 'J'
        if (used[c - 'A']) continue; // skip letters already used in key
        matrix[i][j] = c;
        if (++j == 5) {
            j = 0;
            i++;
        }
    }
}

// Function to encode a message using Playfair cipher
string encode(string message, char matrix[5][5]) {
    // remove spaces and convert to uppercase
   // message.erase(remove_if(message.begin(), message.end(), ::isspace), message.end());
 //   transform(message.begin(), message.end(), message.begin(), ::toupper);

    // add padding if necessary
    if (message.length() % 2 != 0) message += 'X';

    // encode pairs of letters
    string result;
    for (int i = 0; i < message.length(); i += 2) {
        char a = message[i], b = message[i+1];
        int rowA, colA, rowB, colB;
        // find the positions of the two letters in the matrix
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                if (matrix[r][c] == a) {
                    rowA = r;
                    colA = c;
                } else if (matrix[r][c] == b) {
                    rowB = r;
                    colB = c;
                }
            }
        }
        // encode the pair of letters
        if (rowA == rowB) {
            // same row, shift columns
            result += matrix[rowA][(colA+1)%5];
            result += matrix[rowB][(colB+1)%5];
        } else if (colA == colB) {
            // same column, shift rows
            result += matrix[(rowA+1)%5][colA];
            result += matrix[(rowB+1)%5][colB];
        } else {
            // form a rectangle and swap columns
            result += matrix[rowA][colB];
            result += matrix[rowB][colA];
        }
    }
    return result;
}

int main() {
    char matrix[5][5];
//string key = "EXAMPLEKEY";
  string key;
  cin>>key;
    generateMatrix(key, matrix);

    //string message = "HELLO WORLD";
    string message;
    cin>>message;
    string encoded = encode(message, matrix);

    cout << "Original message: " << message << endl;
    cout << "Encoded message: " << encoded << endl;

    return 0;
}
