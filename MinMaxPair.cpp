#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;cin>>N;
    vector<int> a(N+1);
    for(int i=1;i<=N;i++){
        cin>>a[i];
    }
    long long int diff=0,same=0;
    for(int i=1;i<=N;i++){
        if(a[i]==i) same++;
        else if(i==a[a[i]]) diff++;
    }
    diff/=2;
    same=(same*(same-1))/2;
    cout<<diff+same;
}
