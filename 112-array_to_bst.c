#include "binary_trees.h"

/**
 * array_to_bst - builds Binary Search Tree from an array
 * @array: pointer to first element of array to be converted
 * @size: number of elements in array
 * Return: pointer to root node of created BST
 * NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int i;
	bst_t *root = NULL;

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
