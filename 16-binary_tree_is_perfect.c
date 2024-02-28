#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 if not
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int leftP,
	    rightP,
	    H_left,
	    H_right;

	if (tree == NULL)
		return (0);

	H_left = get_tree_height(tree->left);
	H_right = get_tree_height(tree->right);

	leftP = binary_tree_is_perfect(tree->left);
	rightP = binary_tree_is_perfect(tree->right);

	if (H_left == H_right)
	{
		if (tree->left == NULL && tree->right == NULL)
			return (1);
		return (leftP && rightP);
	}
	return (0);
}

/**
 * get_tree_height - Calculates the height of a binary tree recursively
 * @tree: A pointer to the root node to calculate the height
 *
 * Return: The height of the tree or -1 when NULL
 */

int get_tree_height(const binary_tree_t *tree)
{
	int H_left,
	    H_right,
	    height;

	if (tree == NULL)
		return (-1);

	H_left = get_tree_height(tree->left);
	H_right = get_tree_height(tree->right);
	height = 1 + (H_left > H_right ? H_left : H_right);

	return (height);
}
