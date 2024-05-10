/*
 *  Program to evaluate face values.
 *  Released under the Vegas Public License.
 *  (c)2014 The College Blackjack Team.
*/
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char card_name[3];
    int count = 0;
    while (1) {
        puts("Enter the card_name: ");
        scanf("%2s", card_name);

        if (card_name[0] == 'X') {
            break;
        };

        int val = 0;
        switch(card_name[0]) {
            case 'A':
                val = 11;
                break;
            case 'K':
            case 'Q':
            case 'J':
                val = 10;
                break;
            default:
                val = atoi(card_name);

                if (val < 1 || val > 10) {
                    puts("Wrong face value. Try again");
                    continue;
                }    
        }
        if (val >= 3 && val <= 6) {
            count++;
        } else if (val == 10) {
            count--;
        }
        printf("Current count: %i\n", count);
    }

    return 0;
}