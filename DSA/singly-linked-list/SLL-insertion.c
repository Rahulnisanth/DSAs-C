// INSERTION TECHNIQUES USING SINGLY-LINKED-LIST :
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Beginning insertion :
void insertBeg(int value)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = head;
    head = new_node;
}
// Ending insertion :
void insertEnd(int value)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}
// Insertion at nth position :
void insertPos(int index, int value)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    struct Node *temp = head;
    new_node->data = value;
    new_node->next = NULL;

    while (--index)
        temp = temp->next;

    new_node->next = temp->next;
    temp->next = new_node;
}

void display()
{
    struct Node *test = head;
    while (test != NULL)
    {
        printf("%d -> ", test->data);
        test = test->next;
    }
}

int main()
{

    insertBeg(23);
    insertBeg(112);

    insertEnd(90);
    insertEnd(45);

    insertPos(3, 78);
    insertPos(1, 877);

    display();

    return 0;
}
