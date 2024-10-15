#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

bool resolve_case() {
	long long int N;
	std::cin >> N;

	if (N == 0) return false;

	std::priority_queue<long long int, std::vector<long long int>, std::greater<long long int>> _queue;
	for (long long int i = 0; i < N; i++) {
		long long int num;
		std::cin >> num;
		_queue.push(num);
	}

	long long int work = 0;
	while (_queue.size() > 1) {
		long long int a = _queue.top();
		_queue.pop();
		long long int b = _queue.top();
		_queue.pop();

		long long int sum = a + b;
		work += sum;

		_queue.push(sum);
	}
	_queue.pop();
	std::cout << work << '\n';

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