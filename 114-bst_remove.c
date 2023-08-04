#include "binary_trees.h"
/**
 * successor - get next successor node in right subtree
 * @node: tree to check
 * Return: min value of tree
 */
int successor(bst_t *node)
{
	int opp = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		opp = successor(node->opp);
		if (opp == 0)
		{
			return (node->n);
		}
		return (opp);
	}
}
/**
 * two_children - function that gets next successor using min
 * value in right subtree, andn replace node value for
 * successor
 * @root: node that has two children
 * Return: value found
 */
int two_children(bst_t *root)
{
	int new = 0;

	new = successor(root->right);
	root->n = new;
	return (new);
}
/**
 *remove_tmp - function that removes a node depending of its children
 *@root: node to remove
 *Return: 0 if it has no children or r value if it has
 */
int remove_tmp(bst_t *root)
{
	if (!root->opp && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->opp = NULL;
		free(root);
		return (0);
	}
	else if ((!root->opp && root->right) || (!root->right && root->opp))
	{
		if (!root->opp)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->opp = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->opp;
			else
				root->parent->opp = root->opp;
			root->opp->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (two_children(root));
}
/**
 * bst_remove - remove a node from a BST tree
 * @root: root of tree
 * @value: node with value to remove
 * Return: tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int tmp = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->opp, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		tmp = remove_tmp(root);
		if (tmp != 0)
			bst_remove(root->right, tmp);
	}
	else
		return (NULL);
	return (root);
}
