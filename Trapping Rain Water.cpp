// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        int trapped_water = 0;
        
        int i=0;
        while(i < (n-1))
        {
            int max_height = 0;  
            int max_pos;
            // Finding height of the tallest bar that is shorter than the current bar, or the first bar that is taller than the current bar, among all bars to the right of the current bar
            for(int j=i+1; j<n; j++)
            {
                if(height[j] >= max_height)
                {
                    max_height = height[j];
                    max_pos = j;
                }
                if(height[j] > height[i])
                    break;
            }
            // Trapping water in between these 2 bars
            int h = min(height[i], height[max_pos]);
            for(int j=i+1; j<max_pos; j++)
            {
                trapped_water += (h - height[j]);
            }
            
            i = max_pos;
            
        }
        
        return trapped_water;
    }
};