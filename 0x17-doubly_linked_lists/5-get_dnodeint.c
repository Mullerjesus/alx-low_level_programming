#include "lists.h"

/**
* get_dnodeint_at_index - Returns the nth node of a doubly linked list
* @head: Pointer to the head of the list
* @index: Index of the node to be returned
*
* Return: Address of the nth node, or NULL if it doesn't exist
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
dlistint_t *current = head;

while (current != NULL && index > 0)
{
current = current->next;
index--;
}

return (current);
}
