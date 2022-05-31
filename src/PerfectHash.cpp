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

void PerfectHash::get_bucket_size(string in[]){
    for (int i = 0; i < tam; i++)
    {
        bucket_size[first_hash(in[i])]++;
    }  
}

void PerfectHash::build(string in[]){
    get_bucket_size(in);
     int extra = 20;
    for (int i = 0; i < tam; i++)
    {
        int pos = first_hash(in[i]);
        int temp_tam = bucket_size[i]+extra;
        arr[pos] = vector<string>(temp_tam);
    }
    for (int i = 0; i < tam; i++)
    {
        insert(in[i],bucket_size[i]);
    }
    
}

void PerfectHash::insert(string s, int sh){

    if(search(s))
        return;
    int f1 = first_hash(s);
    int f2 = second_hash(s,sh) ;
    arr[f1][f2] = s;
    
}

bool PerfectHash::search(string s){
    int f1 = first_hash(s);
    int f2 = second_hash(s,arr[f1].size()) ;
    if(arr[f1][f2] == s)
        return true;
    return false;
}

int PerfectHash::size(){
    
}
