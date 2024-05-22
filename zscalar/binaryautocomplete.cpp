#include<bits/stdc++.h>
using namespace std;
class Trie{
    public:
        map<int,int> hot;
        map<int,unordered_map<int,int>> trie;
        map<int,int> index;
        int curr =0;
        void insert(string& s,int ind){
            int p=0;
            for(int i=0;i<s.size();i++){
                int temp = s[i]-'0';
                if(trie.count(p)==0 || trie[p].count(temp)==0){
                    trie[p][temp] = ++curr;
                }
                p = trie[p][temp];
                index[p] = ind;
            }
            hot[p]++;
        }
        int search(string& s){
            int p =0;
            for(int i=0;i<s.size();i++){
                int temp = s[i]-'0';
                if(trie.count(p)==0 || trie[p].count(temp)==0) return false;
                p = trie[p][temp];
            }
            return hot[p];
        }
        bool pref(string& s){
            int p =0;
            for(int i=0;i<s.size();i++){
                int temp = s[i]-'0';
                if(trie.count(p)==0 || trie[p].count(temp)==0) return false;
                p = trie[p][temp];
            }
            return true;
        }
        int longest_pref(string& s,int ind){
            int p =0;
            int last_ind = -1;
            for(int i=0;i<s.size();i++){
                if(trie.count(p)==0 || trie[p].count(s[i]-'0')==0) break;
                p = trie[p][s[i]-'0'];
                last_ind = index[p];
            }
            insert(s,ind);
            return last_ind;
        }
};
int main(){
    vector<string> arr = {"000","1110","01","001","110","11"};
    Trie* t = new Trie();
    for(int i=0;i<arr.size();i++){
        int val = t->longest_pref(arr[i],i);
        if(val==-1 && i==0) cout<<0<<" ";
        else if(val==-1) cout<<i<<" ";
        else cout<<val+1<<" ";
    }
    return 0;
}