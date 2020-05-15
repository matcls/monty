#include "monty.h"

/**
 * free_dlistint - frees a stack_t list.
 * @head: head of the stack_t list.
 * Return: nothing
 */
void free_dlistint(stack_t *head)
{
	stack_t *node;

	while (head)
	{
		node = head;
		head = head->next;
		free(node);
	}
}

/**
 * add_dnodeint_end - adds a new node at the end of a stack_t list.
 * @head: head of the stack_t list.
 * @n: data of the node.
 * Return: the address of the new element, or NULL if it failed.
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node = NULL;
	stack_t *current = *head;

	new_node = malloc(sizeof(stack_t));
	if (!head || !new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (!(*head))
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	while (current->next)
	{
		current = current->next;
	}

	new_node->prev = current;
	current->next = new_node;
	return (new_node);
}
/**
 * add_dnodeint - adds a new node at the beginning of a stack_t list.
 * @head: head of the stack_t list.
 * @n: data od the node.
 * Return: the address of the new element, or NULL if it failed.
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	(*head)->prev = new;
	new->next = *head;
	*head = new;

	return (new);
}

/**
 * get_dnodeint_at_index - returns the nth node of a stack_t linked list.
 * @head: head of the stack_t list.
 * @index: the index of the node, starting from 0
 * Return: the index node, if the node does not exist, return NULL
 */
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	if (head && index)
		return (get_dnodeint_at_index(head->next, index - 1));

	return (head);
}

/**
 * delete_dnodeint_at_index - deletes the node at index index
 * of a stack_t linked list.
 * @head: head of the stack_t list.
 * @index: index of the node that should be deleted. Index starts at 0
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *tmp = NULL;
	unsigned int i;

	if (!head || !(*head))
		return (-1);

	for (i = 0, tmp = *head; i < index && tmp; i++, tmp = tmp->next)
		continue;
	if (!tmp)
		return (-1);

	if (tmp == *head)
		*head = tmp->next;

	if (tmp->prev)
		tmp->prev->next = tmp->next;

	if (tmp->next)
		tmp->next->prev = tmp->prev;

	free(tmp);
	return (1);
}
