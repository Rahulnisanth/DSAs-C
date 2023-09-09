// DELETION TECHNIQUES USING SINGLY-LINKED-LIST :
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

// Element enrolling to list :
void add(int value)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL)
        head = tail = new_node;

    else
    {
        tail->next = new_node;
        tail = new_node;
    }
}
// Beginning deletion :
void deleteBeg()
{
    if (head == NULL)
        printf("The list is empty\n");
    else
    {
        head = head->next;
        printf("Deleted the first node!\n");
    }
}
// Ending deletion :
void deleteEnd()
{
    if (head == NULL)
        printf("The list is empty\n");
    else
    {
        struct Node *prev = head;
        struct Node *temp = head;
        // List deletion for 1 element :
        if (head->next == NULL)
        {
            head = NULL;
            return;
        }
        // List deletion at end :
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}
// Deletion at nth position :
void deletePos(int index)
{
    if (head == NULL)
        printf("The list is empty\n");
    else if (index == 1)
    {
        deleteBeg();
        return;
    }
    else
    {
        struct Node *temp = head;
        struct Node *prev = head;

        for (int i = 1; i <= index; i++)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        printf("Deleted the node of data %d in list\n", temp->data);
        free(temp);
    }
}

void display()
{
    struct Node *test = head;
    while (test != NULL)
    {
        printf("%d -> ", test->data);
        test = test->next;
    }
    printf("\n");
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; i++)
        add(arr[i]);

    display();

    deleteBeg();
    deleteBeg();

    deleteEnd();
    deleteEnd();

    deletePos(3);

    display();

    return 0;
}
