#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void slotMacheine(int coins)
{
    char symbols[] = "X7#!?§$&£@=Å";
    int num_symbols = 12;

    // Generate one random symbol for each slot
    char slot1 = symbols[rand() % num_symbols];
    char slot2 = symbols[rand() % num_symbols];
    char slot3 = symbols[rand() % num_symbols];

    // Print the slot values
    printf("*_*_*_*_*_ENARMMADE BANDITEN*_*_*_*_\n");
    printf("|_|_|_|_|_| [%c] [%c] [%c] |_|_|_|_|_|\n", slot1, slot2, slot3);
    printf("*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_\n");
}

int main()
{
    srand((unsigned int)time(NULL)); // Seed random number generator once

    slotMacheine(0);

    return 0;
}

/***************************
XX = x1.5       XXX = x3
77 = x1.5       777 = x3
## = x1.5       ### = x3
!! = x3         !!! = x6
?? = x3         ??? = x6
§§ = x4         §§§ = x8
$$ = x2.5       $$$ = x4
&& = x2.5       &&& = x4
££ = x2.5       £££ = x4
@@ = x2.5       @@@ = x4
== = x2.5       === = x4
ÅÅ = x5         ÅÅÅ = 10
****************************/