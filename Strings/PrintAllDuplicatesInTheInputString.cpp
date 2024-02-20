#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void  helper(string s){
    
    int n = s.length();
    unordered_map<char,int> hashmap;
    for(auto c : s) hashmap[c]++;
    
    for(auto itr : hashmap){
        cout<<itr.first<<" "<<itr.second<<"\n";
    }
    
}
int main() {
    // std::cout << "Become the programmer you're meant to be!" << std::endl;
    string s = "geeksforgeeks";
    helper(s);
    return 0;
}
