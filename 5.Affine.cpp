#include <stdio.h>
#include <ctype.h>

// Function to check if a number is coprime with 26
int isCoprime(int a) {
    return (a % 2 != 0) && (a % 13 != 0);
}

// Function to find modular multiplicative inverse of a number
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++)
        if (((a % m) * (x % m)) % m == 1)
            return x;
    return -1; // Inverse does not exist
}

// Function to encrypt a character using Affine Cipher
char encrypt(char ch, int a, int b) {
    if (isalpha(ch)) {
        char base = islower(ch) ? 'a' : 'A';
        return (char)(((a * (ch - base) + b) % 26) + base);
    }
    return ch;
}

// Function to decrypt a character using Affine Cipher
char decrypt(char ch, int a, int b) {
    if (isalpha(ch)) {
        char base = islower(ch) ? 'a' : 'A';
        int a_inv = modInverse(a, 26);
        return (char)((a_inv * (ch - base - b + 26) % 26) + base);
    }
    return ch;
}

// Function to perform Affine Cipher encryption/decryption on a message
void affineCipher(char message[], int a, int b, int mode) {
    for (int i = 0; message[i] != '\0'; i++) {
        if (mode == 0) // Encryption
            message[i] = encrypt(message[i], a, b);
        else if (mode == 1) // Decryption
            message[i] = decrypt(message[i], a, b);
    }
}

int main() {
    char message[100];
    int a, b;

    printf("Enter the message to encrypt/decrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the value of 'a' (must be coprime with 26): ");
    scanf("%d", &a);

    if (!isCoprime(a)) {
        printf("Invalid value for 'a'. Exiting...\n");
        return 1;
    }

    printf("Enter the value of 'b': ");
    scanf("%d", &b);

    // Encryption
    printf("\nEncrypted Message: ");
    affineCipher(message, a, b, 0);
    printf("%s", message);

    // Decryption
    printf("\nDecrypted Message: ");
    affineCipher(message, a, b, 1);
    printf("%s", message);

    return 0;
}
