#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    long numBlocks;
    char block = '#';
    int c;

    // getting and checking user input
    do {
        printf("Height: ");
        scanf("%d", &numBlocks);
        while ((c = getchar()) != EOF && c != '\n')
        ;
    } while ((numBlocks < 0) || (numBlocks > 23));
    
    // printing the pyramids
    for (int i = 0; i < numBlocks; i++) {
        for (int j = 0; j < (numBlocks-i); j++) {
            printf(" ");
        }
        for (int j = 0; j < (i + 1); j++) {
            printf("%c", block);
        }
        printf("  ");
        for (int j = 0; j < (i + 1); j++) {
            printf("%c", block);
        }
        printf("\n");
    }
    return 0;
}
