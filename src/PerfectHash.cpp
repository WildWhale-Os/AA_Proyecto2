#include "PerfectHash.h"
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

PerfectHash::PerfectHash() {
  p = 1000001;
  a = rand() % p;
  b = 1 + rand() % (p - 1);
}
PerfectHash::~PerfectHash() {}

int PerfectHash::hash(int &key, int &size) {
  return (((a * key) + b) % p) % size;
}

void PerfectHash::build(vector<string> &input) {
  table_size = input.size();
  buckets.resize(table_size);
  values.resize(table_size);
  for (string elem : input) {
    int int_key = Backet::str_to_int(elem);
    int key = this->hash(int_key, table_size);
    values[key].push_back(pair<string, int>(elem, int_key));
  }

  for (int i = 0; i < input.size(); i++)
    buckets[i].build(values[i]);
}

bool PerfectHash::search(string &str) {
  int int_str = Backet::str_to_int(str);
  int key = this->hash(int_str, table_size);
  return buckets[key].search(str);
}
