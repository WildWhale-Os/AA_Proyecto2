#include <string>
#include <vector>

using namespace std;


class PerfectHash {
    private: 
        int tam;
        vector<string> *arr;
        void first_hash(string);
        void second_hash(string);

    public:
        PerfectHash();
        ~PerfectHash();
        void insert();
        void search();
        int size();
};
