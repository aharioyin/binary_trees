#include "binary_trees.h"

/**
 * r_insert_node - node value instertion in AVL.
 * @tree: type **pointer of root node of AVL tree struct.
 * @parent: parent node of struct AVL.
 * @new_val: type**pointer left or right insertion.
 * @nval: insertion value of AVL.
 * Return: pointer to new_val root after insertion rwise NULL
 */
avl_t *r_insert_node(avl_t **tree, avl_t *parent, avl_t **new_val, int nval)
{
	int bal_val;

	if (*tree == NULL)
		return (*new_val = binary_tree_node(parent, nval));
	if ((*tree)->n > nval)
	{
		(*tree)->left = r_insert_node(&(*tree)->left, *tree, new_val, nval);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < nval)
	{
		(*tree)->right = r_insert_node(&(*tree)->right, *tree, new_val, nval);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}
	bal_val = binary_tree_balance(*tree);
	if (bal_val > 1 && (*tree)->left->n > nval)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bal_val > 1 && (*tree)->left->n < nval)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bal_val < -1 && (*tree)->right->n < nval)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (bal_val < -1 && (*tree)->right->n > nval)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}
/**
 * avl_insert - inserts value into an AVL tree.
 * @tree: type **pointer to root node of AVL tree to insert into.
 * @value: value to store in node to be inserted
 * Return: inserted node, or NULL if fails.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_val = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	r_insert_node(tree, *tree, &new_val, value);
	return (new_val);
}
