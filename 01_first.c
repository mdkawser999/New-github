#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    srand(time(0));

    int randomNumber = (rand() % 100) + 1;
    int not_of_guesses = 0;
    int guessed;

    do
    {
        printf("Guess the number");
        scanf("%d", &guessed);
        if (guessed > randomNumber)
        {
            printf("Lower number please!\n");
        }
        else if (randomNumber > guessed)
        {
            printf("Higher number please!\n");
        }
        else
        {
            printf("Nice!!\n");
        }

        not_of_guesses++;
    } while (guessed != randomNumber);

    printf("the number of guess is %d\n", not_of_guesses);

    printf("Random Number: %d\n", randomNumber);

    return 0;
}