#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;
class Backet {
public:
  // variables publicas
  // funciones publicas
  Backet();
  ~Backet();
  void build(list<pair<string, unsigned int>>&, unsigned int&);
  bool search(string &);
  static unsigned int str_to_int(string &);
  void print_bases();

private:
  // variables internas
  long unsigned int a;
  long unsigned int b;
  unsigned int p;
  unsigned int size;
  vector<string> level2;
  // funciones internas
  void set_randoms(unsigned int&);
  unsigned int hash(unsigned int &, unsigned int &);
};
