class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int flag=0, idx=0;
        for(int i = 0; i<s1.size(); i++){
            if(s1[i]!=s2[i] && !flag){
                idx=i;
                flag = 1;
                continue;
            }
            if(s1[i]!=s2[i] && flag){
                swap(s1[idx],s1[i]);
                flag = 0;
                if(s1==s2) return true;
                else return false;
            }
        }
        return flag==1?false:true;
    }
};
