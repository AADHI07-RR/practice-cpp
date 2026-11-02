class Solution {
public:
    int maximumUnits(vector<vector<int>>& arr, int trucksize) {
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(trucksize==0)break;
            int a=arr[i][0];
            int b=arr[i][1];
            if(trucksize>=a){
                ans+=(a*b);
                trucksize-=a;
            }
            else{
                ans+=(trucksize*b);
                trucksize=0;
            }


        }
        return ans;
    }
};