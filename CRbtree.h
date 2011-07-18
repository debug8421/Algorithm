/*
 * CRbtree.h
 *
 *  Created on: 2011-7-17
 *      Author: Tiandao
 */

#ifndef CRBTREE_H_
#define CRBTREE_H_
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
	rb_node *left_rotate(rb_node *ptr_pivot);
	rb_node *right_rotate(rb_node *ptr_pivot);
	rb_node *find(int key,bool &left);
	rb_node *insert(int key);
	rb_node *rb_fixed_insert(rb_node *ptr_node);


};

#endif /* CRBTREE_H_ */
