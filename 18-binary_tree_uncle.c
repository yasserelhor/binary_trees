#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 * Return: Pointer to the uncle node or NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent,
		      *grandfather;

	if (node == NULL || node->parent == NULL ||
			node->parent->parent == NULL)
		return (NULL);

	parent = node->parent;
	grandfather = parent->parent;

	if (grandfather->left == parent)
		return (grandfather->right);

	if (grandfather->right == parent)
		return (grandfather->left);

	return (NULL);
}
