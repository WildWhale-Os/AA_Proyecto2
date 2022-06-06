// #include "PerfectHash.h"
#include "PerfectHash.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
vector<int> PRIMOS;

bool isPrime(int n) {
  // 1 y 0 no son primos
  if (n == 1 || n == 0)
    return false;

  // hasta raiz cuadrada de n
  for (int i = 2; i * i <= n; i++) {
    // si el numero es divisible por i entonces no es primo
    if (n % i == 0)
      return false;
  }
  // en caso final si es primo
  return true;
}

void calculate_primes(int init, int end) {
  // verificar desde casda numero hasta n
  for (int i = init; i <= end; i++) {
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

vector<string> get_kmers(string &data, int k) {
  vector<string> kmers;
  for (int i = 0; i < data.length() - k; i++) {
    string aux = "";
    for_each(data.begin() + i, data.begin() + (i + k - 1),
             [&aux](char &c) { aux += c; });
    // cout << aux << endl;
    kmers.push_back(aux);
  }
  return kmers;
}

int main(int argc, char *argv[]) {
  string data = get_data("./extra/clean_genes.txt");
  vector<string> kmers = get_kmers(data, 15);
  calculate_primes(kmers.size(), kmers.size() + 10000);

  clock_t begin, end;
  double time_spent;
  srand(time(NULL));
  cout << kmers.size() << " " << PRIMOS.at(PRIMOS.size() - 1) << endl;
  PerfectHash table = PerfectHash(PRIMOS.at(PRIMOS.size() - 1));
  table.build(kmers);
  string in;
  do {
    cin >> in;
    if (table.search(in))
      cout << in << " ha sido encontrada" << endl;
    else
      cout << in << " no ha sido encontrada" << endl;
  } while (in != "exit");
  return 0;
}
