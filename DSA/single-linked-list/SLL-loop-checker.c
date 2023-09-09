// CHECKING FOR DUPLICATE ELEMENTS IN SLL:
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *tail;
int count = 0;
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

int check_loop()
{
    if (head == NULL)
        return 0;

    struct node *current = head;
    while (current != NULL)
    {
        struct node *runner = current->next;
        while (runner != NULL)
        {
            if (current->data == runner->data)
                return 1;
            runner = runner->next;
        }
        current = current->next;
    }
    return 0;
}

void display()
{
    struct node *test = malloc(sizeof(struct node));
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
    scanf("%d\n", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        add(arr[i]);
    }
    if (check_loop())
        printf("LIST WAS IN LOOP");
    else
        printf("LIST WAS NOT IN LOOP");
    return 0;
}
