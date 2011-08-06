/*
 * CRbtree.cpp
 *
 *  Created on: 2011-7-17
 *      Author: Tiandao
 */

#include "CRbtree.h"
#include <assert.h>
#include <cstddef>
#include <vector>
#include <iterator>
using namespace std;
CRbtree::CRbtree() {
	// TODO Auto-generated constructor stub
	ptr_root = 0;
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
			ptr->ptr_rchild = ptr_node;
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
//	rb_fixed_insert(ptr_node);

	return ptr_node;
}
/**************************************************/
/* parent node: P
 * uncle node: U
 * parent's parent node: G
 * N is red, and N is left child, P is left child.
 * case1: the parent and  uncle node are red,so gradfather node must be black.
 *		set P and U black, G red, set G current node N. Maybe conflict with 2.
 * case2: the parent node P is red,uncle node U is black, current node N is red and right child.
 *        set P pivot, N is Y, then left rotate. N is left child.
 *        now set current node N is P.
 * case3: N is red. N's parent is red, and N is left child. N's parent is left child.
 *        set N black, the parent's of N is red. set N's parent is current N.
 *
 * */

/* 
 *  ptr_node is  the currnet node.
 */
rb_node *CRbtree::rb_fixed_insert(rb_node *ptr_node)
{
    assert(ptr_node);
	rb_node *ptr_current = ptr_node;
	rb_node *ptr_parent = ptr_current->ptr_parent;
	rb_node *ptr_gradfather = ptr_parent->ptr_parent;
	rb_node *ptr_uncle = 0;
	//case1 \
	//
	//
	if(BLACK == ptr_parent->color)
	{
		return ptr_current;
	}
	else
	{
		assert(ptr_gradfather);
		if(ptr_current == ptr_gradfather->ptr_lchild)
		{
			ptr_uncle = ptr_gradfather->ptr_rchild;
		}
		else
		{
			ptr_uncle = ptr_gradfather->ptr_lchild;
		}
	   if( RED == ptr_parent->color && RED == ptr_uncle->color)
	   {
		
		  ptr_parent->color = BLACK;
		  ptr_uncle->color = BLACK;
		  ptr_gradfather->color = RED;
		  ptr_current = ptr_gradfather;
		  ptr_parent = ptr_current->ptr_parent;

	   }
	    if(RED == ptr_parent->color && (0 == ptr_uncle|| (0 != ptr_uncle && BLACK == ptr_uncle->color)))
	   {
		 ptr_gradfather = ptr_parent->ptr_parent;
         assert(ptr_gradfather);
		 if(ptr_current == ptr_parent->ptr_rchild && ptr_parent == ptr_gradfather->ptr_lchild)
		 {
		    left_rotate(ptr_parent);	
			ptr_current = ptr_parent;
			ptr_parent = ptr_current->ptr_parent;
		 }
		 else if( ptr_current == ptr_parent ->ptr_lchild && ptr_parent == ptr_gradfather->ptr_rchild)
		 {
			right_rotate(ptr_parent);
			ptr_current = ptr_parent;
			ptr_parent = ptr_current->ptr_parent;
		
		 }
	    
		  if(ptr_current == ptr_parent->ptr_lchild && ptr_parent == ptr_gradfather->ptr_lchild)
		  {
				ptr_parent->color = BLACK;
				ptr_gradfather->color = RED;
                right_rotate(ptr_gradfather);
				
		  }
		  else if(ptr_current == ptr_parent->ptr_rchild && ptr_parent == ptr_gradfather->ptr_rchild)
		  {
				ptr_parent->color = BLACK;
				ptr_gradfather->color = RED;
				left_rotate(ptr_gradfather);

		  }

		}
	}

	return ptr_node;
}


void CRbtree::mid_visit(rb_node* ptr_root,void(*func)(rb_node*, void*), void * para)const
{
	rb_node *ptr = ptr_root;
	if(ptr_root == 0)
	  return;
	else
	{
	   CRbtree::mid_visit(ptr_root->ptr_lchild, func, para);
	   func(ptr_root, para);
	   CRbtree::mid_visit(ptr_root->ptr_rchild,func,para);
	}
	 
}
void enumeration(rb_node* rb_node_ptr, void* ptr_vector_data)
{
	vector<int> * vData = (vector<int>*) ptr_vector_data;
	if(rb_node_ptr)
	{
	   vData->push_back(rb_node_ptr->key);
	}
}

ostream& operator<<(ostream& out,const CRbtree& rbtree )
{
   vector<int> *ptr_vector_data = new vector<int>();
  rbtree.mid_visit(rbtree.ptr_root,enumeration, (void*)ptr_vector_data);
   for(vector<int>::iterator iter = ptr_vector_data->begin(); iter != ptr_vector_data->end(); iter ++)
   {
      out << *iter<<'\t';
   }
    return out;
}

istream& operator>>(istream& in, CRbtree& rbtree)
{
    return in;
 }

