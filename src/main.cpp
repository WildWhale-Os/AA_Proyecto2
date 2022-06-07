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
#include <ctime>

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
  int n=1,num, pos;
	int rep=300;
	double tiempoLineal,tiempoBinario,ms=1000;
	clock_t start=clock();
	srand(time(NULL));
	cout<<"n"<<";"<<"Tiempo algoritmo lineal"<<";"<<"Tiempo algoritmo recursivo"<<endl;
  srand(time(NULL));
  string data = get_data("clean_genes.txt");
  cout << "N;build;search" << endl;
  cout << "0;0;0" << endl;
  vector<string> kmers = get_kmers(data, 15);
  calculate_primes(kmers.size(), kmers.size() + 10000);
  PerfectHash table = PerfectHash(n + 1);
  vector<string> test;
  for (int j = 0; j < n; j++)
    test.push_back(kmers.at(j));
  for(n=100000;n<=1000000;n+=100000){
    tiempoLineal=0,tiempoBinario=0;
    for(int it=0;it<rep;it++){
      num=rand() % n;
      start=clock();
      for (int i = 0; i < 100; i++)
      {
        table.build(test);
      }
      tiempoLineal+= ((double)clock() - start);
      //tiempoLineal /= 100;
      start=clock();
      for (string elem : test) {
      table.search(elem);
      
      }
      tiempoBinario+= ((double)clock() - start);
      //tiempoBinario /= 100;
  }
  cout<<n<<";"<<tiempoLineal*ms/(double)rep/CLOCKS_PER_SEC<<";"<<tiempoBinario*ms/(double)rep/CLOCKS_PER_SEC<<endl;
  
  }
  return 0;
}