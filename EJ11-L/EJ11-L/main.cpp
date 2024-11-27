
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int lcs(vector<string>& s1, vector<string>& s2, int i, int j, Matriz<int>& dp) {
    if (i == 0 || j == 0) return 0;
    
    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i - 1] == s2[j - 1])
        return dp[i][j] = 1 + lcs(s1, s2, i - 1, j - 1, dp);

    return dp[i][j] = max(lcs(s1, s2, i, j - 1, dp), lcs(s1, s2, i - 1, j, dp));
}

vector<string> rebuild(vector<string>& s1, vector<string>& s2, int i, int j, Matriz<int>& dp) {
    vector<string> list;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            list.push_back(s1[i - 1]);
            --i, --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) --i;
        else --j;
    }
    return list;
}

bool resuelveCaso() {

    std::string lista1, lista2;
    std::getline(cin, lista1);
    std::getline(cin, lista2);

    if (!std::cin)  // fin de la entrada
        return false;
    
    std::istringstream stream1(lista1);
    std::istringstream stream2(lista2);

    std::vector<std::string> vec1, vec2;

    while (std::getline(stream1, lista1, ' ')) {
        vec1.push_back(lista1);
    }

    while (std::getline(stream2, lista2, ' ')) {
        vec2.push_back(lista2);
    }

    int i = vec1.size();
    int j = vec2.size();

    Matriz<int> dp(i + 1, j + 1, -1);

    lcs(vec1, vec2, i, j, dp);
    vector<string> sol = rebuild(vec1, vec2, i, j, dp);

    for (int i = sol.size() - 1; i > -1; --i) {
        cout << sol[i] << ' ';
    }

    cout << '\n';

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
