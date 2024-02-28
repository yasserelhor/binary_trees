#include "binary_trees.h"

/**
 * binary_tree_node - a function that creates a binary tree node
 * @parent: a pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * Return: a pointer to the new node, or NULL
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *Node_new;

	Node_new = malloc(sizeof(binary_tree_t));
	if (Node_new == NULL)
		return (NULL);

	Node_new->n = value;
	Node_new->parent = parent;
	Node_new->left = NULL;
	Node_new->right = NULL;

	return (Node_new);
}
