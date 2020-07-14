// https://leetcode.com/problems/bitwise-ors-of-subarrays/

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int n = A.size();
        unordered_set<int> result, cur_res;
        
        // After the i'th step cur_res contains the values A[j] | ... | A[i] for all j<=i
        // The size of cur_res is atmost 32
        for(int i=0; i<n; i++)
        {
            unordered_set<int> S;
            S.insert(A[i]);
            for(auto num : cur_res)
                S.insert(A[i] | num);
            
            for(auto num : S)
                result.insert(num);
            
            cur_res = S;
        }
        
        return result.size();
    }
};