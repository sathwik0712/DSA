class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int total=requests[0];
        for(int i=1;i<requests.size();i++){
            int a=max(requests[i],requests[i-1]);
            int b=min(requests[i],requests[i-1]);
            total+=(a-b);
        }
        return total;
    }
};