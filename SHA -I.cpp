#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void printHash(unsigned char hash[]) {
    for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main() {
    char input[100];

    SHA_CTX shaContext;
    SHA1_Init(&shaContext);

    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove the newline character from input

    SHA1_Update(&shaContext, input, strlen(input));

    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1_Final(hash, &shaContext);

    printf("SHA1(\"%s\") = ", input);
    printHash(hash);

    return 0;
}
