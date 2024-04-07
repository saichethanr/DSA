#include<bits/stdc++.h> 
using namespace std;    


// You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array fruits, return the maximum number of fruits you can pick.



    int brute(vector<int>& s) {
        unordered_map <int,int> mpp;
        int maxf = 0;
        int l=0;
        int r=0;
        while(r<s.size()){
            if(mpp.find(s[r])==mpp.end() &&  mpp.size()<2){
                mpp[s[r]]++;
                maxf++;
            }
            else if(mpp.find(s[r])!=mpp.end()){
                mpp[s[r]]++;
                maxf++;
            }
            else if(mpp.find(s[r])==mpp.end() && mpp.size()==2){
                 while(mpp.size()==2){
                    mpp[s[l]]--;
                    if(mpp[s[l]]==0){
                        mpp.erase(s[l]);
                    }
                    l++;
                 }
                 
            }
            r++;
        }
        return maxf;
    }


      int better(vector<int>& s) {
        unordered_map <int,int> mpp;
        int maxf = 0;
        int l=0;
        int r=0;
        while(r<s.size()){
            mpp[s[r]]++;

            while(mpp.size()>2){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                l++;
            }

            maxf = max(maxf,r-l+1);
            r++;
        }
        return maxf;
    }

