class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> s=new HashSet<>();
        Arrays.sort(nums);
        
        for(int i=0;i<nums.length;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            if(nums[i]>0) break;
            int j=i+1;
            int k=nums.length-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    List<Integer> temp=new ArrayList();
                    temp.add(nums[i]);
                    temp.add(nums[j]);
                    temp.add(nums[k]);
                    s.add(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1])k--;

                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    k--;

                }
                else {
                    j++;
                }
            }
        }
        return new ArrayList<>(s);
         
        
    }
}
