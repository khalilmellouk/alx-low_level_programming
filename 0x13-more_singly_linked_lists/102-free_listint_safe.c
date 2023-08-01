#include "lists.h"

/**
 * free_listint_safe - Frees a linked list safely.
 * @h: Pointer to the first node in the linked list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	listint_t *current, *next;

	if (!h || !*h)
		return (0);

	current = *h;
	while (current != NULL)
	{
		next = current->next;
		current->next = NULL; // Break the link to the next node to avoid accessing freed memory.
		free(current);
		current = next;
		len++;
	}

	*h = NULL; // Set the head to NULL after freeing the entire list.

	return (len);
}
