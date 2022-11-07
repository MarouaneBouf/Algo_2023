#include <stdio.h>

int main(void)
{
    char name[40];
    scanf("%[^\n]",name);
    printf("%s\n",name);
}