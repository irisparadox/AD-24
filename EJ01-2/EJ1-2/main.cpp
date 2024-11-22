#include <iostream>
#include <fstream>

#include "TreeSet_AVL.h"

int the_case(Set<int>& _theSet, int k) {
	return _theSet.kesimo(k);
}

bool resolve_case() {
	int n;
	std::cin >> n;
	if (n == 0)
		return false;

	Set<int> _set;
	int _theN;
	for (int i = 0; i < n; i++) {
		std::cin >> _theN;
		_set.insert(_theN);
	}

	int _n_cases;
	std::cin >> _n_cases;
	int k;
	for (int i = 0; i < _n_cases; i++) {
		std::cin >> k;
		try {
			std::cout << the_case(_set, k) << '\n';
		}
		catch (InvalidKException e) {
			std::cout << "??" << '\n';
		}
	}
	std::cout << "---" << '\n';

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resolve_case());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}