#include "lists.h"

/**
* insert_dnodeint_at_index - Inserts a new node at a given position
* @h: Pointer to a pointer to the head of the list
* @idx: Index of the list where the new node should be added
* @n: Value to be added to the new node
*
* Return: Address of the new node, or NULL if it failed
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *new_node, *current = *h;
unsigned int i = 0;

if (idx == 0)
{
return (add_dnodeint(h, n)); /*  Special case for adding at the beginning */
}

while (current != NULL && i < idx - 1)
{
current = current->next;
i++;
}

if (current == NULL && i == idx - 1)
{
return (add_dnodeint_end(h, n)); /* Special case for adding at the end */
}

if (current == NULL)
{
return (NULL); /*  Index out of range */
}

new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
{
return (NULL); /*  Memory allocation failed */
}

new_node->n = n;
new_node->prev = current;
new_node->next = current->next;
if (current->next != NULL)
{
current->next->prev = new_node;
}
current->next = new_node;

return (new_node);
}
