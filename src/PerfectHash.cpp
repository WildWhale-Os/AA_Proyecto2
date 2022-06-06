#include "PerfectHash.h"
#include <cmath>
#include <cstdlib>
#include <list>
#include <string>
#include <utility>
#include <vector>

using namespace std;

PerfectHash::PerfectHash(int p) {
  this->p = p;
  a = rand() % p;
  b = rand() % p;
}
PerfectHash::~PerfectHash() {}

int PerfectHash::hash(int &key, int &size) {
  return (((a * (long int)key) + b) % p) % size;
}

void PerfectHash::get_randoms() {
  a = rand() % p;
  b = rand() % p;
}
void PerfectHash::build(vector<string> &input) {
  table_size = input.size();
  buckets.resize(table_size);
  values = new vector<list<pair<string, int>>>(table_size);
  while (true) {
    for (string elem : input) {
      int int_key = Backet::str_to_int(elem);
      int key = this->hash(int_key, table_size);
      values->at(key).push_back(pair<string, int>(elem, int_key));
    }
    int total = 0;
    for (list<pair<string, int>> elem : *values)
      total += elem.size() * elem.size();
    if (total < 4 * input.size())
      break;
    free(values);
    get_randoms();
  }

  for (int i = 0; i < input.size(); i++) {
    cout << "Armando bucket " << i << " size " << values->at(i).size() << endl;
    buckets[i].build(values->at(i), p);
  }
}

bool PerfectHash::search(string &str) {
  int int_str = Backet::str_to_int(str);
  int key = this->hash(int_str, table_size);
  return buckets[key].search(str);
}
