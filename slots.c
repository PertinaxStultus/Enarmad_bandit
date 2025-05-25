#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void slotMacheine(int *coins)
{


    char symbols[] = "X7#!?S$&+@=Z";
    int num_symbols = 12;

    // Generate one random symbol for each slot
    char slot1 = symbols[rand() % num_symbols];
    char slot2 = symbols[rand() % num_symbols];
    char slot3 = symbols[rand() % num_symbols];

    // Check for winning combinations
    if (slot1 == slot2 && slot2 == slot3)
    {
        // All three slots match
        switch (slot1)
        {
        case 'X': *coins += 5; break;// +5
        case '#': *coins += 5; break;// +5
        case '$': *coins += 5; break;// +5
        case '&': *coins += 10; break;// +10
        case '+': *coins += 10; break;// +10
        case '@': *coins += 10; break;// +10
        case '=': *coins += 15; break;// +15
        case '7': *coins += 15; break;// +15
        case '!': *coins += 20; break;// +20
        case '?': *coins += 25; break;// +25
        case 'S': *coins += 50; break;// +50
        case 'Z': *coins += 100;  break; // +100
        }
    }
    else if (slot1 == slot2 || slot1 == slot3 || slot2 == slot3)
    {
        // Two slots match
        switch (slot1)
        {
        case 'X': *coins += 1; break;// +1
        case '#': *coins += 1; break;// +1
        case '$': *coins += 1; break;// +1
        case '&': *coins += 1; break;// +1
        case '+': *coins += 1; break;// +1
        case '@': *coins += 2; break;// +2
        case '=': *coins += 2; break;// +2
        case '7': *coins += 3; break;// +6
        case '!': *coins += 6; break;// +6
        case '?': *coins += 6; break;// +6
        case 'S': *coins += 6; break;// +6
        case 'Z': *coins += 10;  break; // +10
        }
    }
    else
    {
        // No match, no win
        printf("No win this time!\n");

    }

    // Print the slot values
    printf("*_*_*_*_*_ENARMMADE BANDITEN*_*_*_*_\n");
    printf("|_|_|_|_|_| [%c] [%c] [%c] |_|_|_|_|_|\n", slot1, slot2, slot3);
    printf("*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n");
}

int main()
{
    int coins = 10; // Starting coins
    while (coins > 0)
    {
        srand((unsigned int)time(NULL)); // Seed random number generator once

        printf("You have %d coins. Press Enter to play or type 'E' to quit.\n", coins);
        char input[10];
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'e' || input[0] == 'E') {
            break; // Exit the game
        }
        if (coins < 1) {
            printf("You don't have enough coins to play!\n");
            continue; // Skip to next iteration if no coins
        }
        coins--; // Deduct one coin for playing
        slotMacheine(&coins);
    }
    // displays final winnings
    printf("Game over! You finished with %d coins.\n", coins);
    return 0;
}

/**********************************
XX = +1        XXX = +5
## = +1        ### = +5
$$ = +1        $$$ = +5
&& = +1        &&& = +10
++ = +1        +++ = +10
@@ = +2        @@@ = +10
== = +2        === = +15
77 = +3        777 = +15
!! = +6        !!! = +20
?? = +6        ??? = +25
SS = +6        SSS = +50
ZZ = +10       ZZZ = +100
**********************************/