# ⚡ Time Complexity

## ✅ O(n)

Why?

We use two pointers:

left starts from beginning
right starts from end

In every iteration:

either left++
or right--

Each element is visited only once.

Breakdown:
Initialize variables → O(1)
Two-pointer traversal → O(n)
→ Each iteration moves one pointer inward
→ No element is revisited

👉 Total work: O(n)

# 🧠 Space Complexity

## ✅ O(1) (Constant extra space)

Why?

No extra array or data structure is used.

We only store:

left
right
leftMax
rightMax
totalWater

These variables take constant memory.

👉 Extra space does not grow with input size.
