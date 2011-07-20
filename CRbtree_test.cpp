/*
 * CRbtree_test.cpp
 *
 *  Created on: 2011-7-17
 *      Author: Tiandao
 */
#include <iostream>
#include <stdlib.h>
#include "CRbtree.h"
using namespace std;

int main()
{
	CRbtree rbtree;
	rbtree.insert(3);
	rbtree.insert(1);
	rbtree.insert(2);
	rbtree.insert(5);
	rbtree.insert(9);
	rbtree.insert(7);
	rbtree.insert(4);
	rbtree.insert(0);
	rbtree.insert(8);
	rbtree.insert(1);
	rbtree.insert(17);
	rbtree.insert(19);
	cout << rbtree<<endl;
	cout << "Hello World!\n";
	return 0;
}
