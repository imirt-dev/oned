#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <vector>

using namespace std;
typedef unsigned int uint;

class DisjointSet {
private:
	vector<int> m_sets;

public:
	DisjointSet	() {}
	DisjointSet (const uint size);
	~DisjointSet() {}

	void	addElements	(const uint count);
	int		findRoot	(const uint element);
	void	setUnion	(const uint elementA, const uint elementB);
};

#endif