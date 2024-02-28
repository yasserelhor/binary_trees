#include "binary_trees.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* print_t - Recursively stores each level in an array of strings for printing
* @tree: Pointer to the node to print
* @offset: Offset for printing
* @depth: Depth of the node
* @s: Buffer for storing
* Return: Length of printed tree after processing
*/

static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width, left, right, is_left, i;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);
	for (i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];
	if (depth && is_left)
	{
		for (i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * _height - Calculates the height of a binary tree
 *
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: The height of the binary tree
 */

static size_t _height(const binary_tree_t *tree)
{
	size_t height_1;
	size_t height_2;

	height_1 = tree->left ? 1 + _height(tree->left) : 0;
	height_2 = tree->right ? 1 + _height(tree->right) : 0;
	return (height_1 > height_2 ? height_1 : height_2);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to be printed
 */

void binary_tree_print(const binary_tree_t *tree)
{
	char **satr;
	size_t height, i, j;

	if (!tree)
		return;
	height = _height(tree);
	satr = malloc(sizeof(*satr) * (height + 1));
	if (!satr)
		return;
	for (i = 0; i < height + 1; i++)
	{
		satr[i] = malloc(sizeof(**satr) * 255);
		if (!satr[i])
			return;
		memset(satr[i], 32, 255);
	}
	print_t(tree, 0, 0, satr);
	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (satr[i][j] != ' ')
				break;
			satr[i][j] = '\0';
		}
		printf("%s\n", satr[i]);
		free(satr[i]);
	}
	free(satr);
}
