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
  void build(list<pair<string, int>>&, int&);
  bool search(string &);
  static int str_to_int(string &);
  void print_bases();

private:
  // variables internas
  int a;
  int b;
  int p;
  int size;
  vector<string> level2;
  // funciones internas
  void set_randoms(int&);
  int hash(int &, int &);
};
