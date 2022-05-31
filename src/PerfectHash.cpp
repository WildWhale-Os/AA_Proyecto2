#include "PerfectHash.h"
#include <cmath>

using namespace std;

int hash(int a, int b, int p, int key, int size) {
  return abs(((a * key + b) % p) % size);
}

PerfectHash::PerfectHash(int tam) {
  this->tam = tam;
  arr = new vector<string>[tam];
  // si terminamos usando sets, podria implementarce con un set de sets
}

PerfectHash::~PerfectHash() {}

int PerfectHash::first_hash(string s) {
  int h = 0;
  for (int i = 0; i < s.size(); ++i) {
    h = h * 37 + s[i]; // funcion NO perfecta
    h %= tam;
  }
  return hash(this->a1, this->b1, this->p1, h, tam);
}

int PerfectHash::second_hash(string s, int *hash_one) {
  int h = 0;
  for (int i = 0; i < s.size(); ++i) {
    h = h * 43 + s[i]; // funcion NO perfecta
    h %= tam;
  }
  return hash(this->a2, this->b2, this->p2, h, arr[*hash_one].size());
}

void PerfectHash::insert(string s) {
  if (search(s))
    return;
  int hash_one = first_hash(s);
  int hash_two = second_hash(s, &hash_one);
  vector<string> showsen = arr[hash_one];
  showsen[hash_two] = s;
}

bool PerfectHash::search(string s) {
  int hash_one = first_hash(s);
  int hash_two = second_hash(s, &hash_one);
  vector<string> showsen = arr[hash_one];

  if (showsen.size() == 0)
    return false;

  if (showsen.at(hash_two) == s)
    return true;

  return false;
}

int PerfectHash::size() {
  return total_size;
}

//                 |     set             | unordered_set
// ---------------------------------------------------------
// Ordering        | increasing  order   | no ordering
//                 | (by default)        |

// Implementation  | Self balancing BST  | Hash Table
//                 | like Red-Black Tree |

// search time     | log(n)              | O(1) -> Average
//                 |                     | O(n) -> Worst Case

// Insertion time  | log(n) + Rebalance  | Same as search

// Deletion time   | log(n) + Rebalance  | Same as search

// Overall space   | n                   | n
