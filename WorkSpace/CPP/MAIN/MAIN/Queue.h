#pragma once

#ifndef __QUEUE_H
#define __QUEUE_H

#include <iostream>

template <class T>
struct QueueNode {
	T _data;
	struct QueueNode<T>* _next;

	QueueNode(const T& data = T()) :
		_data(data),
		_next(NULL)
	{}
};

template <class T>
class Queue
{
public:
	Queue() :_front(NULL), _rear(NULL) {};
	~Queue();

	void EnQueue(const T& data) { _EnQueue(_rear, data); }
	QueueNode<T>* DeQueue() { return _DeQueue(_front); }
	int Length() { return _Length(_front); }
	bool IsEmpty() { return _IsEmpty(_front); }

protected:
	QueueNode<T>* _front;
	QueueNode<T>* _rear;

	void _EnQueue(QueueNode<T>*& rear, T data);
	QueueNode<T>* _DeQueue(QueueNode<T>*& front);
	int _Length(QueueNode<T>* front);
	bool _IsEmpty(const QueueNode<T>* front);

private:

};

template <class T>
Queue<T>::~Queue() {

}

template<class T>
inline void Queue<T>::_EnQueue(QueueNode<T>*& rear, T data)
{
	if (rear == NULL) {
		rear = new QueueNode<T>(data);
		_front = rear;
		return;
	}
	QueueNode<T>* node = new QueueNode<T>(data);
	rear->_next = node;
	rear = node;
}

template<class T>
inline QueueNode<T>* Queue<T>::_DeQueue(QueueNode<T>*& front)
{
	if (front == NULL) return NULL;
	QueueNode<T>* node = front;
	front = front->_next;
	if (front == NULL) _rear = front;
	return node;
}

template<class T>
inline int Queue<T>::_Length(QueueNode<T>* front)
{
	int len = 0;

	while (front)
	{
		front = front->_next;
		len++;
	}
	return len;
}

template<class T>
inline bool Queue<T>::_IsEmpty(const QueueNode<T>* front)
{
	if (front) return false;
	return true;
}

#endif // !__QUEUE_H

