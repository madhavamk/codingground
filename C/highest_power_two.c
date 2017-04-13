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
