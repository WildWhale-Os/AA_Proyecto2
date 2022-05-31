#include "PerfectHash.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

  PerfectHash ph(4);
  string test[] = {"a","b","c","d"};
  ph.build(test);
  cout<<ph.search(test[1])<<endl;
  cout << "hola mundo" << endl;
  return 0;
}
