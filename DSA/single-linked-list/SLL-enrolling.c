// ADDING ELEMENTS TO SLL FROM ARRAY :
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

void display()
{
    struct Node *test;
    test = head;
    while (test != NULL)
    {
        printf("%d ", test->data);
        test = test->next;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    // Passing the array elements to list :
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d\n", &arr[i]);
        add(arr[i]);
    }

    display();
    return 0;
}
