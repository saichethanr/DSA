#include<bits/stdc++.h> 
using namespace std;    


// You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

// Return the minimum number of boats to carry every given person.


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();
        int numboats=0;
        int l=0;
        int r=n-1;
        int sum=0;

        while(l<=r){
            if((people[l]+people[r])<=limit){
                r--;
                l++;
            }
            else{
                r--;
            }
            numboats++;
        }

        return numboats;

    }
};