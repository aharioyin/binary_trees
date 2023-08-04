#include "binary_trees.h"

/**
 * bst_insert - inserts value in Binary Search Tree
 * @tree: double pointer to root node of BST to insert value
 * @value: value to store in node to be inserted
 * Return: pointer to created node
 * NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp = NULL;
	bst_t *sec = NULL;
	bst_t *added = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	temp = *tree;
	while (temp)
	{
		sec = temp;
		if (value < temp->n)
			temp = temp->left;
		else if (value > temp->n)
			temp = temp->right;
		else if (value == temp->n)
			return (NULL);
	}

	added = binary_tree_node(NULL, value);
	if (sec == NULL)
		sec = added;
	else if (value < sec->n)
	{
		sec->left = added;
		added->parent = sec;
	}
	else
	{
		sec->right = added;
		added->parent = sec;
	}

	return (added);
}
