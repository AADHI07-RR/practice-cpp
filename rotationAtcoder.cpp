#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,Q;cin>>N>>Q;
    string S;cin>>S;
    int pos=N-1;
    while(Q--){
        int op,t;cin>>op>>t;
        if(op==1){
            t=t%N;
            pos=pos-t;
            if(pos<0) pos+=N;
        }else{
            cout<<S[(pos+t)%N]<<endl;
        }
    }
}
