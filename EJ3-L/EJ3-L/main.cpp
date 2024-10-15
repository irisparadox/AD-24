/**
 * Nombre y usuario de cada miembro de la pareja
 *
 * GABRIEL GUILLERMO SAAVEDRA MOREIRA (DA56)
 * ALEJANDRO LUQUE VILLEGAS (DA43)
 *
 * Explica tu código: En la funcion prime_time() calculamos mediante el uso de dos colas de prioridad variable, cual
 * sera el canal que tenga mayor audiencia. Actualizamos los tiempos que lleva cada canal en la cola "queue", y actualizamos
 * el tiempo en "prime time" en la cola result. Para la cola result creamos un comparador para los casos en los que la duracion
 * en prime time es igual, para ordenarlos de menor a mayor segun el numero de canal. Luego los mostramos.
 *
 */

#include <fstream>
#include <iostream>
#include "IndexPQ.h"

using namespace std;

struct comparator {
    bool operator()(const pair<int, int>& l, const pair<int, int>& r) {
        return (l.second > r.second) ||
            ((l.first < r.first) && (l.second == r.second));
    }
};

IndexPQ <pair<int,int>, comparator> prime_time(int primeDuration, int nChannels, int nUpdates) {
    IndexPQ<int, std::greater<int>> queue(nChannels);
    IndexPQ<pair<int,int>, comparator> result(nChannels);
    for (int i = 0; i < nChannels; i++) {
        int audience;
        cin >> audience;
        queue.push(i, audience);
        result.push(i, {i, 0});
    }

    int prevTime = 0;

    int currentTime;
    int topId;
    int prime;
    for (int i = 0; i < nUpdates; i++) {
        cin >> currentTime;
        topId = queue.top().elem;
        prime = result.priority(topId).second;
        prime += currentTime - prevTime;
        result.update(topId, {topId, prime});

        int id;
        while (cin >> id && (id != -1)) {
            int newAudience;
            cin >> newAudience;
            queue.update(id - 1, newAudience);
        }
        prevTime = currentTime;
    }

    topId = queue.top().elem;
    prime = result.priority(topId).second;
    prime += primeDuration - prevTime;
    result.update(topId, {topId, prime});

    return result;
}

bool resuelveCaso() {
    int primeDuration, nChannels, nUpdates; // Duración del prime time, número de canales y número de actualizaciones
    cin >> primeDuration >> nChannels >> nUpdates;
    if (!cin)
        return false;

    IndexPQ<pair<int, int>, comparator> sol = prime_time(primeDuration, nChannels, nUpdates);

    for (int i = 0; i < nChannels; i++) {
        pair<int, int> result;
        result.first = sol.top().elem;
        result.second = sol.top().prioridad.second;
        if (result.second != 0) {
            cout << result.first + 1 << ' ' << result.second << '\n';
        }
        sol.pop();
    }

    cout << "---" << '\n';

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}