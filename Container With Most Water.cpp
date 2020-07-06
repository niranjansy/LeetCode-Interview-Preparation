// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        int i=0; 
        int j=n-1;
        
        // Keep 2 pointers at the 2 ends of the array
        // Move the pointer that is pointing to the smaller number, one step towards the other end of the array
        
        int max_area = 0;
        while(j > i)
        {
            int area = (j-i) * min(height[i], height[j]);
            if(area > max_area)
                max_area = area;
            
            if(height[i] < height[j])
                i++;
            else if(height[i] > height[j])
                j--;
            else
            {
                i++;
                j--;
            }
        }
        
        return max_area;
    }
};