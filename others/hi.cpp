#include<bits/stdc++.h> 
using namespace std;

int main(){
vector<pair<int,int>>v  = {{2,1},{5,7},{1,2}};

for(int i=0;i<v.size();i++){
    int t = v[i].first;
    v[i].first = v[i].second;
    v[i].second = t;
}

for(int i=0;i<v.size();i++){
    
}

}