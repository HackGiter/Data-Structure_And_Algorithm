#pragma once

#ifndef __SLINKLIST_H
#define __SLINKLIST_H

#include <iostream>

#define INITSIZE				5

template <class T>
struct SLNode {
	T data;
	int next;
};

template <class T>
struct SLinklist {
	SLNode<T>* list;
	int length;
	int MaxSize;
};

template <class T>
void InitList(SLinklist<T>& L) {
	L.length = 0;
	L.MaxSize = INITSIZE;
	L.list = new SLNode<T>[INITSIZE + 1];
	L.list->next = -1;
	for (int i = 1; i < L.MaxSize + 1; i++) L.list[i].next = -2;
}

template <class T>
bool ListExpand(SLinklist<T>& L, int size) {
	if (L.MaxSize >= size) return false;
	SLNode<T>* tmp = new SLNode<T>[size];
	memcpy(tmp, L.list, (L.length + 1) * sizeof(SLNode<T>));
	delete[] L.list;
	L.list = tmp;
	L.MaxSize = size;
	for (int i = L.length + 1; i < L.MaxSize; i++) L.list[i].next = -2;
	return true;
}

template <class T>
int GetElem(SLinklist<T>& L, int i) {
	int index = 0;
	if (i < 0) return -1;
	while (i-- && index != -1) index = L.list[index].next;
	if (i < 0) return index;
	return -1;
}

template <class T>
int LocateElem(SLinklist<T> L, T e) {
	int index = L.list->next;
	while (index != -1)
	{
		if (L.list[index].data == e)
		{
			return index;
		}
		index = L.list[index].next;
	}
	return index;
}

template <class T>
int searchEmpty(SLinklist<T> L) {
	for (int i = 1; i < L.length + 1; i++) {
		if (L.list[i].next == -2) return i;
	}
	return -1;
}

template <class T>
bool ListInsert(SLinklist<T>& L, int i, T e) {
	int loc = 0;
	int index = GetElem(L, i - 1);
	if (index == -1) return false;
	if (++L.length == L.MaxSize) {
		ListExpand(L, L.MaxSize << 1);
		loc = L.MaxSize >> 1;
	} else {
		loc = searchEmpty(L);
	}
	L.list[loc].data = e;
	L.list[loc].next = L.list[index].next;
	L.list[index].next = loc;
	return true;
}

template <class T>
int ListDelete(SLinklist<T> L, int i) {
	int index = GetElem(L, i - 1);
	if (index == -1 || L.list[index].next == -1) return -1;
	int tmp = L.list[index].next;
	L.list[index].next = L.list[tmp].next;
	L.list[tmp].next = -2;
	L.length--;
	return tmp;
}

template <class T>
int Length(SLinklist<T> L) {
	return L.length;
}

template <class T>
void PrintList(SLinklist<T> L) {
	int index = L.list->next;
	while (index != -1)
	{
		std::cout << L.list[index].data << " ";
		index = L.list[index].next;
	}
	std::cout << std::endl;
}

template <class T>
bool IsEmpty(SLinklist<T> L) {
	if (L.length) return false;
	return true;
}

template <class T>
bool DestroyList(SLinklist<T>& L) {
	int index = 0;
	int tmp;
	while (index == -1)
	{
		tmp = L.list[index].next;
		L.list[index].next = -2;
		index = tmp;
	}
	L.list->next = -1;
	return true;
}

#endif // !__SLINKLIST_H

