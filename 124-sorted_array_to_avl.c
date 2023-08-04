#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to first element of array to be converted
 * @size: number of elements in array
 *
 * Return: pointer to root node of created AVL tree
 *         NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t center;

	if (!array)
		return (NULL);
	center = (size - 1) / 2;
	tree = binary_tree_node(NULL, array[center]);

	sata_helper(&tree, array, -1, center);
	sata_helper(&tree, array, center, size);

	return (tree);
}

/**
 * sata_helper - helper that builds an AVL tree from an array
 * @root: double pointer to root node of subtree
 * @array: pointer to first element of array to be converted
 * @lo: lower bound index
 * @hi: upper bound index
 */
void sata_helper(avl_t **root, int *array, size_t lo, size_t hi)
{
	avl_t *new = NULL;
	size_t center;

	if (hi - lo > 1)
	{
		center = (hi - lo) / 2 + lo;
		new = binary_tree_node(*root, array[center]);
		if (array[center] > (*root)->n)
			(*root)->right = new;
		else if (array[center] < (*root)->n)
			(*root)->left = new;
		sata_helper(&new, array, lo, center);
		sata_helper(&new, array, center, hi);
	}
}