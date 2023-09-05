/* THE ARRAY ADT FOR BASIC INSERTION
    1.BEGINNING-INSERTION
    2.ENDING-INSERTION
    3.MIDDLE-INSERTION
    4.DISPLAY
USED METHODS : POINTERS AND STRUCTURES IN C LANGUAGE
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct array
{
    int len;
    int arr[100];
    int option;
    int position;
    int value;
} my_arr;
// DISPLAYING FUNCTIONS ->
void display(struct array *array, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", array->arr[i]);
}
// INSERTING FUNCTIONS ->
void insert(struct array *array, int position, int value)
{
    if (position <= array->len)
    {
        for (int i = array->len - 1; i >= position; i--)
            array->arr[i + 1] = array->arr[i];
        array->arr[position] = value;
        array->len++;
        for (int i = 0; i < array->len; i++)
            printf("%d ", array->arr[i]);
    }
    else
    {
        array->len++;
        for (int i = 0; i < array->len; i++)
        {
            if (i + 1 == position)
                array->arr[i] = value;
            printf("%d ", array->arr[i]);
        }
    }
}
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
    if ((my_arr.option > 0) && (my_arr.option < 4))
    {
        scanf("%d\n%d", &my_arr.position, &my_arr.value);
        insert(&my_arr, my_arr.position, my_arr.value);
    }
    else if (my_arr.option == 1)
    {
        scanf("%d\n%d", &my_arr.position, &my_arr.value);
        insert(&my_arr, (my_arr.position - 1), my_arr.value);
    }
    else if (my_arr.option == 4)
    {
        display(&my_arr, my_arr.len);
    }
    else
        printf("Invalid option");
    return 0;
}