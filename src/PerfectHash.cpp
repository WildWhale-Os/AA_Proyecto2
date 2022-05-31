#include "PerfectHash.h"

using namespace std;

typedef long int lint;

lint hash(lint a, lint b, lint p, int key, int size){
  return ((a*key + b)%p)%size;
}

PerfectHash::PerfectHash(int tam){
    this->tam = tam;
    int aux[tam] = {};
    bucket_size = aux;
    arr = new vector<string>[tam]; 
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

int PerfectHash::second_hash(string s,int t){
    int h = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		h = h*43 + s[i]; //funcion NO perfecta
		h %= t;
	}
    return h;
}

int PerfectHash::get_bucket_size(string in[]){
    for (int i = 0; i < tam; i++)
    {
        bucket_size[first_hash(in[i])]++;
    }  
}

void PerfectHash::insert(string in[]){
    get_bucket_size(in);
    int extra = 20;
    for (int i = 0; i < tam; i++)
    {
        arr[first_hash(in[i])] = vector<string>(bucket_size[i]+extra);
    }
    
    for (int i = 0; i < tam; i++)
    {
        if(search(in[i]))
            return;
        arr[first_hash(in[i])][second_hash(in[i],bucket_size[i])] = in[i];
    }

}

bool PerfectHash::search(string s){
    
    // if(itr == arr[first_hash(s)].end())
    //     return 0;
    // return 1;
}

int PerfectHash::size(){
    
}
