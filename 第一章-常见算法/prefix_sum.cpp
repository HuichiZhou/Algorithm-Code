// Ç°×ººÍ 
#include<iostream>
#include<cstdio>

using namespace std;

const int N = 100010;
int n,m;
int q[N];

int main(){
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>q[i];
		q[i] = q[i] + q[i-1];
	}
	while(m--){
		int l,r;
		cin>>p>>q;
		cout<<q[r]-q[l]<<endl;
	}
} 
