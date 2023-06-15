#include <stdio.h>
#include <string.h>

typedef struct test{
    unsigned char  aa;
    int bb;
    long long cc;
    short int dd;
}test;

int main(){
    test structtest[500];
    unsigned char buff[500];
    int i = 0;
    int j = 0;
    for(i =0;i<500;i++)
    {
        structtest[i].aa=34;
        structtest[i].bb=341;
        structtest[i].cc=447;
        structtest[i].dd=766;
    }

    printf("struct unsigned char addr:0x%016X\r\n",&(structtest[0].aa));
    printf("struct int addr:0x%016X\r\n",&(structtest[0].bb));
    printf("struct longlong addr:0x%016X\r\n",&(structtest[0].cc));
    printf("struct short int  addr:0x%016X\r\n",&(structtest[0].dd));

    printf("sizeof struct is %d\r\n",sizeof(test));
    printf("sizeof unisgned char is %d\r\n",sizeof(unsigned char));
    printf("sizeof int is %d\r\n",sizeof(int));
    printf("sizeof longlong is %d\r\n",sizeof(long long));
    printf("sizeof short int is %d\r\n",sizeof(short int));
    memset(buff,0,500);
    memcpy(buff,&structtest[0],sizeof(test));
    for(i=0;i<3;i++)
    {
        for(j=0;j<8;j++)
        {
            printf("%02X ",buff[i*8+j]);
        }
        printf("\r\n");
    }
    memcpy(buff,&structtest[0],sizeof(test));
}