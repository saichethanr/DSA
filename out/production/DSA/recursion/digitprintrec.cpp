#include<bits/stdc++.h> 
using namespace std;
void digitrec(int n){
    if(n==0){
        return;
    }

   
    digitrec(n/10);

            int dig = n%10;
    cout<<dig<<endl;


}

int main(){
int dig = 789;
digitrec(dig);
return 0;
}