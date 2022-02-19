#pragma once

#ifndef __ADJAMAT_H
#define __ADJAMAT_H

#include <iostream>

#define COORD(w, x, y)		y * w + x

template <class T>
struct AdjaMatrix {
	int width, height;
	T* data;
};

template <class T>
void InitMatrix(AdjaMatrix<T>& M, int w, int h) {
	M.width = w;
	M.height = h;
	M.data = new T[w * h];
}

template <class T>
bool LocateElem(AdjaMatrix<T> M, int x, int y, T& z) {
	if (x < M.width && y < M.height) {
		memcpy(&z, &(M.data[COORD(M.width, x, y)]), sizeof(T));
		return true;
	}
	return false;
}

template <class T>
bool DestroyMatrix(AdjaMatrix<T>& M) {
	if (M.width == 0 || M.height == 0) return false;
	M.width = 0;
	M.height = 0;
	delete[] M.data;
	return true;
}

#endif // !__ADJAMAT_H

