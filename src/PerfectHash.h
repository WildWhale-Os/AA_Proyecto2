#include <string>
#include <vector>

using namespace std;

class PerfectHash {
private:
  int tam;
  vector<string> *arr;
  int first_hash(string);
  int second_hash(string);

public:
  PerfectHash(int tam);
  ~PerfectHash();
  void insert(string);
  int search(string);
  int size();
};
