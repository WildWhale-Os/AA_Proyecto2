#include <string>
#include <vector>

using namespace std;

struct bucket{
    vector<string> s;
};

class PerfectHash {
    private: 
        int tam;
        bucket arr[12];
        void first_hash();
        void second_hash();

    public:
        PerfectHash();
        ~PerfectHash();
        void insert();
        void search();
        int size();
};
