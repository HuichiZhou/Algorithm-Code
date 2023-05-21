#include<iostream>
using namespace std;

const int N = 100010;
int q[N], hh, tt=-1;

int main(){
    int n;
    cin>>n;
    
    while(n--){
        string op;
        int x;
        
        cin>>op;
        
        if(op=="push"){
            cin>>x;
            q[++tt] = x;
        }else if(op=="pop"){
            hh++;
        }else if(op=="empty"){
            cout << (hh <= tt ? "NO" : "YES") << endl;
        }else{
            cout<<q[hh]<<endl;
        }
    }
    
    return 0;
}
