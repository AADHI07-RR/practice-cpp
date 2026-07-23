#include<iostream>
#include<vector>
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
  vector<int> walls(N+2,0);
  while(M--){
    int lt,rt;
    cin>>lt>>rt;
    walls[lt]++;
    walls[rt+1]--;
    
    
  }
  int ans=200001;
  for(int w=1;w<=N;w++){
    walls[w]+=walls[w-1];
    ans=min(ans,walls[w]);
  }
  cout<<ans;
  
}
