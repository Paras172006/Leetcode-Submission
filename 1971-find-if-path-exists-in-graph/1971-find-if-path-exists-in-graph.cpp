class Solution {
public:
   bool solve(vector<vector<int>>& edges, unordered_map<int,vector<int>>& mp,int source, int destination,vector<bool>& vis){
      if(source == destination){
          return true;
      }
      if(vis[source] == true){
        return false;
      }
      vis[source] = true;
      for(auto &node : mp[source]){
           if(solve(edges,mp,node,destination,vis) == true){
            return true;
           }
      }

      return false;
   }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // int n = edges.size();
        unordered_map<int,vector<int>> mp;
        for(vector<int> edge : edges){
            int u = edge[0];
            int v = edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
           
        }

        vector<bool> vis(n,false);
        return solve(edges,mp,source,destination,vis);
    }
};