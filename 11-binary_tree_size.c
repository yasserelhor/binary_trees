#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 * Return: Size of the tree or 0 if NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t L_Sa,
	       R_Sa,
	       size;

	if (tree == NULL)
		return (0);

	L_Sa = binary_tree_size(tree->left);
	R_Sa = binary_tree_size(tree->right);

	size = 1 + L_Sa + R_Sa;

	return (size);
}
