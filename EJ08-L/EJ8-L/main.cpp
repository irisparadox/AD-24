
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
