class Solution {
public:

   vector<int> mergesort(vector<int>&nums, int l,int r)
    {
      if(l < 0 || r >= nums.size()) return {};
        if(l==r) return {nums[l]};
            int mid= (l+r)/2;
            vector<int>left= mergesort(nums, l, mid);
            vector<int>right= mergesort(nums, mid+1, r);
            int i=0 ;
            int j= 0;
            vector<int>res;
            while(i<left.size() && right.size())
            {
                if(left[i]<= right[j])
                {
                    res.push_back(left[i]);
                    i++;
                }
                else
                {
                    res.push_back(right[j]);
                    j++;
                }
            }

            while(i<left.size())
            {
                res.push_back(left[i]);
                i++;
            }
            while(j<right.size())
            {
                res.push_back(right[i]);
                j++;
            }
                
        
        return res;
        
    }

     void send(vector<int>&nums)
     {
         mergesort(nums, 0, nums.size()-1);
     }
    
    vector<int> sortArray(vector<int>& nums) 
    {
        send(nums);
      return nums;
    }
};