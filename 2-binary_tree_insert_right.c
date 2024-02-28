#include "binary_trees.h"

/**
 * binary_tree_insert_right - a function that inserts a node as
 * the right-child of another node
 *
 * @parent: a pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 *
 * Return: a pointer to the created node,
 * or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *Node_new;

	if (parent == NULL)
		return (NULL);

	Node_new = binary_tree_node(parent, value);
	if (Node_new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		parent->right->parent = Node_new;
		Node_new->right = parent->right;
	}

	parent->right = Node_new;

	return (Node_new);
}
