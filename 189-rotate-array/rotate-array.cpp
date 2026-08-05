class Solution {
public:
    void reverse(int l,int r,vector<int>& nums){
        while(l<r){
            swap(nums[l],nums[r]);
            l++;r--;

            
        }

    }
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        int n=nums.size();
        int div=n-k;
        reverse(0,div-1,nums);
        reverse(div,n-1,nums);
        reverse(0,n-1,nums);


    
    }
};