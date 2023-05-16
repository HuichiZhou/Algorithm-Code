// 归并排序 分治 时间复杂度 O(n*logn) 
// 1.确定分界点 mid=(l+r)/2 
// 2.排序 递归排序左右两边 
// 3.归并 把有序的数组合并成一个 
#include<cstdio>
#include<iostream>
using namespace std;
 
const int N = 1e6+10; 

int n;
int q[N], tep[N];

void merge_sort(int q[], int l, int r){
	if(l >= r) return;
	int mid = l + r >> 1;
	merge_sort(q, l, mid), merge_sort(q, mid+1, r);
	int k = 0, i= l, j = mid + 1;
	while(i <= mid && j <= r){
		if(q[i]<=q[j]) tep[k++] = q[i++];
		else tep[k++] = q[j++];
	}
	while(i<=mid) tep[k++] = q[i++];
	while(j<=r) tep[k++] = q[j++];
	
	for(i=l, j=0; i<=r; i++, j++){
		q[i] = tep[j];
	} 
}
int main(){
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d",&q[i]);
	}	
	
	merge_sort(q, 0, n-1);
	
	for(int i=0; i<n; i++){
		printf("%d ", q[i]);
	}	
	
	return 0;
}
