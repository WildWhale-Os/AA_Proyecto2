#include "PerfectHash.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

  PerfectHash ph(20);
  string test = "a";
  ph.insert(test);
  cout<<ph.search(test)<<endl;
  cout << "hola mundo" << endl;
  return 0;
}
