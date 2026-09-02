class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        return cal(nums,0,0,target);
    }
    public int cal(int[] nums, int index, int sum, int target){
        if(index == nums.length) return sum == target? 1 : 0;
        int plus = cal(nums, index + 1, sum + nums[index], target);
        int minus = cal(nums, index + 1, sum - nums[index], target);
        return plus+minus;
    }
}