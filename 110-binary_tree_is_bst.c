#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if binary tree is valid Binary Search Tree
 * @tree: pointer to root node of tree to check
 *
 * Return: 1 if tree is valid BST
 * else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btib_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btib_helper - checks if binary tree is valid Binary Search Tree
 * @tree: pointer to root node of tree to check
 * @min: Lower bound of checked nored
 * @max: Upper bound of checked nodes
 *
 * Return: 1 if tree is valid BST
 * 0 rwise
 */
int btib_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (btib_helper(tree->left, min, tree->n - 1) &&
		btib_helper(tree->right, tree->n + 1, max));
}
