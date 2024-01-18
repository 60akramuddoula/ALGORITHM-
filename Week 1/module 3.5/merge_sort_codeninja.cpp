#include <bits/stdc++.h>
using namespace std;

vector<int> result(vector<int> &nums, int l, int r)
{
	

	if(l == r) return {nums[l]};

	int mid = (l + r) / 2;
	vector<int> left = result(nums, l, mid);
	vector<int> right = result(nums, mid + 1, r);

	int i = 0; int j= 0;
	vector<int> ans;

	while(i < left.size() && j < right.size())
	{
		if(left[i] < right[j])
		{
			ans.push_back(left[i]);
			i++;
		}
		else
		{
			ans.push_back(right[j]);
			j++;
		}
	}

	while(i < left.size())
	{
		ans.push_back(left[i]);
		i++;
	}

	while(j < right.size())
	{
		ans.push_back(right[j]);
		j++;
	}

	return ans;
}

void mergeSort(vector < int > & arr, int n) {
    arr = result(arr, 0, arr.size() - 1);
}