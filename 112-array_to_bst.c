#include "binary_trees.h"

/**
 * array_to_bst - builds Binary Search Tree from an array
 * @array: pointer to first element of array to be converted
 * @size: number of elements in array
 * Return: pointer to base node of created BST
 * NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int index;
	bst_t *base = NULL;

	for (index = 0; index < size; index++)
		bst_insert(&base, array[i]);

	return (base);
}
