// PALINDROME USING STACK:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char new_item)
{
    top++;
    stack[top] = new_item;
}

int main()
{
    char string[100];
    scanf("%s", string);
    int n = strlen(string);

    for (int i = 0; i < n; i++)
    {
        push(string[i]);
    }

    for (int i = top; i >= 0; i--)
    {
        printf("%c", stack[i]);
    }
    return 0;
}