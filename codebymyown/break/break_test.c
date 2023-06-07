#include <stdio.h>

int add(int a,int b)
{
    return a+b;
}

int main()
{
    int a=10;
    int b=100;
    int c=0;
    c=add(a,b);
    printf("C=%d\r\n",c);
    return 0;
}