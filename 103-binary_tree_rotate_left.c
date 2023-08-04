#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function that rotates left binary tree.
 * @tree: root node of three
 * Return: Pointer node of new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *fulcrum;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	fulcrum = tree->right;
	tree->right = fulcrum->left;
	if (fulcrum->left != NULL)
	{
		fulcrum->left->parent = tree;
	}
	fulcrum->left = tree;
	fulcrum->parent = tree->parent;
	tree->parent = fulcrum;
	return (fulcrum);
}
