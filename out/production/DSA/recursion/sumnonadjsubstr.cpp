#include<bits/stdc++.h> 
using namespace std;
void sumsub(vector <int> &t,int i,int sum, int &maxi){
    if(i>=t.size()){
        maxi = max(maxi,sum);
        return;
    }
    sumsub(t,i+2,sum+t[i],maxi);

    sumsub(t,i+1,sum,maxi);
}

int main(){
    int maxi = INT_MIN;
    int i=0;
    int sum=0;
    vector <int> t = {2,1,4,9};
    sumsub(t,i,sum,maxi);
    cout<<maxi<<endl;
    return 0;
}