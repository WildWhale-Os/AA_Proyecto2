#include <string>
#include <utility>
#include <vector>
#include <random>
#include "backet.h"

using namespace std;

class PerfectHash {
private:
  int table_size; // cantidad de buckets
  int a;
  int b;
  int p;
  vector<Backet> buckets;
  vector<list<pair<string, int>>> values;
  int hash(int&,int&);

public:
  PerfectHash();
  ~PerfectHash();
  void build(vector<string>&);
  bool search(string&);
};
