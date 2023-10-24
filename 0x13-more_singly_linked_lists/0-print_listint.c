#include "lists.h"
#include <stdio.h>

int main()
size_t print_listint(const listint_t *h);
size_t count = 0;
listint_t *current = (listint_t *)h;
while (current != NULL)
{
    printf("%d\n", current->n);
    current = current->next;
    count++;
}
printf("-> %lu elements\n", count);

