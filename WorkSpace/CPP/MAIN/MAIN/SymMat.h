#pragma once

#ifndef __SYMMAT_H
#define __SYMMAT_H


#include <iostream>

#define COORD(x, y)		x * (x - 1) / 2 + y - 1

template <class T>
struct SymMatrix {
	int wh;
	T* data;
};

template <class T>
void InitMatrix(SymMatrix<T>& M, int wh) {
	M.wh = wh;
	M.data = new T[wh * (wh + 1) / 2];
}

template <class T>
bool LocateElem(SymMatrix<T> M, int x, int y, T& z) {
	if (x < M.wh && y < M.wh) {
		if (x >= y) {
			memcpy(&z, &(M.data[COORD(x, y)]), sizeof(T));
		}
		else {
			memcpy(&z, &(M.data[COORD(y, x)]), sizeof(T));
		}
		
		return true;
	}
	return false;
}

template <class T>
bool DestroyMatrix(SymMatrix<T>& M) {
	if (M.wh == 0) return false;
	M.wh = 0;
	delete[] M.data;
	return true;
}


#endif // !__SYMMAT_H

