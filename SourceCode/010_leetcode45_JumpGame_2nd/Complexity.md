# ⚡ Time Complexity
## ✅ O(n)
Why? We traverse the array only once from left to right. For each index i, we:

update the farthest reachable index (farthest = max(farthest, i + nums[i]))
check if we have reached the end of the current jump range (i == rangeEnd)
increase jump count and extend the range when needed

👉 Key point: Each element is processed exactly once in a single linear scan, and no nested loops are used.

# 🧠 Space Complexity
## ✅ O(1) (Constant extra space)
Why? We do not use any extra array or auxiliary data structure. We only maintain a few integer variables:

jumps → counts number of jumps
rangeEnd → end of current jump boundary
farthest → farthest reachable index
i → loop index

👉 Key point: Memory usage does not grow with input size, so space complexity remains constant.
