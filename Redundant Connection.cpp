// https://leetcode.com/problems/redundant-connection/

class Solution {
public:
    int Id[1001];
    int Rank[1001];
    
    int Find(int i)
    {
        if(Id[i] != i)
            Id[i] = Find(Id[i]);
        return Id[i];
    }
    
    void Union(int i, int j)
    {
        int p = Find(i);
        int q = Find(j);
        if(Rank[p] > Rank[q])
            Id[q] = p;
        else
            Id[p] = q;
        if(Rank[p] == Rank[q])
            Rank[q]++;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        for(int i=1; i<=N; i++)
        {
            Id[i] = i;
            Rank[i] = 0;
        }
        
        for(int i=0; i<N; i++)
        {
            if(Find(edges[i][0]) == Find(edges[i][1]))
                return edges[i];
            Union(edges[i][0], edges[i][1]);
        }
        return {};
    }
};