class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, deque<int>> adjList;
        unordered_map<int, int> degree;
        for (auto& pair : pairs)
         {
            adjList[pair[0]].push_back(pair[1]);
            degree[pair[0]]++;
            degree[pair[1]]--;
        }
        
        int startNode = pairs[0][0];
        for (auto& [node, deg] : degree) {
            if (deg == 1) {
                startNode = node;
                break;
            }
        }
        
        vector<int> path;
        function<void(int)> dfs = [&](int node) {
            while (!adjList[node].empty()) {
                int nextNode = adjList[node].front();
                adjList[node].pop_front();
                dfs(nextNode);
            }
            path.push_back(node);
        };
        dfs(startNode);
        
        
        reverse(path.begin(), path.end());
        vector<vector<int>> result;
        for (int i = 1; i < path.size(); ++i) {
            result.push_back({path[i - 1], path[i]});
        }
        
        return result;
    }
};
