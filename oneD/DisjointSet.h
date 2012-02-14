#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <vector>

using namespace std;
typedef unsigned int u_int;

class DisjointSet {
private:
	vector<int> m_sets;

public:
	DisjointSet	() {}
	DisjointSet (const u_int size);
	~DisjointSet() {}

	void	addElements	(const u_int count);
	int		findRoot	(const u_int element);
	void	setUnion	(const u_int elementA, const u_int elementB);
};

#endif