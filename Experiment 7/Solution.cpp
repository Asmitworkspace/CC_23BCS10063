class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f: flights){
            adj[f[0]].push_back({f[1], f[2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<tuple<int,int,int>> q; 
        q.push({src, 0, 0});

        while(!q.empty()){
            auto [node, cost, steps] = q.front();
            q.pop();

            if(steps > k) continue; 

            for(auto &it : adj[node]){
                int nextNode = it.first;
                int price = it.second;

                if(cost + price < dist[nextNode]){
                    dist[nextNode] = cost + price;
                    q.push({nextNode, dist[nextNode], steps + 1});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
