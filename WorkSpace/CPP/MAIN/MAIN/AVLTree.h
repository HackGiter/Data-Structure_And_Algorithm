#pragma once

#ifndef __AVLTREE_H
#define __AVLTREE_H

#include <iostream>

#include "MathFunc.h"
#include "Queue.h"

// AVLTree Balance Binary Tree

template <class K, class V>
struct AVLTreeNode {
	K _key;
	V _value;
	int _bf;
	AVLTreeNode<K, V>* _parent;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;

	AVLTreeNode(const K& key = K(), const V& value = V()) :
		_key(key),
		_value(value),
		_bf(0),
		_parent(NULL),
		_left(NULL),
		_right(NULL)
	{}
};

template <class K, class V>
class AVLTree
{
public:
	AVLTree() : _root(NULL) {}
	~AVLTree();
	
	int Height() { return _Height(_root); }
	bool IsBalance() { return _IsBalance(_root) != -1; }
	void Insert(const K& key, const V& value);
	AVLTreeNode<K, V>* Find(const K& key) { return _Find(key, _root); }
	void PreOrder() { _PreOrder(_root); std::cout << std::endl; }
	void InOrder() { _InOrder(_root); std::cout << std::endl; }
	void PostOrder() { _PostOrder(_root); std::cout << std::endl; }
	void LevelOrder() { _LevelOrder(_root); std::cout << std::endl; }
	void DFSearch() { _DepthFirstSearch(_root); std::cout << std::endl; }
	void BFSearch() { _BreadthFirstSearch(_root); std::cout << std::endl; }

protected:
	AVLTreeNode<K, V>* _root;

	int _Height(AVLTreeNode<K, V>* root);
	int _IsBalance(AVLTreeNode<K, V>* root);
	void _PreOrder(AVLTreeNode<K, V>* root);
	void _InOrder(AVLTreeNode<K, V>* root);
	void _PostOrder(AVLTreeNode<K, V>* root);
	void _LevelOrder(AVLTreeNode<K, V>* root);
	void _DepthFirstSearch(AVLTreeNode<K, V>* root);
	void _BreadthFirstSearch(AVLTreeNode<K, V>* root);
	void _RotateLL(AVLTreeNode<K, V>* parent);
	void _RotateRR(AVLTreeNode<K, V>* parent);
	void _RotateLR(AVLTreeNode<K, V>* parent);
	void _RotateRL(AVLTreeNode<K, V>* parent);
	AVLTreeNode<K, V>* _Find(const K& key, AVLTreeNode<K, V>* root);

private:

};

template <class K, class V>
AVLTree<K, V>::~AVLTree()
{
}

template<class K, class V>
inline void AVLTree<K, V>::Insert(const K& key, const V& value)
{
	if (_root == NULL) {
		_root = new AVLTreeNode<K, V>(key, value);
		return;
	}

	AVLTreeNode<K, V>* anc = _root;
	AVLTreeNode<K, V>* par = NULL;
	
	/* INSERT */
	while (anc)
	{
		par = anc;
		if (anc->_key < key) anc = anc->_right;
		else if (anc->_key > key) anc = anc->_left;
		else return;
	}
	anc = new AVLTreeNode<K, V>(key, value);
	anc->_parent = par;
	if (par->_key < key) par->_right = anc;
	else par->_left = anc;

	/* REBALANCE */
	while (par)
	{
		/* RENEW BALANCE FACTOR */
		if (anc == par->_right) par->_bf--;
		else par->_bf++;

		/* VARIFY LEGITIMACY */
		if (par->_bf == 0) break;
		if (par->_bf == -1 || par->_bf == 1) {
			anc = par;
			par = anc->_parent;
		}
		else {
			if (par->_bf == -2) {
				if (par->_right->_bf == -1) 
					_RotateRR(par);
				else 
					_RotateRL(par);
			}
			else {
				if (par->_left->_bf == 1)
					_RotateLL(par);
				else
					_RotateLR(par);
			}
			break;
		}
	}

}

#endif // !__AVLTREE_H

template<class K, class V>
inline int AVLTree<K, V>::_Height(AVLTreeNode<K, V>* root)
{
	if (root == NULL) return 0;

	int left = _Height(root->_left);
	int right = _Height(root->_right);

	if (left > right) return left + 1;
	return right + 1;
}

template<class K, class V>
inline int AVLTree<K, V>::_IsBalance(AVLTreeNode<K, V>* root)
{
	if (root == NULL) return 0;
	
	int left = _IsBalance(root->_left);
	int right = _IsBalance(root->_right);

	if (left < 0 || right < 0) return -1;
	if (_abs(left - right) >= 2) return -1;
	return left > right ? left + 1 : right + 1;
}

template<class K, class V>
inline void AVLTree<K, V>::_PreOrder(AVLTreeNode<K, V>* root)
{
	if (root == NULL) return;
	std::cout << root->_value << " ";
	_PreOrder(root->_left);
	_PreOrder(root->_right);
}

template<class K, class V>
inline void AVLTree<K, V>::_InOrder(AVLTreeNode<K, V>* root)
{
	if (root == NULL) return;
	_InOrder(root->_left);
	std::cout << root->_value << " ";
	_InOrder(root->_right);
}

template<class K, class V>
inline void AVLTree<K, V>::_PostOrder(AVLTreeNode<K, V>* root)
{
	if (root == NULL) return;
	_PostOrder(root->_left);
	_PostOrder(root->_right);
	std::cout << root->_value << " ";
}

template<class K, class V>
inline void AVLTree<K, V>::_LevelOrder(AVLTreeNode<K, V>* root)
{
	Queue<AVLTreeNode<K, V>*> Q;
	QueueNode<AVLTreeNode<K, V>*>* anc;

	Q.EnQueue(root);
	while (!Q.IsEmpty())
	{
		anc = Q.DeQueue();
		if (anc->_data != NULL) {
			std::cout << anc->_data->_value << " ";
			Q.EnQueue(anc->_data->_left);
			Q.EnQueue(anc->_data->_right);
		}
	}
}

template<class K, class V>
inline void AVLTree<K, V>::_DepthFirstSearch(AVLTreeNode<K, V>* root)
{
	_PreOrder(root);
}

template<class K, class V>
inline void AVLTree<K, V>::_BreadthFirstSearch(AVLTreeNode<K, V>* root)
{
	_LevelOrder(root);
}

template<class K, class V>
inline void AVLTree<K, V>::_RotateLL(AVLTreeNode<K, V>* parent)
{
	AVLTreeNode<K, V>* subLN = parent->_left;
	AVLTreeNode<K, V>* prePN = parent->_parent;
	AVLTreeNode<K, V>* subLR = subLN->_right;
	
	parent->_left = subLR;
	if (subLR) subLR->_parent = parent;
	subLN->_right = parent;
	subLN->_parent = prePN;
	parent->_parent = subLN;
	if (prePN) {
		if (prePN->_left == parent) prePN->_left = subLN;
		else prePN->_right = subLN;
	}
	else _root = subLN;
	parent->_bf -= 1;
	parent->_bf -= subLN->_bf > 0 ? 1 : 0;
	subLN->_bf -= 1;
	parent->_bf -= subLN->_bf > 0 ? 1 : 0;
	subLN->_bf -= parent->_bf < 0 ? 1 : 0;
	parent = subLN;
}

template<class K, class V>
inline void AVLTree<K, V>::_RotateRR(AVLTreeNode<K, V>* parent)
{
	AVLTreeNode<K, V>* subRN = parent->_right;
	AVLTreeNode<K, V>* prePN = parent->_parent;
	AVLTreeNode<K, V>* subRL = subRN->_left;

	parent->_right = subRL;
	if (subRL) subRL->_parent = parent;
	subRN->_left = parent;
	subRN->_parent = prePN;
	parent->_parent = subRN;
	if (prePN) {
		if (prePN->_left == parent) prePN->_left = subRN;
		else prePN->_right = subRN;
	}
	else _root = subRN;
	parent->_bf += 1;
	parent->_bf += subRN->_bf < 0 ? 1 : 0;
	subRN->_bf += 1;
	parent->_bf += subRN->_bf < 0 ? 1 : 0;
	subRN->_bf += parent->_bf > 0 ? 1 : 0;
	parent = subRN;
}

template<class K, class V>
inline void AVLTree<K, V>::_RotateLR(AVLTreeNode<K, V>* parent)
{
	_RotateRR(parent->_left);
	_RotateLL(parent);
}

template<class K, class V>
inline void AVLTree<K, V>::_RotateRL(AVLTreeNode<K, V>* parent)
{
	_RotateLL(parent->_right);
	_RotateRR(parent);
}

template<class K, class V>
inline AVLTreeNode<K, V>* AVLTree<K, V>::_Find(const K& key, AVLTreeNode<K, V>* root)
{
	if (root == NULL) return NULL;
	if (root->_key == key) return root;
	if (root->_key < key) return _Find(key, root->_right);
	return _Find(key, root->_left);
}


