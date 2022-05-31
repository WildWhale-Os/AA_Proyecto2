#include "PerfectHash.h"

using namespace std;

PerfectHash::PerfectHash(int tam){
    this->tam = tam;
    arr = new unordered_set<string>[tam]; 
    //si terminamos usando sets, podria implementarce con un set de sets
}

PerfectHash::~PerfectHash(){}

int PerfectHash::first_hash(string s){
    int h = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		h = h*37 + s[i]; //funcion NO perfecta
		h %= tam;
	}
    return h;
}

int PerfectHash::second_hash(string s){
    int h = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		h = h*43 + s[i]; //funcion NO perfecta
		h %= tam;
	}
    return h;
}

void PerfectHash::insert(string s){
    if(search(s))
        return;
    arr[first_hash(s)].insert(s);
}

int PerfectHash::search(string s){
    unordered_set<string>::iterator itr = arr[first_hash(s)].find(s);
    if(itr == arr[first_hash(s)].end())
        return 0;
    return 1;
}

int PerfectHash::size(){}

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