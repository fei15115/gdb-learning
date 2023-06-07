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
    char str[200];
    c=add(a,b);
    sprintf(str,"C=%d\r\n",c);
    return 0;
}