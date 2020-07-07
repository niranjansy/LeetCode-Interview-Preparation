// https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    vector<pair<int,int>> Adj[101];
    int Time[101];
    int Visited[101];

    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // Building adjacency list
        for(int i=0; i<times.size(); i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            Adj[u].push_back(make_pair(v, w));
        }
        
        for(int i=1; i<=N; i++)
        {
            Visited[i] = 0;
            Time[i] = INT_MAX;
        }
        
        Time[K] = 0;
        
        //Implementing Djikstra's Shortest Path algorithm
        
        set<pair<int, int>> S;
        S.insert(make_pair(0, K));
        
        while(!S.empty())
        {
            pair<int, int> P = *(S.begin());
            S.erase(S.begin());
            int u = P.second;
            Visited[u] = 1;
            
            for(int i=0; i<Adj[u].size(); i++)
            {
                int v = Adj[u][i].first;
                if(Visited[v])
                    continue;
                int w = Adj[u][i].second;
                if(Time[v] != INT_MAX)
                    S.erase(S.find(make_pair(Time[v], v)));
                
                if(Time[v] > (Time[u] + w))
                    Time[v] = Time[u] + w;
                S.insert(make_pair(Time[v], v));
            }
        }
        
        int max_time=0;
        for(int i=1; i<=N; i++)
        {
            if(Time[i] > max_time)
                max_time= Time[i];
        }
        
        if(max_time == INT_MAX)
            return -1;
        
        return max_time;
    }
};