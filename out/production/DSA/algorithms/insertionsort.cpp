#include<bits/stdc++.h>
using namespace std;


void insertionsort(vector<int>&arr){
      int n = arr.size();
      for(int i =0;i<n;i++){
        int j =i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
      }

}
int main(){
    vector<int> arr = {1,6,4,2,3,9,5};
    insertionsort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
}