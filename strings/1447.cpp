#include<bits/stdc++.h> 
#include <string>
using namespace std;
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector <string> ans;
        map <float,int> mpp;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(mpp.find(float(i)/j)==mpp.end()){
                    mpp[float(i)/j]=1;
                    ans.push_back(to_string(i)+'/'+to_string(j));
                }
            }
        }
        return ans;
    }
};