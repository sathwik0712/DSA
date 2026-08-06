class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
        string lows=to_string(low);
        string highs=to_string(high);
        vector<int>seq;
        for(int i=lows.size();i<=highs.size();i++)
            for(int j=0;j<=9-i;j++){
                string n=s.substr(j,i);
                int num=stoi(n);
                if(num>=low && num<=high)
                    seq.push_back(num);
        }
        return seq;
    }
};