#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>

/**
* struct dlistint_s - doubly linked list
* @n: Integer stored in the node
* @prev: Pointer to the previous element of the list
* @next: Pointer to the next element of the list
*
* Description: doubly linked list node structure
*/
typedef struct dlistint_s
{
int n;
struct dlistint_s *prev;
struct dlistint_s *next;
} dlistint_t;

/* Function prototypes */
size_t dlistint_len(const dlistint_t *h);

#endif /* LISTS_H */
