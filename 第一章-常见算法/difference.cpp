// ²î·Ö
#include<iostream>
using namespace std;

int n,m;
const int N = 100010;
int a[N],b[N];


int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        b[i] = a[i] - a[i-1];
    }

    while(m--){
        int l,r,t;
        cin>>l>>r>>t;
        b[l] += t;
        b[r+1] -= t;
    }
    
    
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += b[i];
        cout<<sum<<" ";
    }
}
