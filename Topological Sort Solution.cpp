class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        // Step 1: Add all initial supplies to a set for O(1) lookup
        unordered_set<string> st;
        for (string str : supplies)
            st.insert(str);

        // Step 2: Create a mapping from ingredient to list of recipes that need it
        unordered_map<string, vector<int>> mp;

        // Step 3: Track indegree (i.e., number of missing ingredients) for each recipe
        vector<int> indegree(recipes.size(), 0);

        for (int i = 0; i < recipes.size(); i++) {
            for (string str : ingredients[i]) {
                // If the ingredient is not in initial supplies
                if (st.find(str) == st.end()) {
                    mp[str].push_back(i);  // This recipe depends on str
                    indegree[i]++;         // Increment missing ingredients count
                }
            }
        }

        // Step 4: Use a queue to process all recipes that can be made initially (indegree = 0)
        queue<string> q;
        for (int i = 0; i < recipes.size(); i++) {
            if (indegree[i] == 0)
                q.push(recipes[i]);
        }

        // Step 5: Topological sort using BFS
        vector<string> ans;
        while (!q.empty()) {
            string top = q.front();
            q.pop();
            ans.push_back(top);
            
            // Reduce indegree of recipes that require 'top' as an ingredient
            for (int i : mp[top]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(recipes[i]);  // All ingredients available, can prepare
                }
            }
        }

        return ans;  // Return all recipes that can be prepared
    }
};
