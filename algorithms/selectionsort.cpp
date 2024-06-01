#include<bits/stdc++.h>
using namespace std;


void selectionsort(vector<int>&arr){
   int n = arr.size();
   for(int i=0;i<n-1;i++){
        int mini = i;
         for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
         }
         swap(arr[i],arr[mini]);
   }


}
int main(){
    vector<int> arr = {1,6,4,2,3,9,5};
    selectionsort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
}