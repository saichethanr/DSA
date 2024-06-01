#include<bits/stdc++.h> 
using namespace std;

void merge(vector<int>&arr,int l,int m,int h){
      vector<int> temp;
      int left = l;
      int right = m+1;
      while(left<=m && right<=h){
             if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
             }
             else{
                temp.push_back(arr[right]);
                right++;
             }
      }

      while(left<=m){
        temp.push_back(arr[left]);
        left++;
      }
      while(right<=h){
        temp.push_back(arr[right]);
        right++;
      }
      //did not understand this thing
      for(int i=l;i<=h;i++){
        arr[i] = temp[i-l];
      }


}

void ms(int l,int h,vector<int>&arr){
    if(l>=h){
        return;
    }
    int m = (l+h)/2;
    ms(l,m,arr);
    ms(m+1,h,arr);
    merge(arr,l,m,h);
}

int main(){
    vector<int> arr = {1,5,6,4,3,2};
    int n = arr.size();
    ms(0,n-1,arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
}