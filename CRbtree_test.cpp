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
	int data[]={12, 1, 9, 2, 0, 11, 7, 19, 4, 15, 18,  5, 14, 13, 10, 16, 6, 3, 8 ,17};
	for(int i = 0; i < 20; i ++)
	{
		rbtree.insert(data[i]);
	}
	cout << rbtree<<endl;
	cout << "Hello World!\n";
	return 0;
}
