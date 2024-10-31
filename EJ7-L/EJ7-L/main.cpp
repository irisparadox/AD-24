
/*@ <answer>
 *
 * Nombre y Apellidos:
 * 
 * GABRIEL GUILLERMO SAAVEDRA MOREIRA | DA56
 * ALEJANDRO LUQUE VILLEGAS           | DA43
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 Como usamos Dijkstra tendr�amos una complejidad total de O(AlogV).

 La complejidad espacial es de O(V)

 Para calcular el resultado, primero invertimos el grafo y buscamos desde el origen (siendo este la celda salida), y miramos que cada distancia
 sea menor o igual al valor del tiempo, si es as� sumamos 1 al numero de ratas.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig), dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }

    Valor distancia(int v) const { return dist[v]; }

private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;

    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor(); ulti[w] = a;
            pq.update(w, dist[w]);
        }
    }
};

bool resuelveCaso() {
    int n, s, t, a;
    cin >> n >> s >> t >> a;

    if (!std::cin)  // fin de la entrada
        return false;

    DigrafoValorado<int> digrafo(n);
    int u, v, valor;
    for (int i = 0; i < a; ++i) {
        cin >> u >> v >> valor;
        digrafo.ponArista({ v - 1, u - 1, valor });
    }

    int nRatas = 0;
    int i = 0;
    Dijkstra<int> d(digrafo, s - 1);
    while (i < n) {
        if (d.distancia(i) <= t && i != s - 1) ++nRatas;
        ++i;
    }

    std::cout << nRatas << '\n';

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