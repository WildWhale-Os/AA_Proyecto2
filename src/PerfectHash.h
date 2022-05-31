#include <string>
#include <vector>
#include <random>

using namespace std;

class PerfectHash {
private:
  int tam; // cantidad de buckets
  int total_size; // cantidad de elementos dentro de la estructura
  vector<string> *arr;
  int first_hash(string);
  int second_hash(string, int*);

public:
  PerfectHash(int tam);
  ~PerfectHash();
  void insert(string);
  bool search(string);
  int size();
};
