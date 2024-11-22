
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

int knapsack_rec(int W, const vector<int>& wt, const vector<int>& val, int index, Matriz<int>& dp) {
    if (index < 0) return 0;
    if (dp[index][W] != -1) return dp[index][W];
    if (wt[index] > W)
        dp[index][W] = knapsack_rec(W, wt, val, index - 1, dp);
    else {
        dp[index][W] = max(val[index] + knapsack_rec(W - wt[index], wt, val, index - 1, dp), knapsack_rec(W, wt, val, index - 1, dp));
    }

    return dp[index][W];
}

int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    Matriz<int> dp(n, W + 1, -1);

    return knapsack_rec(W, wt, val, n - 1, dp);
}

bool resuelveCaso() {

    int N, W;
    cin >> W >> N;

    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> profit, weight;
    for (int i = 0; i < N; ++i) {
        int val, wt;
        cin >> val >> wt;
        profit.push_back(val);
        weight.push_back(wt);
    }

    cout << knapsack(W, weight, profit, N) << '\n';

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