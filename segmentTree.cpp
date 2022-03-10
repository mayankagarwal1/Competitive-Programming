#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct segTree{
    vector<int>v;
    int len;
    int left(int p)
    {
        return 2*p;
    }
    int right(int p)
    {
        return 2*p+1;
    }
    int config(int l,int r,int arr[],int p)
    {
        if(l==r)
        {
            v[p] = arr[l];
            return v[p];
        }
        int m = (l+r)/2;
        v[p] = config(l,m,arr,left(p))+config(m+1,r,arr,right(p));
        return v[p];
        
    }
    void Build(int n,int arr[])
    {
        v.resize(2*n);
        len = n;
        config(0,n-1,arr,1);
        
    }
    int sum(int l,int r,int i,int j,int p=1)
    {
        if(l>r)
        {
            return 0;
        }
        if(l>j || r<i)
        {
            return 0;
        }
        if(l>=i && r<=j)
        {
            return v[p];
        }
        int m = (l+r)/2;
        return (sum(l,m,i,j,left(p)) + sum(m+1,r,i,j,right(p)));
    }
    int sum(int i,int j)
    {
        return sum(0,len-1,i,j,1);
    }
    void print(int n)
    {
        for(int i=1;i<2*n;i++)
        {
            cout<<v[i]<<" ";
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	
	int n=4;
	int arr[] = {1,2,3,4};
	
	struct segTree s1;
	s1.Build(n,arr);
	
	
	s1.print(n);
	cout<<endl;
	
	cout<<s1.sum(0,2);
	
	
	
	
	
	return 0;
}

