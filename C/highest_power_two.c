/*
 * Given a number n, find the highest power of 2 that is smaller than or equal to n.
 */

/*
 * Application:
 * Some people are standing in a queue. A selection process follows a rule where people standing on even positions are selected
 * Of the selected people a queue is formed and again out of these only people on even position are selected.
 * This continues until we are left with one person. Find out the position of that person in the original queue.
 * Print the position(original queue) of that person who is left.
 */
#include <stdio.h>

int main()
{
    unsigned int num  = 10;
    unsigned int power_two = 1;
    
    while(num > power_two) {
        power_two = power_two << 1;
    }
    printf("\nHighest power of two less than given num is %d\n",power_two >> 1);
    return 0;
}
