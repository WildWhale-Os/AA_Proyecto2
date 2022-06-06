// #include "PerfectHash.h"
#include "PerfectHash.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

  PerfectHash table = PerfectHash();
  vector<string> input;
  string entrada;
  do {
    cin >> entrada;
    input.push_back(entrada);
  } while (entrada != "exit");
  table.build(input);
  do {
    cin >> entrada;
    if (table.search(entrada))
      cout << entrada << " "
           << "A sido encontrado en la tabla" << endl;
    else
      cout << entrada << " "
           << "No a sido encontrado en la tabla" << endl;

  } while (entrada != "exit");
  return 0;
}
