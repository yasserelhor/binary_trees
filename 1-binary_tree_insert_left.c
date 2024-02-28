#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left child of another node
 *
 * @parent: Pointer to the node to insert the left child into
 * @value: The value to store in the new node
 *
 * Return: Pointer to the created node,
 *         or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *Node_new;

	if (parent == NULL)
		return (NULL);

	Node_new = binary_tree_node(parent, value);
	if (Node_new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		parent->left->parent = Node_new;
		Node_new->left = parent->left;
	}

	parent->left = Node_new;

	return (Node_new);
}
