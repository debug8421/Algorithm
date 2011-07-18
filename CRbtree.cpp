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
rb_node *CRbtree::find(int key,bool &left)
{
   if(0 == ptr_root)
	   return 0;
   	rb_node *ptr = ptr_root;
		while(ptr != 0 )
		{
			if(key < ptr->key )
			{
				if(ptr->ptr_lchild != 0 && key < ptr->ptr_lchild->key)
				{
					ptr = ptr->ptr_lchild;

				}
				else
				{

					left = true;
					return ptr;

				}

			}
			else
			{
				if(ptr->ptr_rchild != 0 && key >= ptr->ptr_rchild->key)
				{
					ptr = ptr->ptr_rchild;
				}
				else
				{
					left = false;
			    	return ptr;
				}


			}


		}

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
	//find

	bool left = true;
   rb_node* ptr = find(key,left);
	if(ptr == 0)
	{
		ptr_root = ptr_node;
		ptr_root->color = BLACK;
		return ptr_node;
	}
	else if(true == left)
   {
	   if(0 == ptr ->ptr_lchild)
	   {
		   ptr->ptr_lchild = ptr_node;
		   ptr_node->ptr_parent = ptr;
	   }
	   else
	   {
		   rb_node *ptr_lchild = ptr->ptr_lchild;
		   ptr->ptr_lchild = ptr_node;
		   ptr_node->ptr_parent = ptr;
		   ptr_node->ptr_lchild = ptr_lchild;
		   ptr_lchild->ptr_parent = ptr_node;
	   }
   }
	else
	{
		if(0 == ptr -> ptr_rchild)
		{
			ptr->ptr_lchild = ptr_node;
		    ptr_node->ptr_parent = ptr;
		}
		else
		{
			rb_node *ptr_rchild = ptr->ptr_rchild;
			ptr->ptr_rchild = ptr_node;
		    ptr_node->ptr_parent = ptr;
			ptr_node->ptr_rchild = ptr_rchild;
			ptr_rchild->ptr_parent = ptr_node;
		}
	}
	rb_fixed_insert(ptr_node);

	return ptr_node;
}
rb_node *CRbtree::rb_fixed_insert(rb_node *ptr_node)
{

	return ptr_node;
}
