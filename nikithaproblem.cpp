#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;cin>>n;



    while(n--){
        int r;cin>>r;
        vector<int> arr(r+1,0);
        bool ans=false;
        for(int i=1;i<=r;i++){
            cin>>arr[i];
        }
        int bal=0;
        for(int i=1;i<=r;i++){
            if(arr[i]>=i ){
                bal+=arr[i]-i;
                ans=true;
            }
            else if(arr[i]<i && bal+arr[i]>=i){
                ans=true;
                bal-=(i-arr[i]);
            }
            else{
                ans=false;
                break;
            }


        }
        if(ans==true){
            cout<<"YES"<<endl;
        }
        else{
        cout<<"NO"<<endl;
        }
    }
    return 0;
   }






