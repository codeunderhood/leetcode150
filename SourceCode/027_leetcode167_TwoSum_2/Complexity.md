# ⚡ Time Complexity
## ✅ O(n)

Why? We use two pointers moving from both ends of the sorted array toward the center. Each element is visited at most once.

Breakdown:
Initialize pointers → O(1)
Two-pointer traversal → O(n)
→ Each step moves either left++ or right--
→ So pointers move inward and never revisit elements

👉 Total work: O(n)

# 🧠 Space Complexity
## ✅ O(1) (Constant extra space)

Why? No extra data structure is used that grows with input size.

We only use:

left, right, sum → integer variables
result array/vector of size 2 (fixed output storage)

👉 Since the output size is constant and does not depend on input size, extra space remains constant.
