#pragma once

#ifndef __SORT_HEAP_H
#define __SORT_HEAP_H

template <class T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <class T, class F>
void make_heap(T* top, int size, F(*COMP)) {
	int index;
	for (int i = size; i > 1; i++)
	{
		index = i / 2 - 1;
		if (COMP(top[index], top[i - 1])) swap(top[index], top[i - 1]);
	}
}

template <class T, class F>
void shiftDown(T* top, int n, F(*COMP)) {
	int index = 1;
	while (index < n)
	{
		if (COMP(top[index * 2], top[index * 2 + 1])) {
			if (COMP(top[index * 2], top[index - 1])) {
				swap(top[index * 2], top[index - 1]);
				index = index * 2;
			}
			break;
		}
		else {
			if (COMP(top[index * 2 + 1], top[index - 1])) {
				swap(top[index * 2 + 1], top[index - 1]);
				index = index * 2 + 1;
			}
			break;
		}

	}
}

template <class T, class F>
void push_heap(T* top, int n, F(*COMP)) {
	int index = n;
	while (index != 1)
	{
		if (COMP(top[index - 1], top[index / 2])) {
			swap(top[index - 1], top[index / 2]);
			index = index / 2 + 1;
		}
		else break;

	}
}

template <class T, class F>
void pop_heap(T* top, int n, F(*COMP)) {
	swap(top[0], top[n - 1]);
	shiftDown(top, n - 1, COMP);
}



#endif // !__SORT_HEAP_H

