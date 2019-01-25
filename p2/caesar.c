#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    // var declarations and initializations
    char message[100];
    char decoded[100];
    for (int i = 0; i < 100; i++) {
        message[i] = '\0';
    }
    for (int i = 0; i < 100; i++) {
        decoded[i] = '\0';
    }
    int key;
    if (argc == 2) {
        key = atoi(argv[1]);
    } else {
        printf("Usage: ./caesar k\n");
        exit(0);
    }

    // getting user input
    printf("plaintext: ");
    if (fgets(message, 100, stdin) != NULL) {
        // adding the key
        for (int i = 0; i < (strlen(message) - 1); i++) {
            if (isalpha(message[i])) {
                decoded[i] = message[i] + key;
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
