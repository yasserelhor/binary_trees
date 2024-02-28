#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 *
 * @tree: Pointer to the root node of the tree to count the number of nodes
 * Return: Count of nodes or 0 if NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t N_left,
	       N_right,
	       count;

	if (tree == NULL)
		return (0);
	N_left = binary_tree_nodes(tree->left);
	N_right = binary_tree_nodes(tree->right);

	count = 1 + N_left + N_right;

	if (tree->left != NULL || tree->right != NULL)
		return (count);

	return (0);
}
