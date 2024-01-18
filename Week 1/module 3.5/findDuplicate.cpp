#include <bits/stdc++.h>




 vector<int>mergesort(vector<int>&arr, int l, int r)
 {
	 if(l==r) return{ arr[l]};
	 int mid= (l+r)/2;
	 vector<int> left= mergesort(arr, l, mid);
	 vector<int> right= mergesort(arr, mid+1, r);

	 int i= 0;
	 int j=0 ;
	 vector<int> s;
	 while(i< left.size() && j<right.size())
	 {
		 if(left[i]<=right[j])
		 {
			s.push_back(left[i]);
			i++;
		 }
		 else 
		 {
			 s.push_back(right[j]);
			 j++;
		 }
	 }
	 while(i<left.size()) 
	 {
		 s.push_back(left[i]);
		 i++;
	 }
	 while(j<right.size())
	 {
		 s.push_back(right[j]);
		 j++;
	 }
	 return s;
 }

void send(vector<int>&nums)
{
	nums=mergesort(nums, 0, nums.size()-1);
}
int findDuplicate(vector<int> &arr, int n)
{
	
	send(arr);
	for(int i=1;i<n;i++)
	{
		if(arr[i]== arr[i-1]) // sorted ache tai ei logic 
		{
			return arr[i];
		}
	}
}
