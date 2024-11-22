#include <iostream>
#include <fstream>
#include <queue>

struct checkout {
	int _time, _num;
	checkout(int _t, int _n) : _time(_t), _num(_n) {};
};

bool operator<(const checkout& _c1, const checkout& _c2) {
	return _c2._time <  _c1._time ||
		  (_c2._time == _c1._time &&
		   _c2._num  <  _c1._num);
}

bool resolve_case() {
	int n, c;
	std::cin >> n >> c;
	if (n == 0)
		return false;

	std::priority_queue<checkout> the_queue;

	for (int i = 0; i < n; i++) {
		the_queue.push({ 0, i + 1 });
	}

	for (int i = 0; i < c; i++) {
		int cli;
		std::cin >> cli;
		checkout free = the_queue.top();
		the_queue.pop();
		free._time += cli;
		the_queue.push(free);
	}

	std::cout << the_queue.top()._num << '\n';

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