#pragma once

#ifndef __ADJLIST_H
#define __ADJLIST_H

#include <iostream>

template <class E>
struct ENode {
	int adjvex;
	E info;
	struct ENode* next;
};

template <class V, class E>
struct VNode {
	V data;
	ENode<E>* first;
};

template <class V, class E>
struct AdjList {
	VNode<V, E>* vertices;
	int vexnum, arcnum;
};



#endif // !__ADJLIST_H

