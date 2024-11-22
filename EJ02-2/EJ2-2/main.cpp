#include <iostream>
#include <fstream>
#include <queue>

struct _Registry {
	int _time;
	int _id;
	int _period;
};

bool operator<(const _Registry& _l, const _Registry& _r) {
	return _r._time < _l._time || (_l._time == _r._time && _r._id < _l._id);
}

bool resolve_case() {
	int N;
	std::cin >> N;

	if (N == 0) return false;

	std::priority_queue<_Registry> _queue;
	for (int i = 0; i < N; i++) {
		int id_user, period;
		std::cin >> id_user >> period;
		_queue.push({ period, id_user, period });
	}

	int shipments;
	std::cin >> shipments;

	while (shipments--) {
		auto r = _queue.top();
		_queue.pop();
		std::cout << r._id << '\n';
		r._time += r._period;
		_queue.push(r);
	}
	std::cout << "---\n";
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