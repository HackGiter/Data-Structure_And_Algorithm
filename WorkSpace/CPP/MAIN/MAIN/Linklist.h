#pragma once

#ifndef __LINKLIST_H
#define __LINKLIST_H

#include <iostream>

template <class T>
struct LNode {
	T data;
	struct LNode<T>* next;
};

template <class T>
struct Linklist :LNode<T> {
};

template <class T>
void InitList(Linklist<T>& L) {
	L.next = NULL;
}

template <class T>
void List_HeadInsert(Linklist<T>& L, T tag) {
	LNode<T>* s;
	T x;
	std::cin >> x;
	while (x != tag)
	{
		s = new LNode<T>;
		s->data = x;
		s->next = L.next;
		L.next = s;
		std::cin >> x;
	}
}

template <class T>
void List_TailInsert(Linklist<T>& L, T tag) {
	LNode<T>* s, * r = &L;
	T x;
	std::cin >> x;
	while (x != tag)
	{
		s = new LNode<T>;
		s->data = x;
		s->next = NULL;
		r->next = s;
		r = s;
		std::cin >> x;
	}
}

template <class T>
LNode<T>* GetElem(Linklist<T>& L, int i) {
	LNode<T>* p = &L;
	if (i < 0) return NULL;
	while (i-- && p->next != &L) p = p->next;
	if (i < 0) return p;
	return NULL;
}

template <class T>
LNode<T>* LocateElem(Linklist<T> L, T e) {
	LNode<T>* p  = L.next;
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
bool ListInsert(Linklist<T>& L, int i, T e) {
	LNode<T>* s = new LNode<T>;
	s->data = e;
	LNode<T>* p = GetElem(L, i - 1);
	if (p == NULL) return false;
	s->next = p->next;
	p->next = s;
	return true;
}

template <class T>
LNode<T>* ListDelete(Linklist<T> L, int i) {
	LNode<T>* p = GetElem(L, i - 1);
	if (p == NULL || p->next == NULL) return NULL;
	LNode<T>* s = p->next;
	p->next = s->next;
	s->next = NULL;
	return s;
}

template <class T>
int Length(Linklist<T> L) {
	int i = 1;
	LNode<T>* p = L.next;
	while (p)
	{
		p = p->next;
		i++;
	}
	return i;
}

template <class T>
void PrintList(Linklist<T> L) {
	LNode<T>* p = L.next;
	while (p)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

template <class T>
bool IsEmpty(Linklist<T> L) {
	if (L.next) return false;
	return true;
}

template <class T>
bool DestroyList(Linklist<T> &L) {
	LNode<T>* p = L.next;
	LNode<T>* s;
	while (p)
	{
		s = p->next;
		delete p;
		p = s;
	}
	L.next = NULL;
	return true;
}

#endif // !__LINKLIST_H


