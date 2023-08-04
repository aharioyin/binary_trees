#include "binary_trees.h"

/**
 * bst_search - searches for value in Binary Search Tree
 * @tree: pointer to root point of BST to search
 * @value: value to search in tree
 * Return: pointer to point containing an int equal to `value`
 * NULL if tree is NULL or no match found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *point = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (point)
	{
		if (value == point->n)
			return (point);
		if (value < point->n)
			point = point->left;
		else if (value > point->n)
			point = point->right;
	}

	return (NULL);
}
