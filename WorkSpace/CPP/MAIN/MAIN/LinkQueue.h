#pragma once

#ifndef __LINKQUEUE_H
#define __LINKQUEUE_H

#include <iostream>

template <class T>
struct LinkNode {
	T data;
	struct LinkNode* next;
};

template <class T>
struct LinkQueue {
	LinkNode<T>* front, * rear;
};

template <class T>
void InitQueue(LinkQueue<T>& Q) {
	Q.front = Q.rear = new LinkNode<T>;
	Q.front->next = NULL;
}

template <class T>
bool QueueEmpty(LinkQueue<T> Q) {
	return Q.front == Q.rear;
}

template <class T>
void EnQueue(LinkQueue<T>& Q, T x) {
	LinkNode<T>* s = new LinkNode<T>;
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}

template <class T>
bool DeQueue(LinkQueue<T>& Q, LinkNode<T>& x) {
	if (QueueEmpty(Q)) return false;
	memcpy(&x, Q.front->next, sizeof(LinkNode<T>));
	Q.front->next = x.next;
	if (Q.front->next == NULL) Q.rear = Q.front;
	return true;
}

template <class T>
bool GetHead(LinkQueue<T> Q, LinkNode<T>& x) {
	if (QueueEmpty(Q)) return false;
	memcpy(&x, Q.front->next, sizeof(LinkNode<T>));
	return true;
}

template <class T>
int Length(LinkQueue<T> Q) {
	int length = 0;
	LinkNode<T>* tmp = Q.front->next;
	while (tmp) {
		tmp = tmp->next;
		length++;
	};
	return length;
}

#endif // !__LINKQUEUE_H

