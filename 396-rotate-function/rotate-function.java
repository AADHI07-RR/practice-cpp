class Solution {
    public int maxRotateFunction(int[] nums) {
        int N=nums.length,sum=0;
        long fnval=0,ans=0;
        for(int i=0;i<N;i++){
            sum+=nums[i];
            fnval+=(i*nums[i]);
        }
        ans=fnval;
        for(int l=N-1;l>0;l--){
            fnval=fnval-(nums[l]*(N-1))+(sum-nums[l]);
            ans=Math.max(ans,fnval);
        }

        return (int)ans;
    }
}