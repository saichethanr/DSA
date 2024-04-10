#include<bits/stdc++.h> 
#include <vector>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
      map <int,int> mpp;
      for(int i=0;i<hand.size();i++){
        mpp[hand[i]]++;
      }
      
      while(!mpp.empty()){
        vector <int> temp;
        if(mpp.size()<groupSize){
            return false;
        }
        for(auto it:mpp){
           if(temp.empty()){
              temp.push_back(it.first);
           }
           else{
            if(temp.back()+1 == it.first){
                  temp.push_back(it.first);
            }
            else{
                return false;
            }
           }
           
           mpp[it.first]--;
           if(mpp[it.first]==0){
            mpp.erase(it.first);
           }
           if(temp.size()==groupSize){
            break;
           }
        }
        
      }
      if(mpp.empty()){
        return true;
      }
    return false;    
    }
};