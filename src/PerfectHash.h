#include <bits/stdc++.h>

using namespace std;

class PerfectHash {
    private: 
        int tam;
<<<<<<< HEAD
        unordered_set<string> *arr;
        int first_hash(string);
        int second_hash(string);
=======
        bucket arr[12];
        void hash();
>>>>>>> fc287682391c9c54c4f2f8dbd74fb580b4d30007

    public:
        PerfectHash(int tam);
        ~PerfectHash();
        void insert(string);
        int search(string);
        int size();
};

