class Solution {
public:
    string reversePrefix(string word, char ch) {
        string s="";
        bool present=false;
        for(int i=0;i<word.size();i++){
            s+=word[i];
            if(word[i]==ch){
                reverse(s.begin(),s.end());
                present = true;
                break;
            }
        }
        if(present){
            for(int i=0;i<s.size();i++){
            word[i]=s[i];
            }
        }
        return word;
    }
};