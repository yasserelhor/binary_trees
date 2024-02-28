#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count the numberber of leaves
 * Return: The numberber of leaves or 0 if NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t L_left,
	       L_right,
	       number;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	L_left = binary_tree_leaves(tree->left);
	L_right = binary_tree_leaves(tree->right);

	number = L_left + L_right;

	return (number);
}
