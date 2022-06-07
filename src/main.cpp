#include "PerfectHash.h"
#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<unsigned int> PRIMOS;

bool isPrime(unsigned int n) {
  // 1 y 0 no son primos
  if (n == 1 || n == 0)
    return false;

  // hasta raiz cuadrada de n
  for (unsigned int i = 2; i * i <= n; i++) {
    // si el numero es divisible por i entonces no es primo
    if (n % i == 0)
      return false;
  }
  // en caso final si es primo
  return true;
}

void calculate_primes(unsigned int init, unsigned int end) {
  // verificar desde casda numero hasta n
  for (unsigned int i = init; i <= end; i++) {
    // verifica si en numero actual es primo
    if (isPrime(i)) {
      PRIMOS.push_back(i);
      // cout << i << endl;
    }
  }
}

string get_data(string filename) {
  ifstream file(filename);
  string line, salida = "";
  while (getline(file, line)) {
    // Output the text from the file
    line.pop_back();
    if (line[0] == '>')
      continue;
    salida += line;
  }
  file.close();
  return salida;
}

vector<string> get_kmers(string &data, unsigned int k) {
  vector<string> kmers;
  for (unsigned int i = 0; i < data.length() - k; i++) {
    string aux = "";
    for_each(data.begin() + i, data.begin() + (i + k),
             [&aux](char &c) { aux += c; });
    // cout << aux << endl;
    kmers.push_back(aux);
  }
  return kmers;
}

int main(int argc, char *argv[]) {

  srand(time(NULL));
  string data = get_data("./extra/clean_genes.txt");
  cout << "N;search" << endl;
  cout << "0;0" << endl;
  vector<string> kmers = get_kmers(data, 15);
  calculate_primes(kmers.size(), kmers.size() + 10000);

  for (int n = 1000; n <= 20000; n += 1000) {
    // experimentacion de construccion
    cout << n << ";";
    vector<string> test;
    for (int j = 0; j < n; j++)
      test.push_back(kmers.at(j));
    // para buscar
    PerfectHash table = PerfectHash(PRIMOS[40]);
    // variable de tiempo medio
    clock_t start, finish;
    clock_t tiempo_medio;
    // mediocion de construccion
    table.build(test);
    // d += finish - start;
    // cout << d << ";";
    // experimentacion de busqueda
    // mediocion de busquedas
    // d = 0;
    for (string elem : test) {
      start = clock();
      table.search(elem);
      finish += clock() - finish;
    }

    tiempo_medio = ((float)finish / CLOCKS_PER_SEC) / test.size();
    cout << tiempo_medio << endl;
  }
  return 0;
}
