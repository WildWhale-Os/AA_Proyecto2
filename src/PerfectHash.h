#include <bits/stdc++.h>

using namespace std;

class PerfectHash {
    private: 
        int tam;
        unordered_set<string> *arr;
        int first_hash(string);
        int second_hash(string);

    public:
        PerfectHash(int tam);
        ~PerfectHash();
        void insert(string);
        int search(string);
        int size();
};

