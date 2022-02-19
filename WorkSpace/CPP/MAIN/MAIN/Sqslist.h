#pragma once

#ifndef __SQSLIST_H
#define __SQSLIST_H

#include <iostream>
#define MAXSIZE             100

template <class T>
struct Sqslist
{
    T data[MAXSIZE];
    int length;
};

template <class T>
void InitList(Sqslist<T>& L) {
    L.length = 0;
}

template <class T>
int Length(Sqslist<T> L) {
    return L.length;
}

template <class T>
int LocateElem(Sqslist<T> L, T e) {
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e) return i;
	}
	return -1;
}

template <class T>
T GetElem(Sqslist<T> L, int i) {
	if (L.length <= i || i < 0) throw "Out of List Bound\n";
	return L.data[i];
}

template <class T>
bool ListInsert(Sqslist<T>& L, int i, T e) {
	T tmp;

	if (MAXSIZE <= i || i < 0) return false;
	if (L.length < MAXSIZE) L.length++;
	for (int j = i; j < L.length; j++)
	{
		tmp = L.data[j];
		L.data[j] = e;
		e = tmp;
	}
	return true;
}

template <class T>
bool ListDelete(Sqslist<T>& L, int i, T& e) {
	if (L.length <= i || i < 0) return false;
	L.length--;
	e = L.data[i];
	for (int j = i; j < L.length; j++) L.data[j] = L.data[j + 1];
	return true;
}

template <class T>
void PrintList(Sqslist<T> L) {
	for (int i = 0; i < L.length; i++)
	{
		std::cout << L.data[i] << " ";
	}
	std::cout << std::endl;
}

template <class T>
bool IsEmpty(Sqslist<T> L) {
	if (L.length == 0) return true;
	return false;
}

template <class T>
bool DestroyList(Sqslist<T>& L) {
	L.length = 0;
	return true;
}


#endif // !__SQSLIST_H

