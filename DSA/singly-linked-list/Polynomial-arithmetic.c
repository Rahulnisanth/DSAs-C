// POLYNOMIAL ARITHMETIC USING SINGLY-LINKED-LIST :
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int power;
    int coefficient;
    struct node *next;
};

void add(struct node **poly, int coefficient, int power)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->coefficient = coefficient;
    new_node->power = power;
    new_node->next = NULL;

    if (*poly == NULL)
    {
        *poly = new_node;
        return;
    }
    struct node *temp = *poly;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

struct node *addition(struct node *poly1, struct node *poly2)
{
    struct node *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->power == poly2->power)
        {
            add(&result, (poly1->coefficient + poly2->coefficient), poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->power > poly2->power)
        {
            add(&result, poly1->coefficient, poly1->power);
            poly1 = poly1->next;
        }
        else
        {
            add(&result, poly2->coefficient, poly2->power);
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        add(&result, poly1->coefficient, poly1->power);
        poly1 = poly1->next;
    }

    while (poly2 != NULL)
    {
        add(&result, poly2->coefficient, poly2->power);
        poly2 = poly2->next;
    }

    return result;
}
struct node *subtraction(struct node *poly1, struct node *poly2)
{
    struct node *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->power == poly2->power)
        {
            add(&result, (poly1->coefficient - poly2->coefficient), poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->power > poly2->power)
        {
            add(&result, poly1->coefficient, poly1->power);
            poly1 = poly1->next;
        }
        else
        {
            add(&result, poly2->coefficient, poly2->power);
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        add(&result, poly1->coefficient, poly1->power);
        poly1 = poly1->next;
    }

    while (poly2 != NULL)
    {
        add(&result, poly2->coefficient, poly2->power);
        poly2 = poly2->next;
    }

    return result;
}

void display(struct node *poly)
{
    if (poly == NULL)
        return;
    else
    {
        struct node *test;
        test = poly;
        printf("Polynomial : \t");
        while (test != NULL)
        {
            printf("[%d]X^%d  ", test->coefficient, test->power);
            test = test->next;
        }
    }
    printf("\n");
}

int main()
{
    struct node *poly1 = NULL;
    // First equation :
    add(&poly1, 5, 3);
    add(&poly1, 4, 2);
    add(&poly1, 3, 1);
    // Second equation :
    struct node *poly2 = NULL;
    add(&poly2, 5, 3);
    add(&poly2, 4, 2);
    add(&poly2, 3, 1);

    display(poly1);
    display(poly2);

    // Result equation of addition :
    struct node *summation = addition(poly1, poly2);
    printf("-------------------------------------------------------\nAddition-");
    display(summation);
    printf("-------------------------------------------------------\n");
    // Result equation of difference :
    struct node *difference = subtraction(poly1, poly2);
    printf("-------------------------------------------------------\nDifference-");
    display(difference);
    printf("-------------------------------------------------------\n");

    return 0;
}
