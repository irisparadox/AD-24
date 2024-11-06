
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;

// propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

long long calculate_cost(int _N, int _Max) {
    std::unordered_set<int> _box;
    long long _cost = 0;
    unsigned int i;
    for (i = 1; _box.size() < _N; ++i) {
        if (_box.find(_Max - i) == _box.end()) {
            _box.insert(i);
            _cost += i;
        }
    }

    return _cost;
}

bool resuelveCaso() {

    int _NRes, _Maxres;
    cin >> _NRes >> _Maxres;

    if (!std::cin)  // fin de la entrada
        return false;

    cout << calculate_cost(_NRes, _Maxres) << '\n';

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

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
