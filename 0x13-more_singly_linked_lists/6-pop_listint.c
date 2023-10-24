#include <stdlib.h>
#include "lists.h"

/**
* pop_listint - Deletes the head node of a listint_t linked list.
* @head: Double pointer to the head of the list.
*
* Return: The head node's data (n), or 0 if the list is empty.
*/
int pop_listint(listint_t **head)
{
listint_t *current;
int n;

if (head == NULL || *head == NULL)
return (0);

current = *head;
n = current->n;
*head = current->next;
free(current);

return (n);
}
