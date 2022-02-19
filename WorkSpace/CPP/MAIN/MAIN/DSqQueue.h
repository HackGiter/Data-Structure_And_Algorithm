#pragma once

#ifndef __DSQQUEUE_H
#define __DSQQUEUE_H

#include <iostream>

#define MAXSIZE				10

struct Mode {
	int fin, fout, rin, rout;
};

template <class T>
struct DSqQueue
{
	T data[MAXSIZE];
	struct Mode m;
	int front, rear;
};

template <class T>
void InitQueue(DSqQueue<T>& Q) {
	Q.m.fin = Q.m.fout = Q.m.rin = Q.m.rout = 1;
	Q.front = Q.rear = 0;
}

template <class T>
void InitQueue(DSqQueue<T>& Q, Mode m) {
	memcpy(&(Q.m), &m, sizeof(Mode));
	Q.front = Q.rear = 0;
}

template <class T>
bool QueueEmpty(DSqQueue<T> Q) {
	return Q.front == Q.rear;
}

template <class T>
bool QueueFull(DSqQueue<T> Q) {
	return Q.front == (Q.rear + 1) % MAXSIZE;
}

template <class T>
bool EnQueue(DSqQueue<T>& Q, T x, int in) {
	if (QueueFull(Q)) return false;
	if (in && Q.m.fin) {
		Q.data[Q.rear] = x;
		Q.rear = (Q.rear + 1) % MAXSIZE;
	} else if (in == 0 && Q.m.rin) {
		Q.front = (Q.front - 1 + MAXSIZE) % MAXSIZE;
		Q.data[Q.front] = x;
	}
	
	return true;
}

template <class T>
bool DeQueue(DSqQueue<T>& Q, T& x, int out) {
	if (QueueEmpty(Q)) return false;
	if (out && Q.m.rout) {
		x = Q.data[Q.front];
		Q.front = (Q.front + 1) % MAXSIZE;
	} else if (out == 0 && Q.m.fout) {
		Q.rear = (Q.rear - 1 + MAXSIZE) % MAXSIZE;
		x = Q.data[Q.rear];
	}
	return true;
}

template <class T>
bool GetHead(DSqQueue<T> Q, T& x) {
	if (QueueEmpty(Q)) return false;
	x = Q.data[Q.front];
	return true;
}

template <class T>
int Length(DSqQueue<T> Q) {
	return (Q.rear + MAXSIZE - Q.front) % MAXSIZE;
}

#endif // !__DSQQUEUE_H

