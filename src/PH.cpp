#include <bits/stdc++.h>

using namespace std;

typedef long int lint;

lint hash(lint a, lint b, lint p, int key, int size){
  return ((a*key + b) % p) % size;
}

map<char,char> m (
    {
        pair<char,char>('C',10),
        pair<char,char>('G',01),
        pair<char,char>('T',00),
        pair<char,char>('A',11),
    }
    );


class PerfectHash{
    private: 

        int tam;
        int *bucket_size;
        vector<string> *arr;

        int p1 = 17;
        int p2 = 23;
        int a1 = rand()%p1;
        int a2 = rand()%p2;
        int b1 = 1 + rand()%(p1 - 1);
        int b2 = 1 + rand()%(p2 - 1);
        

        int first_hash(string s){
            int h = 0;
            for (int i = 0; i < s.size(); ++i)
            {
                h = h*37 + s[i]; //funcion NO perfecta
                h %= tam;
            }
            return h;
        }

        int second_hash(string s,int t){
            int h = 0;
            cerr<<"t:"<<t<<endl;
            for (int i = 0; i < s.size(); ++i)
            {
                h = h*43 + s[i]; //funcion NO perfecta
                h %= t;
            }
            
            return h;
        }

        void get_bucket_size(string in[]){
            for (int i = 0; i < tam; i++)
            {
                bucket_size[first_hash(in[i])]++;
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
            fill(bucket_size, bucket_size + tam + 1, 0);
            arr = new vector<string>[tam]; 
        }

        ~PerfectHash(){}

        void build(string in[]){
            get_bucket_size(in);
            //int extra = 20;
            for (int i = 0; i < tam; i++)
            {
                int pos = first_hash(in[i]);
                int temp_tam = bucket_size[i];
                arr[pos] = vector<string>(temp_tam);
            }
            for (int i = 0; i < tam; i++)
            {
                insert(in[i],first_hash(in[i]));
            }
        }

        void insert(string s, int sh){

            if(search(s))
                return;
            int f1 = first_hash(s);
            int f2 = second_hash(s,sh) ;
            printf("ph[%d][%d] == %s\n",f1,f2,s);
            if(f2 == -1)
                return;
            arr[f1][f2] = s;
            
        }

        bool search(string s){
            int f1 = first_hash(s);
            int f2 = second_hash(s,arr[f1].size()) ;
            cerr<<arr[f1].size()<<endl;
            if(arr[f1][f2] == s)
                return true;
            return false;
        }


};

int main(int argc, char *argv[]) {
  cout << "hola mundo" << endl;
  int N = 6;
  PerfectHash ph(N);
  string test[N] = {"a","b","a","c","d","a"};
  ph.build(test);
  cout<<ph.search(test[1])<<endl;
  
  return 0;
}