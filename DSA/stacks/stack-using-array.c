// STACK IMPLEMENTATION USING ARRAY:
#include <stdio.h>
#include <stdlib.h>

int choice, n, top = -1, value;
int stack[100];
void push()
{
    if (top == n - 1)
        printf("Stack overflow\n");
    else
    {
        scanf("%d", &value);
        stack[++top] = value;
        printf("PUSH %d SUCCESSFUL\n", stack[top]);
    }
}
void pop()
{
    if (top == -1)
        printf("Stack underflow\n");
    else
    {
        printf("POP %d\n", stack[top]);
        top--;
    }
}
void peek()
{
    if (top == -1)
        printf("STACK EMPTY\n");
    else
        printf("%d\n", stack[top]);
}
int main()
{

    scanf("%d", &n);

    do
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            break;
        }
    } while (choice != 4);
    return 0;
}
