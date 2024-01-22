#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plain[100], cipher[100];
    int key, i, length;

    printf("\nEnter the plain text: ");
    fgets(plain, sizeof(plain), stdin);

    // Remove newline character from the input
    if (plain[strlen(plain) - 1] == '\n')
        plain[strlen(plain) - 1] = '\0';

    printf("\nEnter the key value: ");
    scanf("%d", &key);

    printf("\nPLAIN TEXT: %s\n", plain);
    printf("\nENCRYPTED TEXT: ");

    for (i = 0, length = strlen(plain); i < length; i++) {
        cipher[i] = plain[i] + key;

        if (isupper(plain[i]) && (cipher[i] > 'Z'))
            cipher[i] = cipher[i] - 26;

        if (islower(plain[i]) && (cipher[i] > 'z'))
            cipher[i] = cipher[i] - 26;

        printf("%c", cipher[i]);
    }

    printf("\nAFTER DECRYPTION: ");
    
    for (i = 0; i < length; i++) {
        plain[i] = cipher[i] - key;

        if (isupper(cipher[i]) && (plain[i] < 'A'))
            plain[i] = plain[i] + 26;

        if (islower(cipher[i]) && (plain[i] < 'a'))
            plain[i] = plain[i] + 26;

        printf("%c", plain[i]);
    }

    printf("\n");
    return 0;
}
