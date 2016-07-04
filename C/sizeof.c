#include <stdio.h>

struct info {
    int data;
    char name;
    float id;
};
int main()
{
    int i[5],size,b,c;
    struct info a;
    b = (char*)(&i+1) - (char*)&i;
    c = (char*)(i+1) - (char*)i;
    size = (char*)(&a+1) - (char*)&a;
    printf("b %d,c %d, size %d,strct %d\n",b,c,b/c,size);
    
}