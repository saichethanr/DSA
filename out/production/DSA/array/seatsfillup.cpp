#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        //sort both the arr and find abs diff and sum it up yo get the ans
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int sum=0;
        for(int i=0;i<seats.size();i++){
            sum+=(abs(seats[i]-students[i]));
        }

        return sum;

    }
};