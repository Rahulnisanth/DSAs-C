/* THE ARRAY ADT FOR BASIC {search, insert, delete, display}
    1.SEARCH
    2.DELETE
    3.INSERT
    4.DISPLAY
USED METHODS : POINTERS AND STRUCTURES IN C LANGUAGE
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
// STRUCTURE DECLARATION -->
struct array
{
    int len;
    int arr[MAX];
    int option;
    int position;
    int value;
} my_arr;

// SEARCHING FUNCTIONS
void search(struct array *array, int value)
{
    int count = 0;
    for (int i = 0; i < array->len; i++)
    {
        if (array->arr[i] == value)
        {
            printf("Element fount at index %d\n", i + 1);
            break;
        }
        else
            count++;
    }
    if (count == array->len)
        printf("No elements found\n");
}
// INSERTING FUNCTIONS
void insert(struct array *array, int position, int value)
{
    for (int i = array->len - 1; i >= position; i--)
    {
        array->arr[i + 1] = array->arr[i];
    }
    array->arr[position] = value;
    array->len++;

    for (int i = 0; i < array->len; i++)
        printf("%d ", array->arr[i]);
}
// DISPLAY FUNCTIONS
void display(struct array *array, int position)
{
    for (int i = 0; i < position; i++)
    {
        printf("%d ", array->arr[i]);
    }
}
// DELETING FUNCTIONS
void delete(struct array *array, int position)
{
    for (int i = 0; i < array->len; i++)
    {
        if (position - 1 == i)
            continue;
        else
            printf("%d ", array->arr[i]);
    }
}
// MAIN FUNCTION -->
int main()
{
    printf("Enter the size of the array: ");
    scanf("%d", &my_arr.len);
    printf("Enter the elements of the array:-\n");
    for (int i = 0; i < my_arr.len; i++)
        scanf("%d", &my_arr.arr[i]);

    // GETTING OPTIONS -->
    scanf("%d", &my_arr.option);

    // OPTION FLAGS -->
    if (my_arr.option == 1)
    {
        scanf("%d\n%d", &my_arr.position, &my_arr.value);
        insert(&my_arr, (my_arr.position - 1), my_arr.value); // Inserting the new element...
    }
    else if (my_arr.option == 2)
    {
        scanf("%d", &my_arr.position);
        delete (&my_arr, my_arr.position); // Deleting the number un given index...
    }
    else if (my_arr.option == 3)
    {
        scanf("%d", &my_arr.value);
        search(&my_arr, my_arr.value); // Invoking the search function...
    }
    else if (my_arr.option == 4)
    {
        display(&my_arr, my_arr.len); // Display upto the given limit...
    }
    else
    {
        printf("Invalid option");
    }

    return 0;
}
