#include <stdio.h>

union tipo{
    int x;
    unsigned char c[2];
};

int main(){

union tipo teste;

teste.x = 222582393;
printf("%x\n", teste.x);

printf("%c\n", teste.c[0]);


};