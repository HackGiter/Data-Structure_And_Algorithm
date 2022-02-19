#pragma once

#ifndef __CLINKLIST_H
#define __CLINKLIST_H

#include <iostream>

template <class T>
struct CNode {
	T data;
	struct CNode<T>* next;
};

template <class T>
struct CLinklist :CNode<T> {
};

template <class T>
void InitList(CLinklist<T>& L) {
	L.next = &L;
}

template <class T>
void List_HeadInsert(CLinklist<T>& L, T tag) {
	CNode<T>* s;
	T x;
	std::cin >> x;
	while (x != tag)
	{
		s = new CNode<T>;
		s->data = x;
		s->next = L.next;
		L.next = s;
		std::cin >> x;
	}
}

template <class T>
void List_TailInsert(CLinklist<T>& L, T tag) {
	CNode<T>* s, * r = &L;
	T x;
	std::cin >> x;
	while (x != tag)
	{
		s = new CNode<T>;
		s->data = x;
		s->next = &L;
		r->next = s;
		r = s;
		std::cin >> x;
	}
}

template <class T>
CNode<T>* GetElem(CLinklist<T>& L, int i) {
	CNode<T>* p = &L;
	if (i < 0) return NULL;
	while (i-- && p->next != &L) p = p->next;
	if (i < 0) return p;
	return NULL;
}

template <class T>
CNode<T>* LocateElem(const CLinklist<T>& L, T e) {
	CNode<T>* p = L.next;
	while (p != &L)
	{
		if (p->data == e)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

template <class T>
bool ListInsert(CLinklist<T>& L, int i, T e) {
	CNode<T>* s = new CNode<T>;
	s->data = e;
	CNode<T>* p = GetElem(L, i - 1);
	if (p == NULL) return false;
	s->next = p->next;
	p->next = s;
	return true;
}

template <class T>
CNode<T>* ListDelete(CLinklist<T>& L, int i) {
	CNode<T>* p = GetElem(L, i - 1);
	if (p == NULL || p->next == &L) return NULL;
	CNode<T>* s = p->next;
	p->next = s->next;
	return s;
}

template <class T>
int Length(const CLinklist<T> &L) {
	int i = 0;
	CNode<T>* p = L.next;
	while (p != &L)
	{
		p = p->next;
		i++;
	}
	return i;
}

template <class T>
void PrintList(const CLinklist<T> &L) {
	CNode<T>* p = L.next;
	while (p != &L)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

template <class T>
bool IsEmpty(CLinklist<T> &L) {
	if (L.next != &L) return false;
	return true;
}

template <class T>
bool DestroyList(CLinklist<T> &L) {
	CNode<T>* p = L.next;
	CNode<T>* s;
	while (p!= &L)
	{
		s = p->next;
		delete p;
		p = s;
	}
	L.next = &L;
	return true;
}

#endif // !__CLINKLIST_H

