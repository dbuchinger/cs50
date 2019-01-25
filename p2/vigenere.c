#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    // var declarations and initializations
    char message[100];
    char decoded[100];
    char key[100];
    int iterator;
    for (int i = 0; i < 100; i++) {
        message[i] = '\0';
    }
    for (int i = 0; i < 100; i++) {
        decoded[i] = '\0';
    }
    for (int i = 0; i < 100; i++) {
        key[i] = '\0';
    }
    if (argc == 2) {
        strcpy(key, argv[1]);
        for (int i = 0; i < strlen(key); i++) {
            if (!isalpha(key[i])) {
                printf("Usage: ./vigenere k\n");
                exit(0);
            }
            else {
                key[i] = tolower(key[i]);
            }
        }            
    } else {
        printf("Usage: ./vigenere k\n");
        exit(0);
    }

    // getting user input
    printf("plaintext: ");
    if (fgets(message, 100, stdin) != NULL) {
        // adding the key
        for (int i = 0; i < (strlen(message) - 1); i++) {
            if (isalpha(message[i])) {
                decoded[i] = message[i] + (key[iterator] - 'a');
                iterator++;
                if (iterator > (strlen(key) - 1)) {
                    iterator = 0;
                }
                // checking if new char is out of bounds and bringing it back
                if (!isalpha(decoded[i])) {
                    decoded[i] = decoded[i] - 26;
                }
            }
            else {
                decoded[i] = message[i];
            }
        }
    }

    // end print
    printf("ciphertext: %s\n", decoded);
    return 0;
}