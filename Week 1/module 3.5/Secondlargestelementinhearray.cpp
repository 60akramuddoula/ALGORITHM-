#include <bits/stdc++.h> 
int findSecondLargest(int n, vector<int> &arr)
{
    // Write your code here.
    set<int, greater<int>>s;
    for(int i=0 ;i<arr.size();i++)
    {
        s.insert(arr[i]);
    }
    
    if(s.size()<=1) return -1;
    else{
        auto it = s.begin();
       advance(it,1);
       return *it ;
    }
}