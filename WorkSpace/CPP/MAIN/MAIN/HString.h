#pragma once

#ifndef __HSTRING_H
#define __HSTRING_H

#include <iostream>

#define INITLENGTH			10

struct HString{
	char* ch;
	int length;
	int MAXLEN;
};

void InitString(HString& T, int len = INITLENGTH) {
	T.MAXLEN = len;
	T.length = 0;
	T.ch = new char[T.MAXLEN];
}

bool StringExpand(HString& T, int len) {
	if (len < T.length) return false;
	char* s = new char[len];
	memcpy(s, T.ch, sizeof(char) * T.length);
	delete[] T.ch;
	T.ch = s;
	T.MAXLEN = len;
	return true;
}

void ReadString(HString& T) {
	char c;
	int index = 0;
	if (T.MAXLEN == 0) InitString(T);
	while ((c = std::cin.get()) != EOF && c != '\n')
	{
		T.ch[index++] = c;
		T.length++;
		if (index == T.MAXLEN) StringExpand(T, T.MAXLEN * 2);
	}
	T.ch[index] = '\0';
}

bool StrAssign(HString& T, char* s) {
	if (!T.length) return false;
	memcpy(s, T.ch, sizeof(char) * T.length);
	return true;
}

bool StrCopy(HString& T, HString S) {
	if (!S.length) return false;
	if (T.length < S.length) StringExpand(T, S.length);
	memcpy(T.ch, S.ch, sizeof(char) * S.length);
	return true;
}

bool StrEmpty(HString T) {
	if (T.length) return false;
	return true;
}

int StrCompare(HString S, HString T) {
	if (S.length > T.length) return 1;
	if (S.length == T.length) return 0;
	return -1;
}

int StrLength(HString S) {
	return S.length;
}

bool SubString(HString& Sub, HString S, int pos, int len) {
	if (pos < 0 || len < 0) return false;
	if (S.length < pos + len) return false;
	if (Sub.length < len) StringExpand(Sub, len);
	memcpy(Sub.ch, (S.ch + pos), sizeof(char) * len);
	return true;
}

void Concat(HString& T, HString S1, HString S2) {
	if (T.length < S1.length + S2.length) StringExpand(T, S1.length + S2.length);
	memcpy(T.ch, S1.ch, sizeof(char) * S1.length);
	memcpy((T.ch + S1.length), S2.ch, sizeof(char) * S2.length);
}

void get_next(HString T, int* next) {
	int i = 1, j = 0;
	next[1] = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[i-1] == T.ch[j-1]) {
			++i; ++j;
			next[i] = j;
		}
		else j = next[j];
	}
}

void get_nextval(HString T, int* nextval) {
	int i = 1, j = 0;
	nextval[1] = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[i-1] == T.ch[j-1]) {
			++i; ++j;
			if (T.ch[i-1] != T.ch[j-1]) nextval[i] = j;
			else nextval[i] = nextval[j];
		}
		else j = nextval[j];
	}
}

int IndexKMP(HString S, HString T) {
	if (S.length < T.length) return 0;
	int* next = new int[T.length + 1];
	//get_next(T, next);
	get_nextval(T, next);
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length) 
	{
		if (j == 0 || S.ch[i-1] == T.ch[j-1]) {
			++i; ++j;
		}
		else j = next[j];
	}
	if (j > T.length) return i - T.length;
	else return 0;

}

bool ClearString(HString& S) {
	if (!S.length) return false;
	memset(S.ch, 0, sizeof(char) * S.length);
	return true;
}

bool DestroyString(HString& S) {
	if (!S.MAXLEN) return false;
	S.length = 0;
	S.MAXLEN = 0;
	delete[] S.ch;
	return true;
}

#endif // !__HSTRING_H

