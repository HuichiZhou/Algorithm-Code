// ��
// ����һ����  head[++size] x; up(size)
// �󼯺ϵ��е���Сֵ head[1]
// ɾ����Сֵ  head[1]  head[size] size--  down(1)
// ɾ������һ��Ԫ��  head[k] = head[size] size--; down(k); up(k)
// �޸�����һ��Ԫ�� head[k] = x; down(k); up(k)

//�洢 x �����2x �Ҷ���2x+1
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
