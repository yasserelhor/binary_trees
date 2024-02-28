#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 *
 * @tree: Pointer to the node to measure the depth
 * Return: Size of the tree or 0 if NULL
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	const binary_tree_t *Present;

	if (tree == NULL)
		return (0);

	Present = tree;
	while (Present->parent != NULL)
	{
		depth++;
		Present = Present->parent;
	}
	return (depth);
}
