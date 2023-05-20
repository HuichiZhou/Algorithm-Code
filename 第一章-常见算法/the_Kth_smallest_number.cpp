// 第k小的数 
// 快速选择算法 O(n)

// 找到分界点x q[L] q[L+R>>1] q[R]
// k<=s_l , 递归左边
// k>s_l , 递归右边 
#include<iostream>
using namespace std;

const int N = 100010;
int n, k;
int q[N];

int quick_sort(int l, int r, int k){
	if(l==r) 
		return q[l];
	int x = q[l], i = l-1, j = r + 1;
	while(i<j){
		while(q[++i]<x);
		while(q[--j]>x);
		if(i<j){
			swap(q[i], q[j]);
		} 
	}
	int sl = j - l + 1;
	if(k <= sl){
		return quick_sort(l, j, k);
	}else{
		return quick_sort(j+1, r, j-sl);
	}
		
}

int main(){
	cin>>n>>k;
	
	for(int i=0; i<n; i++){
		cin>>q[i];	
	}	
		
	cout<<quick_sort(0, n-1, k)<<endl;
	
	
	return 0;	
} 
