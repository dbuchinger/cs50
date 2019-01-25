#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>

int main(int argc, char const *argv[])
{   
    // var declarations and initializations
    char hash[15];
    //char hashGuess[15];
    char *hashGuess;
    char passwordGuess[20];
    char salt[3];
    int digit = 0;
    for (int i = 0; i < strlen(hash); i++) {
        hash[i] = '\0';
    }
    for (int i = 0; i < strlen(hashGuess); i++) {
        hashGuess[i] = '\0';
    }
    for (int i = 0; i < strlen(passwordGuess); i++) {
        passwordGuess[i] = '\0';
    }
    for (int i = 0; i < strlen(salt); i++) {
        salt[i] = '\0';
    }
    if (argc != 2) {
        printf("Usage: ./crack hash");
        exit(0);
    }
    else {
        strcpy(hash, argv[1]);
    }
    salt[0] = hash[0];
    salt[1] = hash[1];

    while (strcmp(hashGuess, hash) != 0) {
        if (passwordGuess[digit] == '\0') {
            passwordGuess[digit] == 'a';
        }
        else {
            passwordGuess[digit]++;
        }
        for (int i = (strlen(passwordGuess) - 1); i >= 0; i--) {
            if (passwordGuess[i] == ('z' + 1)) {
                passwordGuess[i] == 'A';
            }
            else if (passwordGuess[i] == ('Z' + 1)) {
                passwordGuess[i] == 'a';
                passwordGuess[i-1]++;
                if (i == digit) {
                    digit++;
                }
            }
        }
        hashGuess = crypt(passwordGuess, salt);
    }

    printf("%s\n", passwordGuess);
    
    return 0;
}
