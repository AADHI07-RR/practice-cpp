#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    int n;cin>>n;
    vector<int> arr;
    int power=0;
    while(n){
        int dig = n%10;
        int s = arr.size();
        if(s >= dig){
            for(int i=0;i<dig;i++){
                arr[i]+= pow(10, power);
            }
        } else {
            for(int i=0;i<s;i++){
                arr[i]+= pow(10,power);
            }
            for(int i=s;i<dig;i++){
                arr.insert(arr.begin(), pow(10,power));
            }
        }
        n/=10;power++;
    }
    for(int i : arr){
        cout<<i<<"+";
    }
}
