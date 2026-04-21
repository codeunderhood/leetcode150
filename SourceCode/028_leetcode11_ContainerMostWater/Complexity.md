# ⚡ Time Complexity

## ✅ O(n)

Why?
We use two pointers starting from both ends of the array and move inward based on height comparison. Each element is visited at most once.

Breakdown:

Initialize pointers (left, right) → O(1)
Two-pointer traversal → O(n)
Each step moves either left++ or right--
So every index is processed at most one time

👉 Total work: O(n)

# 🧠 Space Complexity

## ✅ O(1) (Constant extra space)

Why?
No extra data structure is used that grows with input size.

We only use:

left, right, maxArea, h, width, area → constant variables

👉 Since no additional memory scales with input size, space remains constant.
