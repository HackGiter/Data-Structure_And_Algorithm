#pragma once

#ifndef __ORTHLIST_H
#define __ORTHLIST_H

#include <iostream>

template <class E>
struct ArcNode {
	E _info;
	int _tailvex, _headvex;
	struct ArcNode<E>* _hlink, * _tlink;
	
	ArcNode(const E& info = E(), const int& headvex = int(), const int& tailvex = int()) :
		_info(info),
		_tailvex(tailvex),
		_headvex(headvex),
		_hlink(NULL),
		_tlink(NULL)
	{}
};

template <class V, class E>
struct VexNode
{
	V _data;
	ArcNode<E>* _firstin, * _firstout;

	VexNode(const V& data = V()) :
		_data(data),
		_firstin(NULL),
		_firstout(NULL)
	{}
};

template <class V, class E>
class OrthList
{
public:
	OrthList() :_vexnum(0), _arcnum(0), _vertexs(NULL) {}
	~OrthList() {}

	int vexnum() { return _vexnum; };
	int arcnum() { return _arcnum; };
	void build(const V* data, const E* info, 
		const int* tailvex, const int* headvex, 
		const int& vexnum, const int& arcnum) 
	{ _BuildGraph(data, info, tailvex, headvex, vexnum, arcnum); }
	
	void print() { _PrintGraph(); }

protected:
	int _vexnum, _arcnum;
	VexNode<V, E>* _vertexs;

	void _BuildGraph(const V* data, const E* info, const int* tailvex, const int* headvex, const int& vexnum, const int& arcnum);
	void _PrintGraph();

private:

};



#endif // !__ORTHLIST_H

template <class V, class E>
inline void OrthList<V, E>::_BuildGraph(const V* data, const E* info, const int* tailvex, const int* headvex, const int& vexnum, const int& arcnum)
{
	_vexnum = vexnum;
	_arcnum = arcnum;
	
	_vertexs = new VexNode<V, E>[vexnum];
	ArcNode<E>* arc, * tmp;
	int head, tail;

	/* FILL DATA IN */
	for (int i = 0; i < _vexnum; i++) _vertexs[i]._data = data[i];

	/* CONNECT EACH VEXNODE AND ARCNODE */
	for (int i = 0; i < _arcnum; i++)
	{
		head = headvex[i]; tail = tailvex[i];
		arc = new ArcNode<E>(info[i], head, tail);
		if (_vertexs[head]._firstout == NULL) _vertexs[head]._firstout = arc;
		else {
			tmp = _vertexs[head]._firstout;
			while (tmp->_hlink) tmp = tmp->_hlink;
			tmp->_hlink = arc;
		}
		if (_vertexs[tail]._firstin == NULL) _vertexs[tail]._firstin = arc;
	}

	/* CONNECT EACH ARCNODE AND ARCNODE */
	for (int i = 0; i < _vexnum; i++)
	{
		arc = _vertexs[i]._firstout;
		if (arc)
		{
			tail = arc->_tailvex;
			for (int j = i; j < _vexnum; j++)
			{
				tmp = _vertexs[j]._firstout;
				if (tmp) {
					while (tmp) {
						if (tmp->_tailvex == tail) break;
						tmp = tmp->_hlink;
					}
					if (tmp) {
						arc->_tlink = tmp;
						break;
					}
				}
			}
		}
	}

}

template <class V, class E>
inline void OrthList<V, E>::_PrintGraph() {
	ArcNode<E>* arc;

	if (_vertexs) {
		for (int i = 0; i < _vexnum; i++)
		{
			std::cout << _vertexs[i]._data << ":";
			arc = _vertexs[i]._firstout;
			while (arc)
			{
				std::cout << arc->_info << " " << arc->_tailvex << ";";
				arc = arc->_hlink;
			}
			std::cout << std::endl;
		}
	}

}