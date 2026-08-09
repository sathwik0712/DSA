class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n1=prices.size(),n2=discounts.size();
        double sum=0;
        sort(prices.begin(),prices.end());
        reverse(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        reverse(discounts.begin(),discounts.end());
        int i=0,j=0;
        while(i< n1 && j<n2 ){
            double temp=prices[i]*(100-discounts[j])/100.0;
            sum+=temp;
            i++;
            j++;
        }
        while(i<n1){
            sum+=prices[i];
            i++;
        }
        return sum;
    }
};