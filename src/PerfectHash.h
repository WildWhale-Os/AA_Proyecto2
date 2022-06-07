#include "backet.h"
#include <random>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class PerfectHash {
private:
  unsigned int table_size; // cantidad de buckets
  unsigned int a;
  unsigned int b;
  unsigned int p;
  unsigned int changes = 1;
  vector<Backet> buckets;
  vector<list<pair<string, unsigned int>>> *values;
  unsigned int hash(unsigned int &, unsigned int &);
  void get_randoms();

public:
  PerfectHash(unsigned int);
  ~PerfectHash();
  void build(vector<string> &);
  bool search(string &);
  int get_changes();
};
