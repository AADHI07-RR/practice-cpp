#include <bits/stdc++.h>
using namespace std;
int find(vector<int>& ldr,int node){
    if(ldr[node]!=node){
        ldr[node]=find(ldr,node);
    }
    return ldr[node];
}
void join(vector<int>& ldr,int rt,int lt){
    ldr[find(ldr,lt)]=find(ldr,rt);
}
int main(){
    int T,c=1;cin>>T;
    while(T--){
    cout<<"Case "<<c++<<":"<<endl;
    int N,Q;cin>>N>>Q;
    vector<int> ldr(N+1),a(N+1);
    map<int,int> vlm,lvm;
    for(int i=1;i<=N;i++){
        int val;
        cin>>a[i];
        if(vlm.find(a[i])==vlm.end()){
            vlm[a[i]]=i;
            lvm[i]=a[i];
        }
        ldr[i]=vlm[a[i]];
    }
    while(Q--){
        int op;cin>>op;
        if(op==1){
            int x,y;cin>>x>>y;
            if(x==y) continue;
            if(vlm.find(x)==vlm.end()) continue;
            if(vlm.find(y)!=vlm.end()){
                join(ldr,vlm[x],vlm[y]);
                lvm.erase(vlm[x]);
                vlm.erase(x);
            }else{
                int xldr=vlm[x];
                lvm[xldr]=y;
                vlm.erase(x);
                vlm[y]=xldr;
            }
        }else{
            int idx;cin>>idx;
            int uldr=find(ldr,ldr[idx]);
            cout<<lvm[uldr]<<endl;
        }
    }
    }
}
