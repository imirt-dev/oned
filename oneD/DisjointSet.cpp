#include "DisjointSet.h"

DisjointSet::DisjointSet (const uint size) {
	addElements(size);
}

void DisjointSet::addElements(const uint count) {
	for (uint i(0); i < count; ++i)
		m_sets.push_back(-1);
}

int DisjointSet::findRoot(const uint element) {
	int max, min;
	
	max = m_sets.size() - 1;
	min = 0;

	if ( (element > max) || (element < min) ) {
		return -1;
	}

	if (m_sets[element] < 0)
		return element;
	
	// Flattens the 'tree'
	m_sets[element] = findRoot(m_sets[element]);

	return m_sets[element];
}

void DisjointSet::setUnion(const uint elementA, const uint elementB) {
	int rootA, rootB;

	rootA = findRoot(elementA);
	rootB = findRoot(elementB);

	if ( (rootA == -1) || (rootB == -1) || (rootA == rootB) )
		return;

	if (m_sets[rootA] <= m_sets[rootB]) {
		m_sets[rootA] += m_sets[rootB];
		m_sets[rootB] = rootA;
	}
	else {
		m_sets[rootB] += m_sets[rootA];
		m_sets[rootA] = rootB;
	}
}
