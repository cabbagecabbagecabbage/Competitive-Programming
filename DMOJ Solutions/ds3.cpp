#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX;
const int MAXSZ=1e5+5;

int n, m, l, r, arr[MAXSZ];
char oper;

struct segTree{
    int L, R;
    int minVal, gcdVal, maxVal;

}seg[MAXSZ*4];

int GCD(int a, int b) {return (b == 0 ? a : GCD(b,a%b));}

void buildTree(int curNode, int left, int right){
    seg[curNode].L = left; seg[curNode].R = right;

    if (left == right){
        seg[curNode].minVal = arr[left];
        seg[curNode].gcdVal = arr[left];
        seg[curNode].maxVal = arr[left];
    }

    else{
        int mid = (left+right)/2;
        buildTree(curNode*2, left, mid);
        buildTree(curNode*2+1, mid+1, right);
        seg[curNode].minVal = min(seg[curNode*2].minVal , seg[curNode*2+1].minVal);
        seg[curNode].gcdVal = GCD(seg[curNode*2].gcdVal, seg[curNode*2+1].gcdVal);
        seg[curNode].maxVal = max(seg[curNode*2].maxVal , seg[curNode*2+1].maxVal);
    }
}

int minQuery(int curNode, int QL, int QR){
    int L = seg[curNode].L, R = seg[curNode].R;
    if (L > QR || R<QL) return inf;
    if (QL <= L && R <= QR) return seg[curNode].minVal;
    return min(minQuery(curNode*2, QL, QR), minQuery(curNode*2+1, QL, QR));
}

int gcdQuery(int curNode, int QL, int QR){
    int L = seg[curNode].L, R = seg[curNode].R;

    if (QL <= L && R <= QR){
        return seg[curNode].gcdVal;
    } 

    int nxtNode = curNode*2;
    int newL = seg[nxtNode].L, newR = seg[nxtNode].R;
    if (newL > QR || newR < QL) return gcdQuery(curNode*2+1, QL, QR);

    nxtNode = curNode*2+1; 
    newL = seg[nxtNode].L; newR = seg[nxtNode].R;
    if (newL > QR || newR < QL) return gcdQuery(curNode*2, QL, QR);

    return GCD(gcdQuery(curNode*2, QL, QR), gcdQuery(curNode*2+1, QL, QR));
}

int freqQuery(int curNode, int want, int QL, int QR){
    int L = seg[curNode].L, R = seg[curNode].R;

    if (L > QR || R < QL || seg[curNode].minVal > want || seg[curNode].maxVal < want) return 0;

    if (L==R){
        if (arr[L]==want) return 1;

        return 0;
    } 

    return freqQuery(curNode*2, want, QL, QR)+freqQuery(curNode*2+1, want, QL, QR);
    
}

void update(int curNode, int idx, int newVal){
    int L = seg[curNode].L, R = seg[curNode].R;

    if (idx < L || idx > R) return;

    if (L == R && L == idx){
        seg[curNode].minVal=newVal; 
        seg[curNode].gcdVal=newVal;
        seg[curNode].maxVal = newVal;
    }

    else{
        update(curNode*2, idx, newVal);
        update(curNode*2+1, idx, newVal);
        
        seg[curNode].minVal = min(seg[curNode*2].minVal, seg[curNode*2+1].minVal);
        seg[curNode].gcdVal = GCD(seg[curNode*2].gcdVal, seg[curNode*2+1].gcdVal);
        seg[curNode].maxVal = max(seg[curNode*2].maxVal, seg[curNode*2+1].maxVal);
    } 
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> arr[i];
    buildTree(1, 0, n-1);
    while (m--){
        cin >> oper >> l >> r;
        --l; --r;
        if (oper == 'C'){
            arr[l] = r+1;
            update(1, l, r+1);
        }

        else if (oper == 'M'){
            cout << minQuery(1, l, r) << "\n";
        }

        else if (oper == 'G'){
            cout << gcdQuery(1, l, r) << "\n";
        }

        else{
            cout << freqQuery(1, gcdQuery(1, l, r), l, r) << "\n";

        }
    }

    
}