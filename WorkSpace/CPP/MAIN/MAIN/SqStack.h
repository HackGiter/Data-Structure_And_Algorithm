#pragma once

#ifndef __SQSTACK_H

#include <iostream>

#define INITSIZE			5

template <class T>
struct SqStack
{
	T* data;
	int top;
	int size;
};

template <class T>
void InitStack(SqStack<T>& S) {
	S.top = -1;
	S.size = INITSIZE;
	S.data = new T[S.size];
}

template <class T>
bool StackEmpty(SqStack<T> S) {
	if (S.top == -1) return false;
	return true;
}

template <class T>
bool StackExpand(SqStack<T>& S, int size) {
	if (S.size >= size) return false;
	S.size = size;
	T* tmp = new T[S.size];
	memcpy(tmp, S.data, (S.top + 1) * sizeof(T));
	delete[] S.data;
	S.data = tmp;
	return true;
}

template <class T>
void Push(SqStack<T>& S, T x) {
	if (S.top == S.size - 1) {
		StackExpand(S, S.size << 2);
	}
	S.data[++S.top] = x;
}

template <class T>
bool Pop(SqStack<T>& S, T& x) {
	if (S.top == -1) return false;
	x = S.data[S.top--];
	return true;
}

template <class T>
void GetTop(SqStack<T>S, T& x) {
	x = S.data[S.top];
}

template <class T>
bool DestroyStack(SqStack<T>& S) {
	if (S.size == 0) return false;
	S.size = 0;
	S.top = -1;
	delete[] S.data;
	return true;
}

#endif // !__SQSTACK_H

