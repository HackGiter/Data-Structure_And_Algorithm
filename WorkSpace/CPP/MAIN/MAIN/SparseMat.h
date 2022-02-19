#pragma once

#ifndef __SPARSEMAT_H
#define __SPARSEMAT_H

#include <iostream>

template <class T>
struct Triplet {
	int x, y;
	T elem;
};

template <class T>
struct SparseMatrix {
	int width, height, size;
	Triplet<T>* data;
};

template <class T>
void InitMatrix(SparseMatrix<T>& M, int w, int h, int s) {
	M.width = w;
	M.height = h;
	M.size = s;
	M.data = new Triplet<T>[M.size];
}

template <class T>
bool LocateElem(SparseMatrix<T> M, int x, int y, Triplet<T>& e) {
	if (M.width * M.height == 0) return false;
	for (int i = 0; i < M.size; i++)
	{
		if (M.data[i].x == x && M.data[i].y == y) {
			memcpy(&e, M.data[i], sizeof(Triplet<T>));
			return true;
		}
	}
	return false;
}

template <class T>
bool DestroyMatrix(SparseMatrix<T>& M) {
	if (M.size == 0) return false;
	delete[] M.data;
	M.size = 0;
	return true;

}

#endif // !__SPARSEMAT_H

