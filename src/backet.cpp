#include "backet.h"
#include <algorithm>
#include <string>
#include <utility>

const string CLEAR = "NA";

using namespace std;

map<char, char> bases = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

Backet ::Backet() {}

Backet ::~Backet() {}

void Backet::set_randoms(int &p) {
  this->p = p;
  a = rand() % p;
  b = rand() % p;
}

int Backet::hash(int &key, int &size) {
  // cout << key << " " << size << " " << p << endl;
  long int aux = a * (long int)key;
  aux += b;
  int salida = aux % p;
  salida = salida % size;

  return salida;
}

int Backet::str_to_int(string &input) {
  int val = 0;
  for (char &elem : input) {
    // cout << elem << endl;
    val = val << 2;
    val += (int)bases.find(elem)->second;
  }
  return val;
}

void Backet::build(list<pair<string, int>> &k_mers, int &p) {
  if (k_mers.empty()) {
    size = 0;
    return;
  }
  size = k_mers.size() * k_mers.size(); // m = c^2
  bool colition = false;

  while (!colition) {
    level2.assign(size, CLEAR);
    set_randoms(p);
    // cout << a << " " << b << endl;
    list<pair<string, int>>::iterator iter = k_mers.begin();

    while (iter != k_mers.end() && !colition) {
      int key = this->hash(iter->second, size);
      string aux = level2[key];
      if (aux != CLEAR) {
        if (aux == iter->first) {
          iter++;
          continue;
        } else {
          // cout << "Rearmando " << iter->first << endl;
          colition = true;
          break;
        }
      }
      level2[key] = iter->first;
      iter++;
    }
    if (colition)
      colition = false;
    else
      colition = true;
  }
}

bool Backet::search(string &str) {
  if (!size)
    return false;
  int str_int = str_to_int(str);
  int key = this->hash(str_int, size);
  if (level2[key] == str)
    return true;
  return false;
}

void Backet::print_bases() {
  cout << (int)bases.find('A')->second << endl;
  cout << (int)bases.find('C')->second << endl;
  cout << (int)bases.find('G')->second << endl;
  cout << (int)bases.find('T')->second << endl;
}
