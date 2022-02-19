#pragma once

#ifndef __THREADTREE_H
#define __THREADTREE_H

#include <iostream>

template <class T>
struct ThreadNode {
	T data;
	struct ThreadNode<T>* lchild, * rchild;
	int ltag, rtag;
};

template <class T>
struct ThreadTree: ThreadNode<T> {

};

template <class T>
void InThread(ThreadTree<T>* p, ThreadTree<T>* pre) {
	if (p != NULL) {
		InThread(p->lchild, pre);
		if (p->lchild == NULL) {
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->rchild == NULL) {
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
		InThread(p->rchild, pre);
	}
}

template <class T>
void CreateInThread(ThreadTree<T>* t) {
	ThreadTree<T>* pre = NULL;
	if(t != NULL) {
		InThread(t, pre);
		pre->rchild = NULL;
		pre->rtag = 1;
	}
}

#endif // !__THREADTREE_H


