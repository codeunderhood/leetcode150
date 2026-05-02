# ⚡ Time Complexity
## ✅ O(n)
Why?
We traverse the array once from left to right.
For each index i, we:

check if i is reachable (i > maxReach)
compute i + nums[i]
update maxReach if needed

👉 Key point: Each element is processed exactly one time in a single pass.

# 🧠 Space Complexity
## ✅ O(1) (Constant extra space)

Why?
We do not use any extra array or data structure.
We only maintain a few variables:

maxReach → stores farthest reachable index
i → loop index
temporary variable reachFromHere (optional)
