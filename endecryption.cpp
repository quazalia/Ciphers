#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string encryptCaesar(string message, int shift) {
    string encrypted = "";
    for (char c : message) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            encrypted += static_cast<char>((c - base + shift) % 26 + base);
        } else {
            encrypted += c;
        }
    }
    return encrypted;
}

string decryptCaesar(string message, int shift) {
    return encryptCaesar(message, 26 - shift);
}

string encryptVigenere(const string& message, const string& key) {
    string encrypted = "";
    int keyLength = key.length();
    for (int i = 0, j = 0; i < message.length();i++) {
        char c = message[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            encrypted += static_cast<char>((c + key[j % keyLength] - 2 * base) % 26 + base);
            ++j;
        } else {
            encrypted += c;
        }
    }
    return encrypted;
}

// Function to decrypt text using Vigenère cipher
string decryptVigenere(const string& message, const string& key) {
    string decrypted = "";
    int keyLength = key.length();
    for (int i = 0, j = 0; i < message.length(); ++i) {
        char c = message[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            decrypted += static_cast<char>((c - key[j % keyLength] + 26) % 26 + base);
            ++j;
        } else {
            decrypted += c;
        }
    }
    return decrypted;
}
int main() {
    string message;
    int shift, choice;
    char operation;
    string vkey;
    string result;
    
    cout << "Enter the message: ";
    getline(cin, message);

    cout << "Select encryption&decryption method:\n";
    cout << "1. Caesar Cipher\n";
    cout << "2. Vigenere Cipher\n";
    cin >> choice;
    
    switch (choice) {
    case 1:
        cout << "Enter the shift value for Caesar cipher: ";
        cin >> shift;
        cout << "Enter 'E' for encryption or 'D' for decryption: ";
        cin >> operation;
        operation = toupper(operation);
        if (operation == 'E') {
            result = encryptCaesar(message, shift);
            cout << "Encrypted message: " << result << endl;
        } else if (operation == 'D') {
            result = decryptCaesar(message, shift);
            cout << "Decrypted message: " << result << endl;
        }else {
        cout << "Invalid operation selected!" << endl;
        }
        break;
    case 2:
        cout << "Enter the key for Vigenere Cipher: ";
        cin >> vkey;
        cout << "Enter 'E' for encryption or 'D' for decryption: ";
        cin >> operation;
        operation = toupper(operation);
        if (operation == 'E') {
            result = encryptVigenere(message, vkey);
            cout << "Encrypted message: " << result << endl;
        } else if (operation == 'D') {
            result = decryptVigenere(message, vkey);
            cout << "Decrypted message: " << result << endl;
        }else {
        cout << "Invalid operation selected!" << endl;
        }
        break;
    default:
        cout << "Invalid choice.\n";
    }
    
    return 0;
}
