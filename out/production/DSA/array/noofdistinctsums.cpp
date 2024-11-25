#include<bits/stdc++.h> 
using namespace std;

vector<int> solve(int n,vector<int>v){
    vector<int> ans;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=v[j];
            ans.push_back(sum);
        }
    }

    return ans;
}

int main(){
    vector<int>v = {1,2,3};
    int n = v.size();
    vector<int> a = solve(n,v);
    set <int> st;
    for(int i=0;i<a.size();i++){
        st.insert(a[i]);
    }

    cout<<st.size()<<endl;
}