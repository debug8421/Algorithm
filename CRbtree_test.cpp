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
	rbtree.insert(1);
	rbtree.insert(2);
	rbtree.insert(3);
	cout << "Hello World!\n";
	return 0;
}
