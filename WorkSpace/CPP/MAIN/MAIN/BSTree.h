#pragma once

#ifndef __BSTREE_H
#define __BSTREE_H

#include "BiTree.h"

template <class T>
BiTNode<T>* BST_Search(BiTree<T>* B, T key) {
	while (B != NULL && key != B->data)
	{
		if (key < B->data) B = B->lchild;
		else B = B->rchild;
	}
	return B;
}

template <class T>
bool BST_Insert(BiTree<T>* B, T key) {
	if (B == NULL) {
		B = new BiTNode<T>();
		B->data = key;
		B->lchild = B->rchild = NULL;
		return true;
	}
	else if (key == B->data) return false;
	else if (key < B->data) return BST_Insert(B->lchild, key);
	else return BST_Insert(B->rchild, key);
}

template <class T>
bool BST_Insert2(BiTree<T>* B, T key) {
	if (B == NULL) return false;
	if (B->data < key) {
		if (B->lchild == NULL) {
			B->lchild = new BiTNode();
			B->lchild->data = key;
			B->lchild->lchild = NULL;
			B->lchild->rchild = NULL;
			return true;
		}
		return BST_Insert2(B->lchild, key);
	} else if (B->data > key) {
		if (B->rchild == NULL) {
			B->rchild = new BiTNode();
			B->rchild->data = key;
			B->rchild->lchild = NULL;
			B->rchild->rchild = NULL;
			return true;
		}
		return BST_Insert2(B->rchild, key);
	}
	return false;
}

template <class T>
void Create_BST(BiTree<T>* B, T data[], int n) {
	B = NULL;
	int i = 0;
	while (i < n)
	{
		BST_Insert(B, data[i++]);
	}
}

template <class T>
void Create_BST2(BiTree<T>& B, T data[], int n) {
	B.data = data[0];
	int i = 1;
	while (i < n)
	{
		BST_Insert2(B, data[i++]);
	}
}

template <class T>
bool BST_Delete(BiTree<T>* B, T key) {
	BiTNode<T>* p = NULL;
	BiTNode<T>* t = NULL;
	BiTNode<T>* s = NULL;
	int lor;
	while (1)
	{
		if (B->data < key) {
			if (B->lchild == NULL) return false;
			if (B->lchild->data == key) {
				p = B;
				t = B->lchild;
				lor = 0;
				break;
			}
			else B = B->lchild;
		}
		else if (B->data > key)
		{
			if (B->rchild == NULL) return false;
			if (B->rchild->data == key) {
				p = B;
				t = B->rchild;
				lor = 1;
				break;
			}
			else B = B->rchild;
		}
		else return false;
	}
	if (lor) {
		if (t->rchild == NULL) p->rchild = t->lchild;
		else if (t->lchild == NULL) p->rchild = t->rchild;
		else {
			s = t->lchild;
			while (s->lchild) s = s->lchild;
			p->rchild = s;
			s->rchild = t->lchild;
			t->lchild->rchild = s->rchild;
		}
	}
	else {
		if (t->rchild == NULL) p->lchild = t->lchild;
		else if (t->lchild == NULL) p->lchild = t->rchild;
		else {
			s = t->lchild;
			while (s->lchild) s = s->lchild;
			p->lchild = s;
			s->rchild = t->lchild;
			p->lchild = s;
		}
	}
	delete t;
	return true;
}

#endif // !__BSTREE_H

