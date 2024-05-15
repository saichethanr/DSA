#include<bits/stdc++.h> 
#include <vector>
using namespace std;

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {   
        sort(arr,arr+n);
        sort(dep,dep+n);
    	int ans=1;
    	//we are comparing the second arrival train and the second departure train
    	int i=1;
    	int j=0;
    	//let the
    	int plat=1;
    	while(i<n && j<n){
    	    if(arr[i]<=dep[j]){
    	        plat++;
    	        i++;
    	    }
    	    else if(arr[i] > dep[j]){
    	        plat--;
    	        j++;
    	    }
    	    
    	    ans = max(plat,ans);
    	}
    	
    	return ans;
    }
};
