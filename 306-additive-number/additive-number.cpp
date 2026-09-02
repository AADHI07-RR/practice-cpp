#define ll long long int
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n=num.size();
        for(int fl=1;fl<=n/2;fl++){
            if(num[0]=='0' && fl>1) break;
            for(int sl=1;(n-fl-sl)>=max(fl,sl);sl++){
                if(num[fl]=='0'&& sl>1) break;
                ll fn=stoll(num.substr(0,fl));
                ll sn=stoll(num.substr(fl,sl));
                string bal=num.substr(fl+sl);
                
                while(bal.size()>0){
                    ll tn=fn+sn;
                    string tns=to_string(tn);
                
                    if(bal.find(tns)==0){
                        fn=sn;
                        sn=tn;
                        bal=bal.substr(tns.size());

                    } else break;
            
            }
            if(bal.size()==0)return true;

        }
    }
    return false;
}
};