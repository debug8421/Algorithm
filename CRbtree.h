/*
 * CRbtree.h
 *
 *  Created on: 2011-7-17
 *      Author: Tiandao
 */

#ifndef CRBTREE_H_
#define CRBTREE_H_
#include <istream>
#include <ostream>
using namespace std;
class CRbtree;
enum COLOR
{
   RED,
   BLACK
};
struct rb_node
{
  COLOR color;
  rb_node *ptr_parent;
  rb_node *ptr_lchild;
  rb_node *ptr_rchild;
  int key;

};

class CRbtree {
protected:

	rb_node *ptr_root;

public:

	CRbtree();
	virtual ~CRbtree();
	rb_node *get_root()
	{
		return ptr_root;
	}
	rb_node *left_rotate(rb_node *ptr_pivot);
	rb_node *right_rotate(rb_node *ptr_pivot);
	rb_node *find(int key,bool &left);
	rb_node *insert(int key);
	int *remove(int key);

	rb_node *rb_fixed_insert(rb_node *ptr_node);
	void mid_visit(rb_node* ptr_root, void(*func)(rb_node*, void*), void *)const;
	rb_node *get_successor(rb_node* ptr_node);
	void remove(rb_node *ptr_node);
	rb_node *rb_fixed_remove(rb_node *ptr_node);
	friend ostream& operator<<(ostream& out,const CRbtree& rbtree);
	friend istream& operator>>(istream& in, CRbtree& rbtree);
	

};

#endif /* CRBTREE_H_ */
