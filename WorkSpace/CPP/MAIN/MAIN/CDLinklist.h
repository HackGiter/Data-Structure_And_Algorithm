#pragma once

#ifndef __CDLINKLIST_H
#define __CDLINKLIST_H

#include <iostream>

template <class T>
struct CDNode {
	T data;
	struct CDNode<T>* prior, * next;
};

template <class T>
struct CDLinklist :CDNode<T> {
};

template <class T>
void InitList(CDLinklist<T>& L) {
	L.prior = &L;
	L.next = &L;
}

template <class T>
void List_HeadInsert(CDLinklist<T>& L, T tag) {
	CDNode<T>* s;
	T x;
	std::cin >> x;
	if (x == tag) return;
	s = new CDNode<T>;
	s->data = x;
	s->next = L.next;
	s->prior = &L;
	L.next = s;
	L.prior = s;
	std::cin >> x;
	while (x != tag)
	{
		s = new CDNode<T>;
		s->data = x;
		s->next = L.next;
		s->prior = &L;
		L.next->prior = s;
		L.next = s;
		std::cin >> x;
	}
}

template <class T>
void List_TailInsert(CDLinklist<T>& L, T tag) {
	CDNode<T>* s, * r = &L;
	T x;
	std::cin >> x;
	while (x != tag)
	{
		s = new CDNode<T>;
		s->data = x;
		s->next = &L;
		s->prior = r;
		r->next = s;
		r = s;
		L.prior = r;
		std::cin >> x;
	}
}

template <class T>
CDNode<T>* GetElem(CDLinklist<T>& L, int i) {
	CDNode<T>* p = &L;
	if (i < 0) return NULL;
	while (i-- && p->next != &L) p = p->next;
	if (i < 0) return p;
	return NULL;
}

template <class T>
CDNode<T>* LocateElem(const CDLinklist<T>& L, T e) {
	CDNode<T>* p = L.next;
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
bool ListInsert(CDLinklist<T>& L, int i, T e) {
	CDNode<T>* s = new CDNode<T>;
	s->data = e;
	CDNode<T>* p = GetElem(L, i);
	if (p == NULL) return false;
	s->next = p;
	s->prior = p->prior;
	p->prior = s;
	s->prior->next = s;
	return true;
}

template <class T>
CDNode<T>* ListDelete(CDLinklist<T>& L, int i) {
	CDNode<T>* p = GetElem(L, i);
	if (p == NULL) return NULL;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	return p;
}

template <class T>
int Length(const CDLinklist<T>& L) {
	int i = 0;
	CDNode<T>* p = L.next;
	while (p != &L)
	{
		p = p->next;
		i++;
	}
	return i;
}

template <class T>
void PrintList(const CDLinklist<T>& L) {
	CDNode<T>* p = L.next;
	while (p != &L)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

template <class T>
bool IsEmpty(CDLinklist<T>& L) {
	if (L.next != &L) return false;
	return true;
}

template <class T>
bool DestroyList(CDLinklist<T>& L) {
	CDNode<T>* p = L.next;
	CDNode<T>* s;
	while (p != &L)
	{
		s = p->next;
		delete p;
		p = s;
	}
	L.next = &L;
	return true;
}

#endif // !__CDLINKLIST_H

