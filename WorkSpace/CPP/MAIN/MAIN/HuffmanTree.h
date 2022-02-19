#pragma once

#ifndef __HUFFMANTREE_H
#define __HUFFMANTREE_H

#include <iostream>
#include <vector>
#include <algorithm>

template <class F, class V, class C>
struct HuffmanNode
{
	F _freq;
	V _value;
	C _code;
	struct HuffmanNode<F, V, C>* _parent, * _left, * _right;

	HuffmanNode(const F& freq = F(), const V& value = V(), const C& code = C()) :
		_freq(freq),
		_value(value),
		_code(code),
		_parent(NULL),
		_left(NULL),
		_right(NULL)
	{}
	
	HuffmanNode<F, V, C>& operator = (const HuffmanNode<F, V, C>& other) {
		if (this != &other) {
			this->_freq = other._freq;
			this->_value = other._value;
			this->_code = other._code;
			this->_parent = other._parent;
			this->_left = other._left;
			this->_right = other._right;
		}
		return (*this);
	}
	bool operator < (const HuffmanNode<F, V, C>& other) const { return _freq < other._freq; }
	bool operator > (const HuffmanNode<F, V, C>& other) const { return _freq > other._freq; }
	bool operator == (const HuffmanNode<F, V, C>& other) const { return _freq == other._freq; }
};

template <class F, class V, class C>
class HuffmanTree
{
public:
	HuffmanTree() :_root(NULL) {}
	~HuffmanTree();

	void BuildTree(const F freq[], const V value[], const C& lcode, const C& rcode, const int& n) { _Build(freq, value, lcode, rcode, n); }
	C* SearchCode(const V& value) { return _Search(_root, value); }

protected:
	HuffmanNode<F, V, C>* _root;

	void _Build(const F freq[], const V value[], const C& lcode, const C& rcode, const int& n);
	C* _Search(const HuffmanNode<F, V, C>* root, const V& value);

private:

};

template <class F, class V, class C>
HuffmanTree<F, V, C>::~HuffmanTree()
{
}

template<class F, class V, class C>
inline void HuffmanTree<F, V, C>::_Build(const F freq[], const V value[], const C& lcode, const C& rcode, const int& n)
{
	std::vector<HuffmanNode<F, V, C>> vec;
	HuffmanNode<F, V, C>* tmp, * left, *right;
	
	for (int i = 0; i < n; i++)
	{
		tmp = new HuffmanNode<F, V, C>(freq[i], value[i]);
		vec.push_back(*tmp);
		delete tmp;
	}

	std::make_heap(vec.begin(), vec.end(), std::greater<HuffmanNode<F,V, C>>());
	while (vec.size() > 1)
	{
		left = new HuffmanNode<F, V, C>();
		*left = vec.front();
		left->_code = lcode;
		std::pop_heap(vec.begin(), vec.end(), std::greater<HuffmanNode<F, V, C>>());
		vec.pop_back();

		right = new HuffmanNode<F, V, C>();
		*right = vec.front();
		right->_code = rcode;
		std::pop_heap(vec.begin(), vec.end(), std::greater<HuffmanNode<F, V, C>>());
		vec.pop_back();

		tmp = new HuffmanNode<F, V, C>(left->_freq + right->_freq);
		tmp->_left = left;
		tmp->_right = right;
		vec.push_back(*tmp);
		std::push_heap(vec.begin(), vec.end(), std::greater<HuffmanNode<F, V, C>>());
		delete tmp;
	}
	
	_root = new HuffmanNode<F, V, C>();
	*_root = vec.front();
	vec.pop_back();
}

template<class F, class V, class C>
inline C* HuffmanTree<F, V, C>::_Search(const HuffmanNode<F, V, C>* root, const V& value)
{
	if (root == NULL) return NULL;

	C* left, * right;
	left = _Search(root->_left, value);
	right = _Search(root->_right, value);

	if (left == NULL && right == NULL) {
		if (root->_value == value) return new C(root->_code);
	}
	else {
		C* tmp = new C(root->_code);
		if (left == NULL) {
			*tmp += *right;
			delete right;
		}
		else {
			*tmp += *left;
			delete left;
		}
		
		return tmp;
	}

	return NULL;
}

#endif // !__HUFFMANTREE_H
