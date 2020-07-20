// https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> Adj[200001];
    bool Visited[200001];
    bool RS[200001];
    vector<int> TopoSort;
    
    bool DFS(int v) 
    { 
        // Mark the current node as visited and part of recursion stack 
        Visited[v] = true; 
        RS[v] = true; 
        bool FoundCycle = false;

        // Recur for all the vertices adjacent to this vertex 
        for(int i = 0; i < Adj[v].size(); ++i) 
        { 
            int u = Adj[v][i];
            if (!Visited[u])
                FoundCycle = DFS(u); 
            else if (RS[u]) 
                FoundCycle = true; 
            if(FoundCycle == true)
                return true;
        } 
        RS[v] = false;  // remove the vertex from recursion stack 
        
        TopoSort.push_back(v);  // Update topological sort ordering

        return FoundCycle; 
    } 
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        
        for(int i=0; i<n; i++)
        {
            RS[i] = false;
            Visited[i] = false;
        }
        
        for(int i=0; i<prerequisites.size(); i++)
        {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            Adj[u].push_back(v);
        }
        
        int flag = 0;
        for(int i=0; i<n; i++)
        {
            if(!Visited[i])
            {
                flag = DFS(i);
                if(flag == 1)
                    break;
            }
        }
        
        if(flag == 1)
            return {};
        
        reverse(TopoSort.begin(), TopoSort.end());
        return TopoSort;
    }
};