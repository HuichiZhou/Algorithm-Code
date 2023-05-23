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
            
        if(x>n || y>n){ // ��ǰ�Ļ��� X �� Y �� N �󣬾��Ǽٻ�
            res++;
        }else{
            int px = find(x), py = find(y); //�ҵ����ڽ��
            if(t==1){ //������ͬ���ϵ
                if(px==py && (d[x]-d[y])%3){  //��ͬһ������ �� ������벻��ͬ��ľ���
                    res++;
                }else if(px!=py){ // �������ͬһ����
                    p[px] = py;  // ʹ��x�����ڽ��ĸ��ڵ� ���� y�����ڽ��
                    d[px] = d[y] - d[x]; // x�����ڽ��ľ��� ���� y�ľ��뵽x�ľ���
                }
            }else{ // �����ǳԹ�ϵ
                    if(px==py && (d[x]-d[y]-1)%3) //�������ͬһ���� �� ͬ��
                        res++;
                    else if(px!=py){ //��֮����ͬһ����
                        p[px] = py; // ����һ��
                        d[px] = d[y]+1-d[x]; // ����һ���Եľ���
                    }
            }
        }
    }
    cout<<res<<endl;


    return 0;
}
