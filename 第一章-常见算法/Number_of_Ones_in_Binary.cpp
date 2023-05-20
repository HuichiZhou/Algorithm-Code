#include<iostream>

using namespace std;

const int N =100010;
int n;
int q[N];

int lowbit(int x){
    return x&-x;
}

int main(){
    cin>>n;
    
    while(n--){
        int x;
        cin>>x;
        
        int res = 0;
        while(x){
            x -= lowbit(x);
            res ++;
        }
        cout<<res<<" ";
    }
    cout<<endl;
    return 0;
}
