#include <bits/stdc++.h> 
using namespace std;

vector <int> solve(vector<int>arr){
   priority_queue<int> pq1;
   priority_queue<int,vector<int>,greater<int>>pq2;
   for(int i=0;i<arr.size();i++){
        pq1.push(arr[i]);
        pq2.push(arr[i]);
   }

   int n = arr.size();

   vector<int>a;
   while(!pq1.empty() && !pq2.empty() && a.size()<n){
       a.push_back(pq1.top());
       pq1.pop();
       a.push_back(pq2.top());
       pq2.pop();
   }
   return a;
}


int main(){
vector <int> v ={1,2,3,4,5,6};
vector <int> ans = solve(v);
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
}

}