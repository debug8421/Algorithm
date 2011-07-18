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
