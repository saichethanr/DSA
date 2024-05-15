#include<bits/stdc++.h> 
using namespace std;

class Solution{
public:
    int solve(int i,int j,int arr[]){
        if(i==j){
            return 0;
        }
        int mini = 1e9;
        for(int k=i;k<j;k++){
            int steps = (arr[i-1] * arr[k] * arr[j]) + solve(i,k,arr) + solve(k+1,j,arr);
            if(steps<mini){
                mini=steps;
            }
        }
        return mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
       return solve(1,N-1,arr);     
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driv