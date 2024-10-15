#include <iostream>
#include <string>
#include "TreeSet_AVL.h"
using namespace std;

int main() {
	   Set<int> ents;
	   ents.insert(10);
	   ents.insert(20);
	   ents.insert(14);
	   ents.insert(7);
	   ents.insert(8);
	   cout << ents.get_min() << '\n';  // muestra 7
	   ents.erase(8);
	   ents.erase(ents.get_min());
	   cout << ents.get_min() << '\n';  // muestra 10

	   Set<string> cads;
	   cads.insert("uno");
	   cads.insert("dos");
	   cads.insert("tres");
	   cads.insert("cuatro");
	   cads.insert("seis");
	   cout << cads.get_min() << '\n';  // muestra cuatro
	   cads.erase(cads.get_min());
	   cout << cads.get_min() << '\n';  // muestra dos
}