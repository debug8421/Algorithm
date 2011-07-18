/*
 * CRbtree.cpp
 *
 *  Created on: 2011-7-17
 *      Author: Tiandao
 */

#include "CRbtree.h"
#include <assert.h>
#include <cstddef>
CRbtree::CRbtree() {
	// TODO Auto-generated constructor stub

}

CRbtree::~CRbtree() {
	// TODO Auto-generated destructor stub
}
rb_node *CRbtree::left_rotate(rb_node *ptr_pivot)
{

	assert(ptr_pivot);
	rb_node *ptr_parent = ptr_pivot->ptr_parent;
	rb_node *ptr_Y = ptr_pivot->ptr_rchild;
	assert(ptr_Y);
	rb_node *ptr_b = ptr_Y->ptr_lchild;
	if(ptr_parent == 0)
	{
	   ptr_root = ptr_Y;
	}
	else if(ptr_parent->ptr_lchild == ptr_pivot)
	{
		ptr_parent->ptr_lchild = ptr_Y;
	}
	else
	{
		ptr_parent->ptr_rchild = ptr_Y;
	}
	ptr_Y->ptr_parent = ptr_parent;
	ptr_Y->ptr_lchild = ptr_pivot;
	ptr_pivot->ptr_parent = ptr_Y;
	ptr_pivot->ptr_rchild = ptr_b;
	if(ptr_b != 0)
	{
		ptr_b->ptr_parent = ptr_pivot;
	}
	return ptr_Y;

}
rb_node *CRbtree::right_rotate(rb_node *ptr_pivot)
{
	assert(ptr_pivot);
	rb_node *ptr_parent = ptr_pivot->ptr_parent;
	rb_node *ptr_Y = ptr_pivot->ptr_lchild;
	assert(ptr_Y);
	rb_node *ptr_b = ptr_Y->ptr_rchild;
	if(ptr_parent == 0)
	{
		ptr_root = ptr_Y;
	}
	else if(ptr_parent->ptr_lchild == ptr_pivot)
	{
		ptr_parent->ptr_lchild = ptr_Y;
	}
	else
	{
		ptr_parent->ptr_rchild = ptr_Y;

	}
	ptr_Y->ptr_parent = ptr_parent;
	ptr_Y->ptr_rchild = ptr_pivot;
	ptr_pivot->ptr_parent = ptr_Y;
	ptr_pivot->ptr_lchild = ptr_b;
	if(ptr_b != 0)
	{
		ptr_b->ptr_parent = ptr_pivot;
	}

	return ptr_Y;
	
}


rb_node *CRbtree::insert(int key)
{
	rb_node *ptr_node = new rb_node();
	ptr_node->key = key;
	ptr_node->ptr_lchild = 0;
	ptr_node->ptr_rchild = 0;
	ptr_node->ptr_parent = 0;
	ptr_node->color = RED;
//sort
	rb_node *ptr = ptr_root;
	if(ptr_root == 0)
	{
		ptr_root = ptr_node;
		ptr_root->color = BLACK;
	}
	while(ptr != 0 )
	{
		if(ptr_node->key < ptr->key )
		{
			if(ptr->ptr_lchild != 0)
			{
				rb_node *ptr_lchild = ptr->ptr_lchild;
				if(ptr_node->key >= ptr_lchild->key)
				{
					ptr->ptr_lchild = ptr_node;
					ptr_node->ptr_parent = ptr;
					ptr_node->ptr_lchild = ptr_lchild;
					ptr_lchild->ptr_parent = ptr_node;
					break;
				}
				else
				{
					ptr = ptr->ptr_lchild;

				}
			}
			else
			{
				ptr->ptr_lchild = ptr_node;
				ptr_node->ptr_parent = ptr;

			}

		}
		else
		{
			if(ptr->ptr_rchild != 0)
			{
				rb_node *ptr_rchild = ptr->ptr_rchild;
				if(ptr_node->key <= ptr_rchild->key)
				{
					ptr->ptr_rchild = ptr_node;
					ptr_node->ptr_parent = ptr;
					ptr_node->ptr_rchild = ptr_rchild;
					ptr_rchild->ptr_parent = ptr_node;
					break;
				}
				else
				{
					ptr = ptr->ptr_rchild;
				}
			}
			else
			{
				ptr_node->ptr_parent = ptr;
				ptr->ptr_rchild = ptr_node;

			}

		}


	}

	return ptr_root;
}
