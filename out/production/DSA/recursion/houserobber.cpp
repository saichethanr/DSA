#include<bits/stdc++.h> 

    void robrec(vector <int>  &  t,int i,int sum,int &maxi){
        if(i>=t.size()){
            maxi = max(maxi,sum);
            return;
        }

        rob(t,i+2,sum+t[i],maxi);
        rob(t,i+1,sum,maxi);
    }
    int rob(vector<int>& nums) {
        int maxi = INT_MIN;
        int i=0;
        int sum=0;
        robrec(nums,i,sum,maxi);
        return maxi;
    }
     
     int main(){

     }