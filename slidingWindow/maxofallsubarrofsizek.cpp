#include<bits/stdc++.h> 
using namespace std;

  //mistake 1
  vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        //mistake done priority queue is not a good option as it sorts the elements 
        // and does not maintain the order of the array
      priority_queue <int> pq;
      int i;
      for( i=0;i<k;i++){
          pq.push(arr[i]);
      }
      vector<int> ans;
      ans.push_back(pq.top());
      int r=k;
      while(r<n && !pq.empty()){
          pq.pop();
          pq.push(arr[r]);
          ans.push_back(pq.top());
          r++;
      }
      
      return ans;
    }


    //mistake 2
    vector <int> max_of_subarrays(int *arr, int n, int k){
       //works good but consumes a lot of time because of the inner loop
       vector <int> ans;
       int l=0;
       int r=k-1;
       int maxel = INT_MIN;
       while(r<n){
           maxel = INT_MIN;
          for(int i=l;i<=r;i++){
              maxel = max(arr[i],maxel);
          }
          
           ans.push_back(maxel);
           r++;
           l++;
       }
       
       return ans;
    }