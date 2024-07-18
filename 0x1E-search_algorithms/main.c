#include <stdio.h>  
#include <stdlib.h>  
#include "search_algos.h"  

/**  
 * print_array - Prints an array of integers  
 * @array: The array to print  
 * @size: The size of the array  
 */  
void print_array(int *array, size_t size)  
{  
    size_t i;  

    if (array == NULL)  
        return;  

    printf("[");  
    for (i = 0; i < size; i++)  
    {  
        printf("%d", array[i]);  
        if (i < size - 1)  
            printf(", ");  
    }  
    printf("]\n");  
}  


/**  
 * main - Entry point of the program  
 * Return: Always 0 (success)  
 */  
int main(void)  
{  
    int array[] = {98, 2, 7, 5, 11, 12, 42, 9, 100, 1};  
    size_t n = sizeof(array) / sizeof(array[0]);  
    int value = 12;  

    printf("Linear search in [");  
    print_array(array, n);  
    printf("]\n");  

    printf("Value to search for: %d\n", value);  
    int index = linear_search(array, n, value);  

    if (index == -1)  
        printf("Value not found\n");  
    else  
        printf("Value found at index: %d\n", index);  

    return (0);  
}
