#include "backet.h"
#include <random>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class PerfectHash {
private:
  int table_size; // cantidad de buckets
  int a;
  int b;
  int p;
  vector<Backet> buckets;
  vector<list<pair<string, int>>> *values;
  int hash(int &, int &);
  void get_randoms();

public:
  PerfectHash(int);
  ~PerfectHash();
  void build(vector<string> &);
  bool search(string &);
};
