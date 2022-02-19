#pragma once

#ifndef __DLINKLIST_H
#define __DLINKLIST_H

#include <iostream>

template <class T>
struct DNode {
	T data;
	struct DNode<T>* prior, * next;
};

template <class T>
struct DLinklist :DNode<T> {

};

template <class T>
void InitList(DLinklist<T>& L) {
	L.prior = NULL;
	L.next = NULL;
}

template <class T>
void List_HeadInsert(DLinklist<T>& L, T tag) {
	DNode<T>* s;
	T x;
	std::cin >> x;
	if (x == tag) return;
	s = new DNode<T>;
	s->data = x;
	s->next = L.next;
	s->prior = &L;
	L.next = s;
	std::cin >> x;
	while (x != tag)
	{
		s = new DNode<T>;
		s->data = x;
		s->next = L.next;
		s->prior = &L;
		L.next->prior = s;
		L.next = s;
		std::cin >> x;
	}
}

template <class T>
void List_TailInsert(DLinklist<T>& L, T tag) {
	DNode<T>* s, * r = &L;
	T x;
	std::cin >> x;
	while (x != tag)
	{
		s = new DNode<T>;
		s->data = x;
		r->next = s;
		s->prior = r;
		s->next = NULL;
		r = s;
		std::cin >> x;
	}
}

template <class T>
DNode<T>* GetElem(DLinklist<T> &L, int i) {
	DNode<T>* p = &L;
	if (i < 0) return NULL;
	while (i-- && p->next != &L) p = p->next;
	if (i < 0) return p;
	return NULL;
}

template <class T>
DNode<T>* LocateElem(DLinklist<T> L, T e) {
	DNode<T>* p = L.next;
	while (p)
	{
		if (p->data == e)
		{
			return p;
		}
		p = p->next;
	}
	return p;
}

template <class T>
bool ListInsert(DLinklist<T>& L, int i, T e) {
	DNode<T>* s = new DNode<T>;
	s->data = e;
	DNode<T>* p = GetElem(L, i);
	if (p == NULL) return false;
	s->next = p;
	s->prior = p->prior;
	p->prior->next = s;
	p->prior = s;
	return true;
}

template <class T>
DNode<T>* ListDelete(DLinklist<T> &L, int i) {
	DNode<T>* p = GetElem(L, i);
	if (p == NULL) return NULL;
	if (p->prior) p->prior->next = p->next;
	if (p->next) p->next->prior = p->prior;
	return p;
}

template <class T>
int Length(DLinklist<T> L) {
	int i = 1;
	DNode<T>* p = L.next;
	while (p)
	{
		p = p->next;
		i++;
	}
	return i;
}

template <class T>
void PrintList(DLinklist<T> L) {
	DNode<T>* p = L.next;
	while (p)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

template <class T>
bool IsEmpty(DLinklist<T> L) {
	if (L.next) return false;
	return true;
}

template <class T>
bool DestroyList(DLinklist<T> L) {
	DNode<T>* p = L.next;
	L.next = NULL;
	if (p == NULL) return false;
	while (p->next)
	{
		p = p->next;
		delete p->prior;
		p->prior = NULL;
	}
	delete p;
	return true;
}

#endif // !__DLINKLIST_H

