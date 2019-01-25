#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    double money;
    int count = 0;
    int pennies = 0, nickels = 0, dimes = 0, quarters = 0, _1dollars = 0, _5dollars = 0,
        _10dollars = 0, _20dollars = 0, _50dollars = 0, _100dollars = 0;
    int usedPennies = 0, usedNickels = 0, usedDimes = 0, usedQuarters = 0, used1dollars = 0,
        used5dollars = 0, used10dollars = 0, used20dollars = 0, used50dollars = 0,
        used100dollars = 0;
    int iterator;
    do {
        printf("Change owed: ");
        scanf("%lf", &money);
        while ((iterator = getchar()) != EOF && iterator != '\n');
    } while (money < 0);

    printf("\n", money);

    while (money >= 100) {
        money = money - 100;
        _100dollars++;
        used100dollars = 1;
    }
    while (money >= 50) {
        money = money - 50;
        _50dollars++;
        used50dollars = 1;
    }
    while (money >= 20) {
        money = money - 20;
        _20dollars++;
        used20dollars = 1;
    }
    while (money >= 10) {
        money = money - 10;
        _10dollars++;
        used10dollars = 1;
    }
    while (money >= 5) {
        money = money - 5;
        _5dollars++;
        used5dollars = 1;
    }
    while (money >= 1) {
        money = money - 1;
        _1dollars++;
        used1dollars = 1;
    }
    while (money >= 0.25) {
        money = money - 0.25;
        quarters++;
        usedQuarters = 1;
    }
    while (money >= 0.10) {
        money = money - 0.10;
        dimes++;
        usedDimes = 1;
    }
    while (money >= 0.05) {
        money = money - 0.05;
        nickels++;
        usedNickels = 1;
    }
    while (money >= 0.009) {
        money = money - 0.01;
        pennies++;
        usedPennies = 1;
    }
    count = pennies + nickels + dimes + quarters + _1dollars + _5dollars + _10dollars
        + _20dollars + _50dollars + _100dollars;
    printf("Change given\n");
    printf("____________\n");
    if (used100dollars == 1) {
        printf("%d 100 dollar bills\n", _100dollars);
    }
    if (used50dollars == 1) {
        printf("%d 50 dollar bills\n", _50dollars);
    }
    if (used20dollars == 1) {
        printf("%d 20 dollar bills\n", _20dollars);
    }
    if (used10dollars == 1) {
        printf("%d 10 dollar bills\n", _10dollars);
    }
    if (used5dollars == 1) {
        printf("%d 5 dollar bills\n", _5dollars);
    }
    if (used1dollars == 1) {
        printf("%d 1 dollar bills\n", _1dollars);
    }
    if (usedQuarters == 1) {
        printf("%d quarters\n", quarters);
    }
    if (usedDimes == 1) {
        printf("%d dimes\n", dimes);
    }
    if (usedNickels == 1) {
        printf("%d nickels\n", nickels);
    }
    if (usedPennies == 1) {
        printf("%d pennies\n", pennies);
    }
    printf("\nTotal change units used: %d", count);
    return 0;
}
