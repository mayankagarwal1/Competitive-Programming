#include<bits/stdc++.h>
using namespace std;
//program to generate all subset from 1 to n(input)
void allSubsets(int n){
	for(int i=0;i<(1<<n);i++){
		vector<int>v;
		int siz = 0;
		for(int j=0;j<n;j++){
			if(i & (1<<j)){
				v.push_back(j+1);//1-n 
				siz++;
			}
		}
		for(int k = 0;k<siz;k++){
			cout<<v[k]<<" ";
		}
		cout<<endl;
	}
}
int main(){

	int n;
	cin>>n;
	allSubsets(n);

}
