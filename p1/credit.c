#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // variable declarations and initializations
    char num[25];
    int check = 0;
    char cardType[11] = "INVALID";
    char visa[5] = "VISA";
    char masterCard[11] = "MASTERCARD";
    char amex[5] = "AMEX";
    char invalid[8] = "INVALID";
    int numTimes2[20];
    int sum;
    int iterator;
    int numNums = 0;
    int arraySize = sizeof(num) / sizeof(num[0]);
    for (int i = 0; i < arraySize; i++) {
        num[i] = 'a';
    }

    // user input number
    do {
        printf("Number: ");
        if (fgets(num , 25, stdin) != NULL) {
            for (int i = 0; i < arraySize; i++) {
                if (num[i] != '\0' && num[i] != '\n') {
                    numNums++;
                }
                else {
                    check = 1;
                }
                if (!isdigit(num[i]) && num[i] != '\0' && num[i] != '\n') {
                    check = 0;
                }
            }
        }
    } while (check != 1);

    // determining card type
    if ((numNums == 15) && num[0] == '3') {
        if (num[1] == '4' || num[1] == '7') {
            strcpy(cardType, amex);
        }
    }
    if ((numNums == 16) && num[0] == '5') {
        if (num[1] == '1' || num[1] == '2' || num[1] == '3' || num[1] == '4' || num[1] == '5') {
            strcpy(cardType, masterCard);
        }
    }
    if ((numNums == 13) || (numNums == 16)) {
        if (num[0] == '4') {
            strcpy(cardType, visa);
        }
    }

    // checksum operations
    for (int i = 0; i < numNums; i++) {
        numTimes2[i] = (num[i] - '0') * 2;
    }

    for (int i = 0; i < numNums; i++) {
        if ((numNums % 2) == 0) {
            if ((i % 2) == 0) {
                sum = sum + (numTimes2[i] % 10) + (numTimes2[i] / 10);
            }
            else {
                sum = sum + (num[i] - '0');
            }
        }
        if ((numNums % 2) == 1) {
            if ((i % 2) == 1) {
                sum = sum + (numTimes2[i] % 10) + (numTimes2[i] / 10);
            }
            else {
                sum = sum + (num[i] - '0');
            }
        }
    }
    if ((sum%10) != 0) {
        strcpy(cardType, invalid);
    }

    // end result
    printf("%s\n", cardType); 
    return 0;
}
