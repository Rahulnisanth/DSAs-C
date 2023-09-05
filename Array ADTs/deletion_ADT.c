/* THE ARRAY ADT FOR BASIC DELETION
    1.BEGINNING-DELETION
    2.ENDING-DELETION
    3.MIDDLE-DELETION
    4.DISPLAY
USED METHODS : POINTERS AND STRUCTURES IN C LANGUAGE
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct array
{
    int len;
    int arr[MAX];
    int option;
} my_arr;

// DISPLAYING FUNCTIONS ->
void display(struct array *array, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", array->arr[i]);
}
// DELETING FUNCTIONS ->
void delete(struct array *array, int index)
{
    for (int i = 0; i < array->len; i++)
    {
        if (i == index)
            continue;
        else
            printf("%d ", array->arr[i]);
    }
}
int main()
{
    printf("Enter the size of the array: ");
    scanf("%d", &my_arr.len);
    printf("Enter the my_arr elements:-\n");
    for (int i = 0; i < my_arr.len; i++)
        scanf("%d", &my_arr.arr[i]);
    scanf("%d", &my_arr.option);

    // OPTIONS FLAGS ->
    if (my_arr.option == 4)
        display(&my_arr, my_arr.len);
    else if (my_arr.option == 1)
    {
        delete (&my_arr, 0);
    }
    else if (my_arr.option == 2)
    {
        delete (&my_arr, (my_arr.len - 1));
    }
    else if (my_arr.option == 3)
    {
        delete (&my_arr, (my_arr.len / 2));
    }
    else
        printf("Invalid option");
    return 0;
}