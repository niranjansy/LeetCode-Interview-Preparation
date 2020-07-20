// https://leetcode.com/problems/sum-of-distances-in-tree/

class Solution {
public:
    vector<int> Adj[10000];
    int Size[10000];
    vector<int> Sums;
    int Num;
    
    void DFS1(int v, int p)
    {
        Size[v] = 1;
        for(int i=0; i<Adj[v].size(); i++)
        {
            int u = Adj[v][i];
            if(u != p)
            {
                DFS1(u, v);
                Size[v] += Size[u];
                Sums[v] += Sums[u] + Size[u];
            }
        }
    }
    
    void DFS2(int v, int p)
    {
        Size[v] = 1;
        for(int i=0; i<Adj[v].size(); i++)
        {
            int u = Adj[v][i];
            if(u != p)
            {
                Sums[u] = Sums[v] - Size[u] + (Num - Size[u]);
                DFS2(u, v);
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        
        Num = N;
        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }
        
        for(int i=0; i<N; i++)
        {
            Sums.push_back(0);
            Size[i] = 0;
        }
            
        // Assign node 0 to be the root of the tree
        /* DFS1 computes the size of subtree rooted at every node, 
           and the sum of distances between every node and all nodes in its subtree*/
        
        DFS1(0, 0);
        
        // At the end of DFS1, only the root has the required sum of distances from all nodes
        //  Using the roots's sum, we compute the sums for all other nodes in DFS2
        
        DFS2(0, 0);
        
        return Sums;
    }
};