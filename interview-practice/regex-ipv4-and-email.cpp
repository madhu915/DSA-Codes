#include<iostream>
#include<regex>
using namespace std;
#include <bits/stdc++.h> 
bool isValidIPv4(string s) {
    // Write your code here.
   int p=s.length();
   int n1=0;
   int count=0;
   
   for(int i=0;i<p;i++){
        //invalid character
       if(s[i]>='1' && s[i]<='9' || s[i]=='.' || s[i]=='0'){
            if(s[i]!='.'){
                //number till next dot
                n1=n1*10+int(s[i]-'0');
                if(n1<0 || n1>255 )
                    return false;
            }
            else{
                count++;
                n1=0;
            }
        }
       else
           return false;
   }
   if(count>3 || count<3 ||s[p-1]=='.')
       return false;
   return true;

}
bool isvalidEmail(string s){
    //optional underscore/period
    regex email("([a-zA-Z0-9]+)(\\.|_)?([a-zA-Z0-9]*)@([a-zA-Z]+)(\\.([a-zA-Z]+))+");
    return regex_match(s,email)!=0;

}
int main(){
    regex pattern("(([0-9]|[1-9][0-9]|[1][0-9][0-9]|[2][0-9][0-9]|[2][0-5][0-5])\\.){3}([0-9]|[1-9][0-9]|[1][0-9][0-9]|[2][0-9][0-9]|[2][0-5][0-5])");
    
    cout<<regex_match("8.8.8.8", pattern);
    cout<<"\n"<<isValidIPv4("8.8.8.255");
    cout<<"\n"<<isvalidEmail("abc@svce.ac.in.");
    return 0;

    // TC:O(N)
    // SC:O(1)

}