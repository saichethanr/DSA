#include<bits/stdc++.h> 
using namespace std;

int pivotInteger(int n) {
        vector <int> s;
        vector <int> e;
        int sumend=0;
        int sumstart=0;
        for(int i=1;i<=n;i++){
            sumstart+=i;
            s.push_back(sumstart);
        }
        for(int i=n;i>=1;i--){
            sumend+=i;
            e.push_back(sumend);
        }
        reverse(e.begin(),e.end());
        for(int i=0;i<s.size();i++){
            if(s[i]==e[i]){
                return i+1;
            }
           
        }
      
        return -1;

    }

int main(){
    int ans = pivotInteger(8);
    cout<<ans<<endl;
    return 0;
}