#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if it is full, 0 if not
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int F_left,
	    F_right;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	F_left = binary_tree_is_full(tree->left);
	F_right = binary_tree_is_full(tree->right);

	if (tree->left != NULL && tree->right != NULL)
		return (F_left && F_right);

	return (0);
}
