class Solution {
    public String largestNumber(int[] nums) {
        List<String> vals=new ArrayList<>();
        for(Integer n:nums){
            vals.add(n.toString());
        }
        Collections.sort(vals,(a,b)->{return -((a+b).compareTo(b+a));});
        StringBuilder sb=new StringBuilder();
        for(String s:vals){
            sb.append(s);
        }
        if("".equals(sb.toString().replaceAll("0",""))){
            return "0";
        }
        return sb.toString();
    }
}