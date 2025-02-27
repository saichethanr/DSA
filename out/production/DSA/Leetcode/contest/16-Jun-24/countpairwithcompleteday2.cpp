#include<bits/stdc++.h> 
using namespace std;

//a very wrong approach 
//wrong answer
        class Solution {
        public:
            long long solve(int l,int r, vector<int>&hours){
                if(l>r){
                    return 1;
                }
                int match = 0;
                int nomatch=0;
                if((hours[l]+hours[r])%24==0){
                    match = 1+solve(l+1,r-1,hours);
                }
                else{
                    nomatch = solve(l+1,r,hours) + solve(l,r-1,hours);
                }
                
                return match+nomatch;
                
            }
            long long countCompleteDayPairs(vector<int>& hours) {
                long long ans = solve(0,hours.size()-1,hours);
                return ans;
            }
        };


//correct answer

    class Solution {
    public:
        
        long long countCompleteDayPairs(vector<int>& hours) {
            unordered_map<int, int> modCount;
            long long countPairs = 0;
        
                for (int hour : hours) {
                    int mod = hour % 24;
                    int complement = (24 - mod) % 24;

                    if (modCount.find(complement) != modCount.end()) {
                        countPairs += modCount[complement];
                    }

                    modCount[mod]++;
                }

                return countPairs;
        }
    };