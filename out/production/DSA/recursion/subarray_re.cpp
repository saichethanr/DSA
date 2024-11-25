#include<bits/stdc++.h> 
using namespace std;
void subarray(vector<int> &t,int s,int e){
 if (e == t.size()) {
        return;
    
}  
    if(s > e) {
        cout << endl;
        subarray(t, 0, e + 1);
    } 
    else{
        for (int i = s; i <= e; i++) {
            cout << t[i] << " ";
        }
       
        cout << endl;
        subarray(t, s + 1, e);
    }
  
}
int main(){
    vector <int> t = {1,2,3,4,5};
    vector <int> temp;
    int e=0;
    int s=0;
    subarray(t,s,e);
    return 0;
}