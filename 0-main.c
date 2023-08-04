#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *base;

	base = binary_tree_node(NULL, 98);

	base->left = binary_tree_node(base, 12);
	base->left->left = binary_tree_node(base->left, 6);
	base->left->right = binary_tree_node(base->left, 16);

	base->right = binary_tree_node(base, 402);
	base->right->left = binary_tree_node(base->right, 256);
	base->right->right = binary_tree_node(base->right, 512);

	binary_tree_print(base);
	return (0);
}
