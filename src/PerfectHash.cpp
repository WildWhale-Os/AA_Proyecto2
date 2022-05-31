#include "PerfectHash.h"

using namespace std;

PerfectHash::PerfectHash(){
    tam = 20;
    arr = new vector<string>[tam];
}

PerfectHash::~PerfectHash(){}

void PerfectHash::first_hash(string s){
    int h = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		h = h*37 + s[i]; //funcion NO perfecta
		h %= tam;
	}
    arr[h].push_back(s);
}

void PerfectHash::second_hash(string s){}

void PerfectHash::insert(){}

void PerfectHash::search(){}

int PerfectHash::size(){}