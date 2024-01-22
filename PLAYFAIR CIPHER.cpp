#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MX 5

void playfair(char ch1, char ch2, char key[MX][MX]);

int main() {
    char key[MX][MX], keyminus[25], keystr[10], str[25] = {0};
    char alpa[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int i, j, k = 0, l, m = 0, n;

    // clrscr(); // Removing clrscr() function

    printf("\nEnter key:");
    gets(keystr);
    printf("\nEnter the plain text:");
    gets(str);

    n = strlen(keystr);

    // convert the characters to uppercase
    for (i = 0; i < n; i++) {
        if (keystr[i] == 'j') keystr[i] = 'i';
        else if (keystr[i] == 'J') keystr[i] = 'I';
        keystr[i] = toupper(keystr[i]);
    }

    // convert all the characters of plaintext to uppercase
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == 'j') str[i] = 'i';
        else if (str[i] == 'J') str[i] = 'I';
        str[i] = toupper(str[i]);
    }

    j = 0;
    for (i = 0; i < 26; i++) {
        for (k = 0; k < n; k++) {
            if (keystr[k] == alpa[i])
                break;
            else if (alpa[i] == 'J')
                break;
        }
        if (k == n) {
            keyminus[j] = alpa[i];
            j++;
        }
    }

    k = 0;
    for (i = 0; i < MX; i++) {
        for (j = 0; j < MX; j++) {
            if (k < n) {
                key[i][j] = keystr[k];
                k++;
            } else {
                key[i][j] = keyminus[m];
                m++;
            }
            printf("%c ", key[i][j]);
        }
        printf("\n");
    }

    printf("\n\nEntered text: %s\nCipher Text: ", str);

    for (i = 0; i < strlen(str); i++) {
        if (str[i + 1] == '\0')
            playfair(str[i], 'X', key);
        else {
            if (str[i] == str[i + 1])
                playfair(str[i], 'X', key);
            else
                playfair(str[i], str[i + 1], key);
            i++;
        }
    }

    // getch(); // Removed getch() function
    return 0;
}

void playfair(char ch1, char ch2, char key[MX][MX]) {
    int i, j, w = 0, x = 0, y = 0, z = 0;
    FILE *out;
    if ((out = fopen("cipher.txt", "a+")) == NULL) {
        printf("File Currupted.");
    }

    for (i = 0; i < MX; i++) {
        for (j = 0; j < MX; j++) {
            if (ch1 == key[i][j]) {
                w = i;
                x = j;
            } else if (ch2 == key[i][j]) {
                y = i;
                z = j;
            }
        }
    }

    if (w == y) {
        x = (x + 1) % MX;
        z = (z + 1) % MX;
        printf("%c%c", key[w][x], key[y][z]);
        fprintf(out, "%c%c", key[w][x], key[y][z]);
    } else if (x == z) {
        w = (w + 1) % MX;
        y = (y + 1) % MX;
        printf("%c%c", key[w][x], key[y][z]);
        fprintf(out, "%c%c", key[w][x], key[y][z]);
    } else {
        printf("%c%c", key[w][z], key[y][x]);
        fprintf(out, "%c%c", key[w][z], key[y][x]);
    }

    fclose(out);
}
