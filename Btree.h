#include <iostream>
// #include "lqueue.h"
#include "btnode.h"
// #include "xcept.h"
using namespace std;
template <class T>
void Visit(BinaryTreeNode<T> *x)
{
  cout << "----------------------------------------------" << endl;
	cout <<"NIK/NIP/NRM        : "<<x->data1<<endl;
  cout <<"Nama               : "<<x->data2<<endl;
  cout << "----------------------------------------------" << endl;
}

template <class T>
void PreOrder(BinaryTreeNode<T> *t){
	if (t){
		Visit(t);
		PreOrder(t->LeftChild);
		PreOrder(t->RightChild);
	}
}

template <class T>
void InOrder(BinaryTreeNode<T> *t){
	if (t){
		InOrder(t->LeftChild);
		Visit(t);
		InOrder(t->RightChild);
	}
}

template <class T>
void PostOrder(BinaryTreeNode<T> *t){
	if (t){
		PostOrder(t->LeftChild);
		PostOrder(t->RightChild);
		Visit(t);
	}
}

// template <class T>
// void LevelOrder(BinaryTreeNode<T> *t){
// 	LinkedQueue<BinaryTreeNode<T>*> Q;
// 	while (t){
// 		Visit(t);
// 		if (t->LeftChild) Q.Add(t->LeftChild);
// 		if (t->RightChild) Q.Add(t->RightChild);
// 		try{
// 			Q.Delete(t);
// 		}
// 		catch (OutOfBounds){
// 			return;
// 		}
// 	}
// }