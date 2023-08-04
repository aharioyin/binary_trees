#include "binary_trees.h"

/**
 * bst_insert - inserts value in Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: pointer to the created node
 * NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp = NULL;
	bst_t *sec = NULL;
	bst_t *new_val = NULL;

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

	new_val = binary_tree_node(NULL, value);
	if (sec == NULL)
		sec = new_val;
	else if (value < sec->n)
	{
		sec->left = new_val;
		new_val->parent = sec;
	}
	else
	{
		sec->right = new_val;
		new_val->parent = sec;
	}

	return (new_val);
}
