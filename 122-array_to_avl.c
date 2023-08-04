#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: array to create from
 * @size: size of array
 *
 * Return: a pointer to root node of created AVL tree
 * NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int index;
	avl_t *root = NULL;

	for (index = 0; index < size; index++)
		avl_insert(&root, array[i]);

	return (root);
}
