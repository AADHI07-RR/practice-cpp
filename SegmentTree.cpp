#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int find(vector<int>& seg, int node, int nl, int nr, int ql, int qr){
    if(nr<ql || nl>qr) return INT_MAX;
    if(nl>=ql && nr<=qr) return seg[node];
    int mid = (nl+nr)/2;
    int lftr = find(seg,2*node,nl,mid,ql,qr);
    int rftr = find(seg,2*node+1,mid+1,nr,ql,qr);
    return min(lftr,rftr);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,Q; cin>>N>>Q;
    int newN = 1;
    while(newN<N) newN<<=1;
    vector<int> seg(newN+newN, INT_MAX);
    for(int i=newN;i<newN+N;i++){
        int n;cin>>n;
        seg[i] = n;
    }
    for(int i=newN-1;i>=1;i--) seg[i] = min(seg[i+i], seg[i+i+1]);
    while(Q--){
        int a, b; cin >> a >> b;
        a--; b--;
        cout << find(seg, 1, 0, newN - 1, a, b) << '\n';
    }


}
