#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
* struct dlistint_s - Doubly linked list node structure
* @n: Integer stored in the node
* @prev: Pointer to the previous element in the list
* @next: Pointer to the next element in the list
*
* Description: Doubly linked list node structure
*/
typedef struct dlistint_s
{
int n;
struct dlistint_s *prev;
struct dlistint_s *next;
} dlistint_t;

size_t print_dlistint(const dlistint_t *h);

#endif /* LISTS_H */
