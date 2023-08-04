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
	base->right = binary_tree_node(base, 402);
	binary_tree_print(base);
	printf("\n");
	binary_tree_insert_right(base->left, 54);
	binary_tree_insert_right(base, 128);
	binary_tree_print(base);
	return (0);
}
