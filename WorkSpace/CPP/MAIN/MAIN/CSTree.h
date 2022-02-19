#pragma once

#ifndef __CSTREE_H
#define __CSTREE_H

template <class T>
struct CSNode {
	T data;
	struct CSNode<T>* firstchild, * nextsibling;
};

template <class T>
struct CSTree :CSNode<T> {

};

#endif // !__CSTREE_H

