#include <bits/stdc++.h>

using namespace std;

class PerfectHash {
    private: 
        int tam;
        int *bucket_size;
        vector<string> *arr;
        int first_hash(string);
        int second_hash(string,int);
        void get_bucket_size(string*);

    public:
        PerfectHash(int tam);
        ~PerfectHash();
        void build(string*);
        void insert(string,int);
        bool search(string);
        int size();
};

