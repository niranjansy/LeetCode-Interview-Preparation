// https://leetcode.com/problems/couples-holding-hands/

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int N = row.size();
        map<int, int> pos;
        for(int i=0; i<N; i++)
            pos[row[i]] = i;
        int count = 0;
        for(int i=0; i<N; i+=2)
        {
            if(row[i] % 2 == 0)
            {
                if(row[i+1] != (row[i]+1))
                {
                    pos[row[i+1]] = pos[row[i]+1];
                    swap(row[i+1], row[pos[row[i]+1]]);
                    pos[row[i]+1] = i+1;
                    count++;
                }
                    
            }
            else
            {
                if(row[i+1] != (row[i]-1))
                {
                    pos[row[i+1]] = pos[row[i]-1];
                    swap(row[i+1], row[pos[row[i]-1]]);
                    pos[row[i]-1] = i+1;
                    count++;
                } 
            }
        }
        
        return count;
    }
};