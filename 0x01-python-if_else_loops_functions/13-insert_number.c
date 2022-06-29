#include "lists.h"

/**
 * insert_node - malloc and insert node into sorted singly linked list
 * @head: pointer to head of linked list
 * @number: data for new node
 * Return: address of new node, or NULL if failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *tmpNode = NULL;
	listint_t *new = NULL;

	if (!head)
		return (NULL);

	/* malloc new node */
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;

	/* if no linked list, insert node as the only member of the list */
	if (*head == NULL)
	{
		*head = new;
		(*head)->next = NULL;
		return (new);
	}
	/* if only one node in linked list, compare and insert */
	if ((*head)->next == NULL)
	{
		if ((*head)->n > new->n)
		{
			new->next = *head;
			*head = new;
		}
		else
			(*head)->next = new;
		return (new);
	}

	/* if more than one nodes in linked list, compare and insert */
	tmpNode = *head;
	while (tmpNode->next != NULL)
	{
		/* if new node num is smaller than first node, insert */
		if (new->n < tmpNode->n)
		{
			new->next = tmpNode;
			*head = new;
			return (new);
		}
		/* if new node num is the same as an existing node, insert */
		/* compare previous node and next node, insert in between */
		if (((new->n > tmpNode->n) && (new->n < (tmpNode->next)->n)) ||
		    (new->n == tmpNode->n))
		{
			new->next = tmpNode->next;
			tmpNode->next = new;
			return (new);
		}
		tmpNode = tmpNode->next;
	}
	/* if new node is greatest and never inserted, insert now */
	tmpNode->next = new;
	return (new);
}
