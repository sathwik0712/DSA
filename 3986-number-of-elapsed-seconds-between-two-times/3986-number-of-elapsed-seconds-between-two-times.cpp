class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int startH=stoi(startTime.substr(0,2));
        int startM=stoi(startTime.substr(3,2));
        int startS=stoi(startTime.substr(6,2));
        int endH=stoi(endTime.substr(0,2));
        int endM=stoi(endTime.substr(3,2));
        int endS=stoi(endTime.substr(6,2));
        int start=startH*3600+startM*60+startS;
        int end=endH*3600+endM*60+endS;
        return end-start;
    }
};