#pragma once

#ifndef __SQBINTREE_H
#define __SQBINTREE_H

#include <iostream>

#define INITHEIGHT			(2 << 3) - 1
#define H2S(H)				(1 << H) - 1
#define LC(r)				(r << 1) + 1
#define RC(r)				(r << 1) + 2

template <class T>
struct SqBinTree {
	T* t;
	int height;
};

template <class T>
void InitTree(SqBinTree<T>& B, T tag, int h = INITHEIGHT) {
	B.height = h;
	B.t = new T[H2S(h)];
	memset(B.t, tag, sizeof(T) * H2S(h));
}

template <class T>
bool GetElem(SqBinTree<T> B, T& e, int h, int n) {
	if (B.height < h || H2S(h - 1) + 1 < n) return false;
	e = B.t[H2S(h - 1) + n];
	return true;
}

template <class T>
bool GetElem(SqBinTree<T> B, T& e, int n) {
	if (H2S(B.height) < n) return false;
	e = B.t[n];
	return true;
}

template <class T>
bool PreOrder(SqBinTree<T> B, int index, T tag) {
	if (B.height == 0) return false;
	if (B.t[index] != tag && index < H2S(B.height)) {
		std::cout << B.t[index] << " ";
		PreOrder(B, LC(index), tag);
		PreOrder(B, RC(index), tag);
		return true;
	}
	return false;
}

template <class T>
bool InOrder(SqBinTree<T> B, int index, T tag) {
	if (B.height == 0) return false;
	if (B.t[index] != tag && index < H2S(B.height)) {
		InOrder(B, LC(index), tag);
		std::cout << B.t[index] << " ";
		InOrder(B, RC(index), tag);
		return true;
	}
	return false;
}

template <class T>
bool PostOrder(SqBinTree<T> B, int index, T tag) {
	if (B.height == 0) return false;
	if (B.t[index] != tag && index < H2S(B.height)) {
		PostOrder(B, LC(index), tag);
		PostOrder(B, RC(index), tag);
		std::cout << B.t[index] << " ";
		return true;
	}
	return false;
}

template <class T> 
bool LevelOrder(SqBinTree<T> B, T tag) {
	if (B.height == 0) return false;
	for (int i = 0; i < B.height; i++) {
		int s1 = H2S(i);
		int s2 = s1 + (1 << i);
		for (int j = s1; j < s2; j++)
		{
			if (B.t[j] != tag) {
				std::cout << B.t[j] << " ";
			}
		}
	}
	std::cout << std::endl;
	return true;
}

#endif // !__SQBINTREE_H

