// 堆
// 插入一个数  head[++size] x; up(size)
// 求集合当中的最小值 head[1]
// 删除最小值  head[1]  head[size] size--  down(1)
// 删除任意一个元素  head[k] = head[size] size--; down(k); up(k)
// 修改任意一个元素 head[k] = x; down(k); up(k)

//存储 x 左儿子2x 右儿子2x+1
//down(x)  up(x)

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;

int n, m;
int h[N], cnt;

void down(int u){
    int t = u;
    if(u*2 <= cnt && h[u*2]<h[t]) t = u * 2;
    if(u*2 + 1 <= cnt && h[u*2 + 1]<h[t]) t = u * 2 + 1;
    if(u != t){
        swap(h[u], h[t]);
        down(t);
    }
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>h[i];
    }
    cnt = n;
    
    for(int i = n/2; i; i--){
        down(i);
    }
    
    while(m--){
        cout<<h[1]<<" ";
        h[1] = h[cnt];
        cnt--;
        down(1);
    }
    
    return 0;    
}
