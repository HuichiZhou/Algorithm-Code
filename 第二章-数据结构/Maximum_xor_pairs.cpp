// Trie�� ��Ч�ش洢�Ͳ����ַ������ϵ����ݽṹ

#include<iostream>

using namespace std;

const int N = 100010;
int son[N][26], cnt[N], idx; // �±���0�ĵ㣬���Ǹ��ڵ㣬���ǿսڵ�
char str[N];
void insert(char str[]){
    int p = 0;
    for(int i=0; str[i]; i++){
        int u = str[i] - 'a';
        if(!son[p][u]) 
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p] ++;
}

int query(char str[]){
    int p = 0;
    for(int i=0; str[i]; i++){
        int u = str[i] - 'a';
        if(!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main(){
    int n;
    cin>>n;
    
    while(n--){
        char op[2];
        scanf("%s%s", op, str);
        if(op[0]=='I')
            insert(str);
        else
            printf("%d\n",query(str));
    }
    
    return 0;
}
