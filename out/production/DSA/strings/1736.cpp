#include<bits/stdc++.h> 
#include <string>
using namespace std;

// You are given a string time in the form of  hh:mm, where some of the digits in the string are hidden (represented by ?).

// The valid times are those inclusively between 00:00 and 23:59.

// Return the latest valid time you can get from time by replacing the hidden digits.


class Solution {
public:
    string maximumTime(string time) {
        string hour = time.substr(0,2);
        string min = time.substr(3,2);

        if(hour[0]=='?' && hour[1]!='?'){
            int h = hour[1] - '0';
            if(h>3){
                hour[0] ='1';
            }
            else{
               hour[0] ='2';
            }
           
        }
        if(hour[0]!='?' && hour[1]=='?'){
            if(hour[0]=='2'){
                hour[1] = '3';
            }
            else{
                hour[1] = '9';
            }
        }
        if(hour[0]=='?' && hour[1]=='?'){
            hour[0]='2';
            hour[1]='3';
        }

        if(min[0]=='?' && min[1]!='?'){
            min[0]='5';
        }
        if(min[0]!='?' && min[1]=='?'){
            min[1] = '9';
        }
        if(min[0]=='?' && min[1]=='?'){
            min[0]='5';
            min[1] ='9';
        }
        string ans = hour + ":" + min;
        return ans;;
    }
};