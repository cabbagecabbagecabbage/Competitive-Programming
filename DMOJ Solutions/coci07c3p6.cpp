#include <bits/stdc++.h>
using namespace std;

int n,m,tree[1000005][10]={}, lazy[1000005]={};
int dials[250005];
int ql,qr,sum;
string s;

void build(int v, int l, int r) {
    //bottom of tree
    if (l == r) {
        tree[v][dials[l]] = 1;
    } 
    else {
        int m = (l + r) / 2;
        build(v*2, l, m);
        build(v*2+1, m+1, r);
        //combine frequency list of children
        for (int i=0; i<10; i++){
            tree[v][i] = tree[v*2][i]+tree[v*2+1][i];
        }
    }
}

int sumrange(int v, int l, int r) {
    //no overlap (the range given wasnt valid)
    if (l>qr || r<ql){
        return 0;
    }

    int temp[10]={};

    //overlap
    if (ql <= l && qr >= r) {

        //sum list
        for (int i=0; i<10; i++){
            sum += tree[v][i]*i;
        }

        //update the node itself
        for (int i=0; i<10; i++){
            temp[i] = tree[v][(i-1+10)%10];
        }
        for (int i=0; i<10; i++){
            tree[v][i] = temp[i];
        }
        lazy[v] = (lazy[v]+1)%10;
    }

    //partial overlap
    else{
        //update children
        for (int i=0; i<10; i++){
            temp[i] = tree[v*2][(i-(lazy[v])%10+10)%10];
        }
        for (int i=0; i<10; i++){
            tree[v*2][i] = temp[i];
        }
        lazy[v*2] = (lazy[v*2]+lazy[v])%10;

        for (int i=0; i<10; i++){
            temp[i] = tree[v*2+1][(i-(lazy[v])%10+10)%10];
        }
        for (int i=0; i<10; i++){
            tree[v*2+1][i] = temp[i];
        }
        lazy[v*2+1] = (lazy[v*2+1]+lazy[v])%10;

        lazy[v] = 0;

        //recur down
        int m = (l + r) / 2;
        sumrange(v*2, l, m);
        sumrange(v*2+1, m+1, r);

        //merge
        for (int i=0; i<10; i++){
            tree[v][i] = tree[v*2][i]+tree[v*2+1][i];
        }
    }
    return 0;
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin >> s;
    for (int i=0; i<n; i++){
        dials[i] = s[i]-'0';
    }
    build(1,0,n-1);

    long long a,b;

    for (int i=0; i<m; i++){
        cin >> ql >> qr;
        ql-=1;
        qr-=1;
        sum=0;
        sumrange(1,0,n-1);
        cout << sum << endl;
    }
    
    return 0;
}