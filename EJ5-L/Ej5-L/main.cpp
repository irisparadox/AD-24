
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class Ciclo {
public:
    using Camino = std::queue<int>;

public:
    Ciclo(const Digrafo& g) : visit(g.V(), false), ant(g.V()), apilado(g.V(), false), hayCiclo(false) {
        for (int v = 0; v < g.V(); ++v) {
            if (!visit[v])
                dfs(g, v);
        }
    }

    bool hay_ciclo() const { return hayCiclo; }

    Camino const& ciclo() const { return _ciclo; }
private:
    std::vector<bool> visit;
    std::vector<int> ant;
    std::vector<bool> apilado;
    Camino _ciclo;
    bool hayCiclo;

private:
    void dfs(const Digrafo& g, int v) {
        apilado[v] = true;
        visit[v] = true;
        for (int w : g.ady(v)) {
            if (hayCiclo)
                return;
            if (!visit[w]) {
                ant[w] = v; dfs(g, w);
            }
            else if (apilado[w]){
                hayCiclo = true;
                for (int x = v; x != w; x = ant[x]) {
                    _ciclo.push(x);
                }
                _ciclo.push(w);
                _ciclo.push(v);
            }
        }
        apilado[v] = false;
    }
};

Digrafo construir_grafo(int _Size) {
    Digrafo graph(_Size);
    char vertexType;
    std::cin >> vertexType;
    for (int i = 0; i < _Size - 1; ++i) {
        int dir;
        switch (vertexType) {
        case 'A':
            graph.ponArista(i, i + 1);
            break;
        case 'J':
            std::cin >> dir;
            graph.ponArista(i, dir - 1);
            break;
        case 'C':
            std::cin >> dir;
            graph.ponArista(i, dir - 1);
            graph.ponArista(i, i + 1);
            break;
        }
        std::cin >> vertexType;
    }

    switch (vertexType) {
    case 'A':
        break;
    case 'J': case 'C':
        int dir;
        std::cin >> dir;
        graph.ponArista(_Size - 1, dir - 1);
        break;
    }

    return graph;
}

bool resolve_case() {

    int n;
    std::cin >> n;

    Digrafo grafo = construir_grafo(n);
    Ciclo ciclo(grafo);

    if (!std::cin)  // fin de la entrada
        return false;


    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
/*#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
*/
    while (resolve_case());

    // para dejar todo como estaba al principio
/*#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
*/
    return 0;
}
