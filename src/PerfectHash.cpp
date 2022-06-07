#include "PerfectHash.h"
#include <cmath>
#include <cstdlib>
#include <list>
#include <string>
#include <utility>
#include <vector>

using namespace std;

PerfectHash::PerfectHash(unsigned int p) {
  this->p = p;
  a = rand() % p;
  b = rand() % p;
}
PerfectHash::~PerfectHash() {}

unsigned int PerfectHash::hash(unsigned int &key, unsigned int &size) {
  return (((a * key) + b) % p) % size;
}

void PerfectHash::get_randoms() {
  a = rand() % p;
  b = rand() % p;
  this->changes++;
}
void PerfectHash::build(vector<string> &input) {
  table_size = input.size();
  buckets.resize(table_size);
  values = vector<list<pair<string, unsigned int>>>(table_size);
  while (true) {
    for (string elem : input) {
      unsigned int int_key = Backet::str_to_int(elem);
      unsigned int key = this->hash(int_key, table_size);
      values.at(key).push_back(pair<string, unsigned int>(elem, int_key));
    }
    unsigned int total = 0;
    for (list<pair<string, unsigned int>> elem : values)
      total += elem.size() * elem.size();
    if (total < 2 * input.size())
      break;
    values.clear();
    get_randoms();
  }

  for (unsigned int i = 0; i < input.size(); i++) {
    buckets[i].build(values.at(i), p);
  }
}

bool PerfectHash::search(string &str) {
  unsigned int int_str = Backet::str_to_int(str);
  unsigned int key = this->hash(int_str, table_size);
  return buckets[key].search(str);
}

int PerfectHash::get_changes() { return this->changes; }
