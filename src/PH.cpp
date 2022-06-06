#include <bits/stdc++.h>

using namespace std;

//typedef long int lint;

int p_hash(int a, int b, int p, int key, int size){
  return ((a*key + b) % p) % size;
}

map<char,char> m (
    {
        pair<char,char>('C',0),
        pair<char,char>('G',1),
        pair<char,char>('T',2),
        pair<char,char>('A',3),
    }
);

class PerfectHash{
    private: 

        int tam;
        int *bucket_size;
        int *string_int;
        vector<string> *arr;
        
        int p1 = 1000001;
        int p2 = 17;
        int a1 = rand()%p1;
        int a2 = rand()%p2;
        int b1 = 1 + rand()%(p1 - 1);
        int b2 = 1 + rand()%(p2 - 1);
        
        int to_int(string s){
            int val = 0;
            for (int i = 0; i < s.size()-1; i++)
            {
                val += m[s[i]];
                val = val<<2;
            }
            val += m[s[s.size()-1]];
            return val;
        }

        int first_hash(int s){
            return p_hash(a1,b1,p1,s,tam);
        }

        int second_hash(int s,int t){ 
            return p_hash(a2,b2,p2,s,t);
        }

        void get_bucket_size(string in[]){

            for (int i = 0; i < tam; i++)
            { 
                string_int[i] = to_int(in[i]);
                cerr<<string_int[i]<<endl;
                bucket_size[first_hash(string_int[i])]++;
            }  
            

            for (int i = 0; i < tam; i++)
            {
                cerr<<bucket_size[i]<<" ";
            }cerr<<endl;
            
        }

    public:
        PerfectHash(int tam){
            this->tam = tam;
            bucket_size = new int[tam];
            string_int = new int[tam];
            fill(bucket_size, bucket_size + tam + 1, 0);
            arr = new vector<string>[tam]; 
        }

        ~PerfectHash(){}

        void build(string in[]){
            get_bucket_size(in);
            //int extra = 20;
            for (int i = 0; i < tam; i++)
            {
                // int temp = string_int[i];
                // int pos = first_hash(temp);
                int temp_tam = bucket_size[i];
                arr[i] = vector<string>(temp_tam*temp_tam);
            }
            for (int i = 0; i < tam; i++)
            {
                int temp = to_int(in[i]);
                insert(in[i], temp);
            }
        }

        void insert(string a, int s){

            if(search(a,s))
                return;
            int f1 = first_hash(s);
            int f2 = second_hash(s,bucket_size[f1]*bucket_size[f1]);
            //                                        printf("ph[%d][%d] == %s\n",f1,f2,s); 
            // if(f2 == -1)
            //     return;
            arr[f1][f2] = a;
            
        }

        bool search(string a, int s){
            int f1 = first_hash(s);
            if(f1 == 0);
                return false;
            int f2 = second_hash(s,bucket_size[f1]*bucket_size[f1]) ;
                                                        cerr<<bucket_size[f1]<<endl;
            if(arr[f1][f2] == a)
                return true;
            return false;
        }

        void print_ph(){
            for (int i = 0; i < tam; i++)
            {
                cout<<bucket_size[i]<<"-> ";
                for (int j = 0; j < bucket_size[i]*bucket_size[i]; j++)
                {
                    if(arr[i][j] != "")cout<<arr[i][j]<<" ";
                }cout<<endl;
                
            }  
        }
};

int main(int argc, char *argv[]) {
    
    int N = 6;
    PerfectHash ph(N);
    string test[N] = {"ATGC","TCGA","AACT","CCTG","TCGA","GGTA"};
    ph.build(test);
    ph.print_ph();
    //cout<<ph.search(test[0],228)<<endl;
  
    return 0;
}