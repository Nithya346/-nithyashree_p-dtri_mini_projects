#include <stdio.h>
#include <string.h>

int main() {
    char word[] = "apple";
    char guess[10];
    int attempts = 6;
    int i, len, found;
    len = strlen(word);
    printf("You have 6 attempts to guess the word.\n");

    while (attempts > 0) {
        printf("\nEnter your guess: ");
        scanf("%s", guess);

        if (strcmp(guess, word) == 0) {
            printf("\nYou've guessed the word correctly: %s\n", word);
            break;
        } else {
            found = 0;
            for (i = 0; i < len; i++) {
                if (word[i] == guess[i]) {
                    printf("%c", guess[i]);
                } else {
                    printf("-");
                }
            }
            printf("\nIncorrect guess, try again.\n");
            attempts--;
            printf("You have %d attempts left.\n", attempts);
        }
    }
    if (attempts == 0) {
        printf("\nYou've run out of attempts. The word was: %s\n", word);
    }

    return 0;
}
