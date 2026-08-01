class Solution {
public:
    int countValidPrefixes(string s) {
        int count1=0,count0=0,prefixcount=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')
                count1++;
            else
                count0++;
            if((count1==count0-1) || count0==count1-1 || count0==count1)
                prefixcount++;
        }
        return prefixcount;
    }
};