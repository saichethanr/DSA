#include <iostream>
#include <queue>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int>  pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        
        // while(!pq.empty()){
        //    cout<<pq.top()<<endl;
        //    pq.pop();
        // }
        int i = 1;
        while(i!=k){
            pq.pop();
            i++;
        }
        return pq.top();

    }
};