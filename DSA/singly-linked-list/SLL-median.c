// PRINTING THE MEDIAN IN SLL:
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *tail;
void add(int value)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    if (head == NULL)
        head = tail = temp;
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void display(int median)
{
    struct node *test = malloc(sizeof(struct node));
    test = head;
    for (int i = 1; i <= median; i++)
    {
        if (i == median)
        {
            printf("%d ", test->data);
        }
        test = test->next;
    }
}
// MAIN DRIVE :
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        add(arr[i]);
    }
    // Finding the median-index of the list :
    int median = (n / 2) + 1;
    display(median);
    return 0;
}