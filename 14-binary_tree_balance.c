#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the balance factor
 * Return: Balance factor or 0 if NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int H_left,
	    H_right,
	    balance;

	if (tree == NULL)
		return (0);

	H_left = get_tree_height(tree->left);
	H_right = get_tree_height(tree->right);
	balance = H_left - H_right;

	return (balance);
}

/**
 * get_tree_height - Calculates the height of a binary tree recursively
 * @tree: Pointer to the root to calculate the height
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
