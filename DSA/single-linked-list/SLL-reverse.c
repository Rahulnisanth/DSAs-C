// REVERSE OF SLL :
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head, *tail;

void add(int data)
{
    struct Node *temp;
    temp = malloc(sizeof(struct Node));

    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

// Reverse fuction :
void reverse()
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void display()
{
    struct Node *test;
    test = head;
    while (test != NULL)
    {
        printf("%d -> ", test->data);
        test = test->next;
    }
    printf("\n");
}
// MAIN DRIVE :
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; i++)
        add(arr[i]);

    //Original list...
    display();
    reverse();
    //After reversing...
    display();

    return 0;
}
