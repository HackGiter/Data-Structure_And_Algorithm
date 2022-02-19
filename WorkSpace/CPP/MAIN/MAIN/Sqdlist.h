#pragma once

#ifndef __SQDLIST_H
#define __SQDLIST_H

#include <iostream>

#define INITSIZE            10

template <class T>
struct Sqdlist
{
    T* data;
    int MaxSize, length;
};

template <class T>
void InitList(Sqdlist<T>& L) {
	L.data = new T[INITSIZE];
	L.length = 0;
	L.MaxSize = INITSIZE;
}

template <class T>
int Length(Sqdlist<T> L) {
	return L.length;
}

template <class T>
int LocateElem(Sqdlist<T> L, T e) {
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e) return i;
	}
	return -1;
}

template <class T>
T GetElem(Sqdlist<T> L, int i) {
	if (L.length <= i) throw "Out of List Bound\n";
	return L.data[i];
}

template <class T>
bool ListInsert(Sqdlist<T>& L, int i, T e) {
	T tmp;

	if (L.length < i) return false;
	L.data[L.length++] = 0;
	for (int j = i; j < L.length; j++)
	{
		tmp = L.data[j];
		L.data[j] = e;
		e = tmp;
	}
	if (L.length == L.MaxSize)
	{
		L.MaxSize *= 2;
		T* cp = new T[L.MaxSize];
		memcpy(cp, L.data, sizeof(T) * L.length);
		delete L.data;
		L.data = cp;
	}
	return true;
}

template <class T>
bool ListDelete(Sqdlist<T>& L, int i, T& e) {
	if (L.length <= i) return false;
	L.length--;
	e = L.data[i];
	for (int j = i; j < L.length; j++) L.data[j] = L.data[j + 1];
	return true;
}

template <class T>
void PrintList(Sqdlist<T> L) {
	for (int i = 0; i < L.length; i++)
	{
		std::cout << L.data[i] << " ";
	}
	std::cout << std::endl;
}

template <class T>
bool IsEmpty(Sqdlist<T> L) {
	if (L.length == 0) return true;
	return false;
}

template <class T>
bool DestroyList(Sqdlist<T>& L) {
	L.length = 0;
	L.MaxSize = 0;
	delete	L.data;
	return true;
}

#endif // !__SQDLIST_H



