#include<iostream>

using namespace std;

const int N = 50010;

int n, m;
int p[N], d[N];

int find(int x){
    if(p[x] != x){
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}


int main(){
    cin>>n>>m;
    
    for(int i=1; i<=n; i++){
        p[i] = i;
    }
    
    int res = 0;
    
    while(m--){
        int t, x, y;
        cin>>t>>x>>y;
            
        if(x>n || y>n){ // 当前的话中 X 或 Y 比 N 大，就是假话
            res++;
        }else{
            int px = find(x), py = find(y); //找到祖宗结点
            if(t==1){ //他们是同类关系
                if(px==py && (d[x]-d[y])%3){  //在同一个环内 且 满足距离不是同类的距离
                    res++;
                }else if(px!=py){ // 如果不在同一个环
                    p[px] = py;  // 使得x的祖宗结点的父节点 连到 y的祖宗结点
                    d[px] = d[y] - d[x]; // x的祖宗结点的距离 等于 y的距离到x的距离
                }
            }else{ // 他们是吃关系
                    if(px==py && (d[x]-d[y]-1)%3) //如果是在同一个环 且 同类
                        res++;
                    else if(px!=py){ //反之不在同一个环
                        p[px] = py; // 连在一起
                        d[px] = d[y]+1-d[x]; // 加上一个吃的距离
                    }
            }
        }
    }
    cout<<res<<endl;


    return 0;
}
