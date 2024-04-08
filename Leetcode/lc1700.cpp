#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack <int> st;
        queue <int> que;
        for(int i=0;i<students.size();i++){
            que.push(students[i]);
        }
         for(int i=0;i<sandwiches.size();i++){
            st.push(sandwiches[i]);
        }

        while(!st.empty()){
            if(st.top()==que.front()){
                que.pop();
                st.pop();
            }
            else{
                int t = que.front();
                que.pop();
                que.push(t);
            }
        }

        return que.size();
    }
};