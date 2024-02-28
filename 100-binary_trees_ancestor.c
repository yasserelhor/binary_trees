#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *firstAn,
		      *secondAn,
		      *firstSecond;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	firstAn = binary_trees_ancestor(first, second->parent);
	if (first->parent == NULL || first == second->parent ||
			(!first->parent->parent && second->parent))
		return (firstAn);

	secondAn = binary_trees_ancestor(first->parent, second);
	if (second->parent == NULL || second == first->parent ||
			(!second->parent->parent && first->parent))
		return (secondAn);

	firstSecond = binary_trees_ancestor(first->parent, second->parent);
	return (firstSecond);
}
