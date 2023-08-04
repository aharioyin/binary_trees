#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Function that rotates right binary tree.
 * @tree: root node of three
 * Return: Pointer node of new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *fulcrum;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	fulcrum = tree->left;
	tree->left = fulcrum->right;
	if (fulcrum->right != NULL)
	{
		fulcrum->right->parent = tree;
	}
	fulcrum->right = tree;
	fulcrum->parent = tree->parent;
	tree->parent = fulcrum;
	return (fulcrum);
}
