#pragma once

#ifndef __BITREE_H
#define __BITREE_H

#include <iostream>
#include "SqStack.h"
#include "SqQueue.h"

#define MAXSTACKSIZE		1000

template <class T>
struct BiTNode {
	T data;
	struct BiTNode* lchild, * rchild;
};

template <class T>
struct BiTree :BiTNode<T> {

};

template <class T>
void InitTree(BiTree<T>& B) {
	B.lchild = NULL;
	B.rchild = NULL;
	memset(B.data, 0, sizeof(T));
}

template <class T>
void PreOrder(BiTree<T>* B) {
	if (B != NULL) {
		std::cout << B->data << " ";
		PreOrder(B->lchild);
		PreOrder(B->rchilds);
	}
}

template <class T>
bool InOrder(BiTree<T>* B) {
	if (B != NULL) {
		InOrder(B->lchild);
		std::cout << B->data << " ";
		InOrder(B->rchild);
	}
}

template <class T>
bool PostOrder(BiTree<T>* B) {
	if (B != NULL) {
		PostOrder(B->lchild);
		PostOrder(B->rchild);
		std::cout << B->data << " ";
	}
}

template <class T>
void PreOrderS(BiTree<T>* B) {
	SqStack<BiTNode<T>*> S;
	InitStack(S);
	BiTNode<T>* t = B;
	while (t || !StackEmpty(S))
	{
		if (t) {
			std::cout << t->data << " ";
			Push(S, t);
			t = t->lchild;
		}
		else {
			Pop(S, t);
			t = t->rchild;
		}
	}
	std::cout << std::endl;
}

template <class T>
bool InOrderS(BiTree<T>* B) {
	SqStack<BiTNode<T>*> S;
	InitStack(S);
	BiTNode<T>* t = B;
	while (t || !StackEmpty(S))
	{
		if (t) {
			Push(S, t);
			t = t->lchild;
		}
		else {
			Pop(S, t);
			std::cout << t->data << " ";
			t = t->rchild;
		}
	}
	std::cout << std::endl;
}

template <class T>
void LevelOrder(BiTree<T> B) {
	SqQueue<BiTNode<T>*> Q;
	BiTNode<T>* p;
	InitQueue(Q);
	EnQueue(&B);
	while (!QueueEmpty(Q))
	{
		DeQueue(Q, p);
		std::cout << p->data << " ";
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);
	}
}

#endif // !__BITREE_H

