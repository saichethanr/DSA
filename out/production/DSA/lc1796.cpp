#include<bits/stdc++.h> 
#include <string>
using namespace std;



class Solution {
public:
    int secondHighest(string s) {
        priority_queue <int> pq;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                int num = s[i] - '0';
                pq.push(num);
            }
        }
        if(pq.empty()){
            return -1;
        }
        int maxi = pq.top();
        while(pq.top()==maxi && !pq.empty()){
            pq.pop();
        }
        if(pq.empty()){
            return -1;
        }
        return pq.top();
    }
};