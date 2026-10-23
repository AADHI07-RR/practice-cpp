class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        if (n == 0) return true;
        bool c=true;
        for(int i=0;i<fb.size();i++){
            if(fb[i]==1) c=false;
            else if(fb[i]==0){
                if(c && (i+1==fb.size() || fb[i+1]==0)){
                    fb[i]=1;
                    c=false; n--;
                }
                else{
                    c=true;
                }

            }
            if(n==0) return true;
        }
        
         return false;
    }
};