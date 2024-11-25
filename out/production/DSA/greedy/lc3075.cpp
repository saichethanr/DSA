#include<bits/stdc++.h> 
#include <vector>
using namespace std;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int>pq;
        int cnt=1;
        for(int i=0;i<happiness.size();i++){
            pq.push(happiness[i]);
        }
        
        long long int sum=0;
        while(k>0 && !pq.empty()){
            sum+=pq.top();
            pq.pop();
            
            if(pq.top()>cnt && !pq.empty()){
                int t = pq.top()-cnt;
                pq.pop();
                pq.push(t);
            }
            else{
                break;
            }
            cnt++;
            k--;
        }

        return sum;
    }
};

//correct answer
class Solution {
public:
    long long maximumHappinessSum(vector<int>& v, int k) {
       sort(v.begin(),v.end());
       reverse(v.begin(),v.end());
       int cnt=1;
       long long int sum=0;
       int i=0;
       while(k--){
          v[i] = max(v[i]-i,0);
          sum+=v[i++];
       } 
       return sum;
    }
};