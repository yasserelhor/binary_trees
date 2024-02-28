#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: The height of the tree or 0 if NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t L_height = 0,
	       R_height = 0,
	       height;

	if (tree == NULL)
		return (0);

	L_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	R_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	height = L_height > R_height ? L_height : R_height;
	return (height);
}
