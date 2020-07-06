// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        // Solution using STL lower_bound and upper_bound functions
        /*vector<int> :: iterator p1, p2;
        p1 = lower_bound(nums.begin(), nums.end(), target);
        p2 = upper_bound(nums.begin(), nums.end(), target);
        
        if(p1 == nums.end())
            return {-1,-1};
        
        if(*p1 != target)
            return {-1, -1};
        
        int l = p1-nums.begin();
        int r = p2-nums.begin()-1;
        return {l, r};*/
        
        // Solution using binary search
        int n = nums.size();
        int pos1, pos2;
        int l=0, r=n-1;
        while(r > l)
        {
            int m = (r+l)/2;
            if(nums[m] == target)
                r = m;
            else if (nums[m] > target)
                r = m-1;
            else
                l = m+1;
        }
        if(l!=r || nums[l]!=target)
            return {-1, -1};
        pos1 = l;
        
        l=0, r=n-1;
        while(r > l)
        {
            int m = (r+l+1)/2;
            if(nums[m] == target)
                l = m;
            else if (nums[m] > target)
                r = m-1;
            else
                l = m+1;
        }
        pos2 = l;
        
        return {pos1, pos2};
        
        
    }
};