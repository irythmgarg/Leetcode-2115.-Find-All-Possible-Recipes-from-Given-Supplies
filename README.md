# Leetcode-2115.-Find-All-Possible-Recipes-from-Given-Supplies

Author: Ridham Garg
🎓 Thapar Institute of Engineering and Technology, Patiala, Punjab

---


🍽️ Recipe Maker App — Brute Force vs Optimized (Topological Sort)🧑‍🍳

This project solves the "Find All Recipes You Can Prepare" problem using two approaches:

🔹 Brute Force Method — Easy to understand, iterative

🔹 Topological Sort — Efficient and scalable using BFS graph traversal

🧩 Problem Statement
You’re given:

A list of recipes

A list of ingredients for each recipe

A set of supplies

Your goal is to return all recipes that can be prepared by using the given supplies and previously prepared recipes.

---

Input:
recipes = ["bread", "sandwich"]
ingredients = [["yeast", "flour"], ["bread", "meat"]]
supplies = ["yeast", "flour", "meat"]

Output:
["bread", "sandwich"]


---

🛠️ Approach 1: Brute Force 🔁

✅ Logic
Use a set to keep track of all available supplies.

Loop through all recipes multiple times.

If all ingredients of a recipe are found in the set, prepare it and add to the set.

🧠 Time Complexity
Worst Case: O(N² * M) where N = #recipes and M = avg #ingredients

---

⚡ Approach 2: Optimized using Topological Sort (BFS) ⚡
✅ Logic
Build a dependency graph from ingredients to recipes.

Track the number of missing ingredients (indegree) for each recipe.

Use a queue to simulate Topological Sorting:

If a recipe has indegree 0, it can be prepared.

Once prepared, decrease the indegree of other recipes depending on it.

🧠 Time Complexity
Efficient: O(N * M) — every recipe and ingredient processed once

---

🌟 Star This Project
If this helped you, please ⭐ the repo and share with your friends!
Feedback and contributions are always welcome! 💬✨

🧠 Learnings
How to use graph theory for dependency resolution

Applying Topological Sort in real-life problems

Efficient usage of unordered_set, queue, and maps in C++




