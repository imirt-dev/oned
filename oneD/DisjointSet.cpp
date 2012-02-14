#include "DisjointSet.h"

DisjointSet::DisjointSet (const u_int size) {
	addElements(size);
}

void DisjointSet::addElements(const u_int count) {
	for (u_int i(0); i < count; ++i)
		m_sets.push_back(-1);
}

int DisjointSet::findRoot(const u_int element) {
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

void DisjointSet::setUnion(const u_int elementA, const u_int elementB) {
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
