class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // Store all available supplies in a set for O(1) lookup
        unordered_set<string> present;
        for(string st : supplies) {
            present.insert(st);
        }

        vector<string> ans;

        // Run up to N iterations to ensure recipes that depend on other recipes are also considered
        for(int k = 0; k < recipes.size(); k++) {
            for(int i = 0; i < recipes.size(); i++) {
                // Skip already prepared recipes
                if(present.find(recipes[i]) != present.end())
                    continue;

                bool presenty = true; // Flag to check if all ingredients are available

                // Check if all ingredients of the current recipe are available
                for(string ingred : ingredients[i]) {
                    if(present.find(ingred) == present.end()) {
                        presenty = false;
                        break; // Optimization: exit early if any ingredient is missing
                    }
                }

                // If all ingredients are present, the recipe can be made
                if(presenty) {
                    ans.push_back(recipes[i]);      // Add recipe to the answer list
                    present.insert(recipes[i]);     // Mark recipe as now available
                }
            }
        }

        return ans; // Return all recipes that can be prepared
    }
};
