// Given a 5x6 snakes and ladders board, find the minimum number of dice throws required to reach the destination or 
// last cell (30th cell) from the source (1st cell).
// You are given an integer N denoting the total number of snakes and ladders and an array arr[] of 2*N 
// size where 2*i and (2*i + 1)th 
// values denote the starting and ending point respectively of ith snake or ladder. 
// The board looks like the following.
// Note: Assume that you have complete control over the 6 sided dice. No ladder starts from 1st cell.



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    pair<int,int> findcor(int dice){
        int r = 5-1-(dice-1)/5;
        int c = (dice-1)%6;
        if(r%2==5%2){
            return {r,6-1-c};
        }
        else{
            return {r,c};
        }
    }

    unordered_map<int,int> mapit(int N, int arr[]){
        unordered_map<int,int> mpp;
        for(int i = 0; i < 2 * N; i += 2){
            mpp[arr[i]] = arr[i + 1];
        }
        return mpp;
    }

    int minThrow(int N, int arr[]){
        vector<vector<bool>> vis(5, vector<bool>(6, false));
        queue<int> q;
        vis[4][0] = true;
        q.push(1);
        int minsteps = 0;
        while(!q.empty()){
            int size = q.size();
            for(int j = 0; j < size; j++){
                int cur = q.front();
                q.pop();
                if(cur == 30){
                    return minsteps;
                }
                for(int k = 1; k <= 6; k++){
                    int next = cur + k;
                    if(next > 30){
                        break;
                    }
                    
                    pair<int,int> p = findcor(next);
                    int x = p.first;
                    int y = p.second;
                    if(x>=0 && y >=0 && vis[x][y]){
                        continue;
                    }
                    if(x >= 0 && x < 5 && y >= 0 && y < 6 && !vis[x][y]){
                        vis[x][y] = true;
                        unordered_map<int,int> mpp = mapit(N, arr);
                        if(mpp.find(next) != mpp.end()){
                            q.push(mpp[next]);
                        }
                        else{
                            q.push(next);
                        }
                    }
                }
            }
            minsteps++;
        }
        return minsteps; // If destination is not reachable
    }
};

