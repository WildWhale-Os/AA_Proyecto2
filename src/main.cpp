// #include "PerfectHash.h"
#include "PerfectHash.h"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <time.h>
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
  string data = get_data("clean_genes.txt");
  cout << "N;build;search" << endl;
  cout << "0;0;0" << endl;
  vector<string> kmers = get_kmers(data, 15);
  calculate_primes(kmers.size(), kmers.size() + 10000);

  for (int n = 10000; n <= 1000000; n += 10000) {
    // experimentacion de construccion
    cout << n << ";";
    vector<string> test;
    for (int j = 0; j < n; j++)
      test.push_back(kmers.at(j));
    // para buscar
    PerfectHash table = PerfectHash(n + 1);
    // variable de tiempo medio
    double tiempo_medio;
    auto d = 0;
    // mediocion de construccion
    for (int i = 0; i < 100; i++) {
      auto start = chrono::high_resolution_clock::now();
      table.build(test);
      try{ auto finish = chrono::high_resolution_clock::now();
      d += chrono::duration_cast<chrono::nanoseconds>(finish - start).count();}
      catch(...) { cerr<<"ERROR"<<endl;}
      
    }
    tiempo_medio = (float)d / 100;
    cout << tiempo_medio << ";";
    // experimentacion de busqueda
    d = 0;
    // mediocion de busquedas
    for (string elem : test) {
      auto start = chrono::high_resolution_clock::now();
      table.search(elem);
      auto finish = chrono::high_resolution_clock::now();
      d += chrono::duration_cast<chrono::nanoseconds>(finish - start).count();
    }
    tiempo_medio = (float)d / test.size();
    cout << tiempo_medio << endl;
  }
  return 0;
}