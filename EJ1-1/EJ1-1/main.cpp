#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "bintree.h"

template<typename T>
struct _Sol {
	bool _isAvl;
	int _ht;
	T _minV, _maxV;
};

template<typename T>
_Sol<T> is_AVL(const BinTree<T>& _myTree) {
	if (_myTree.empty())
		return {true, 0, T(), T()};
	
	_Sol<T> left  = is_AVL(_myTree.left());
	_Sol<T> right = is_AVL(_myTree.right());
	_Sol<T> sol;

	sol._ht   = 1 + std::max(left._ht, right._ht); // we get the maximum height of the current node
	sol._minV = _myTree.left().empty()  ? _myTree.root() : left._minV; // we get the minimum value
	sol._maxV = _myTree.right().empty() ? _myTree.root() : right._maxV; // we get the maximum value

	sol._isAvl = left._isAvl											 && // left is AVL
				 right._isAvl											 && // right is AVL
				 abs(left._ht - right._ht) < 2							 && // absolute value of balance factor is less or equal to 1
				 (_myTree.left().empty() || left._maxV < _myTree.root()) && // left is less than root
				 (_myTree.right().empty() || right._minV > _myTree.root()); // right is greater than root

	return sol;
}

template<typename T>
bool the_case(const BinTree<T>& _myTree) {
	_Sol<T> mySol = is_AVL(_myTree);
	return mySol._isAvl;
}

template<typename T>
BinTree<T> build_tree(std::stringstream& _sStream) {
	char c;
	_sStream >> c;

	if (c == '.') // empty node
		return BinTree<T>();

	if (c == '(') {
		BinTree<T> left = build_tree<T>(_sStream);  // left child

		T value;
		_sStream >> value;							// get value inbetween

		BinTree<T> right = build_tree<T>(_sStream); // right child

		_sStream >> c;								// should be the )

		return BinTree<T>(left, value, right);
	}
	
	return BinTree<T>();
}

bool resolve_case() {
	char type;
	std::cin >> type;

	if (!std::cin)  // fin de la entrada
		return false;

	std::string tree_description;
	std::cin.ignore();
	std::getline(std::cin, tree_description);

	std::stringstream ss(tree_description);

	bool result = false;
	if (type == 'N') {
		BinTree<int> tree = build_tree<int>(ss);
		result = the_case(tree);
	}
	else if (type == 'P') {
		BinTree<std::string> tree = build_tree<std::string>(ss);
		result = the_case(tree);
	}
	else return true;

	if (result)
		std::cout << "SI" << '\n';
	else
		std::cout << "NO" << '\n';

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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