#pragma once

#ifndef __SQQUEUE_H
#define __SQQUEUE_H

#include <iostream>

#define MAXSIZE				100

template <class T>
struct SqQueue
{
	T data[MAXSIZE];
	int front;
	int rear;
};

template <class T>
void InitQueue(SqQueue<T>& Q) {
	Q.front = 0;
	Q.rear = 0;
}

template <class T>
bool QueueEmpty(SqQueue<T> Q) {
	return Q.front == Q.rear;
}

template <class T>
bool QueueFull(SqQueue<T> Q) {
	return Q.front == (Q.rear + 1) % MAXSIZE;
}

template <class T>
bool EnQueue(SqQueue<T>& Q, T x) {
	if (QueueFull(Q)) return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return true;
}

template <class T>
bool DeQueue(SqQueue<T>& Q, T& x) {
	if (QueueEmpty(Q)) return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return true;
}

template <class T>
bool GetHead(SqQueue<T> Q, T& x) {
	if (QueueEmpty(Q)) return false;
	x = Q.data[Q.front];
	return true;
}

template <class T>
int Length(SqQueue<T> Q) {
	return (Q.rear + MAXSIZE - Q.front) % MAXSIZE;
}


#endif // !__SQQUEUE_H

