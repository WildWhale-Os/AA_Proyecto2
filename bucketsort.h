#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketsort(vector<int> &v){
	int n=v.size();
	vector<int> bucket[n+1];
	int max=v[0];
	for (int i = 1; i < n; ++i)//obtenemos valor maximo
	{
		if(v[i]>max)max=v[i];
	}

	for (int i = 0; i < n; ++i)//agregamos valores a los buckets
	{
		bucket[v[i]/(max/n)].push_back(v[i]);
	}

	for (int i = 0; i < v.size()+1; ++i)sort(bucket[i].begin(),bucket[i].end());//sort buckets

	int k=0;
	for (int i = 0; i < n+1; ++i)//reintroducimos valores a v ordenados
	{
		for (int j = 0; j < bucket[i].size(); ++j)
		{
			v[k]=bucket[i][j];
			k++;
		}
	}
}
