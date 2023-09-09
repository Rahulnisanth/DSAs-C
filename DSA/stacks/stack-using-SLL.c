// STACK IMPLEMENTATION USING SLL :
#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *tail; // Head & Tail pointers
void push(int new_value)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = new_value;
    new_node->next = NULL;

    if (head == NULL)
        head = tail = new_node;
    else
    {
        tail->next = new_node;
        tail = new_node;
    }
}
void pop()
{
    struct node *tag = head;
    struct node *prev;
    if (head == NULL)
    {
        printf("The stack is empty!\n");
        return;
    }
    if (tag->next == NULL)
    {
        head = NULL;
        return;
    }
    else
    {
        while (tag->next != NULL)
        {
            prev = tag;
            tag = tag->next;
        }
        prev->next = NULL;
        printf("Popped last element %d in the stack!\n", tag->data);
        free(tag);
    }
}
void display()
{
    struct node *temp = head;
    printf("The elements in the stack are:\n");
    while (temp != NULL)
    {
        printf("%d <- ", temp->data);
        temp = temp->next;
    }
}
// MAIN DRIVE FUNCTION :
int main()
{
    // pushing elements in stack...
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    // popping the last element...
    pop();
    // printing the stack...
    display();
    return 0;
}