# ⚡ Time Complexity
## ✅ O(m × n)

Why?
We traverse the entire matrix multiple times, but each pass is linear over all cells.

Breakdown:
First pass (apply rules + encoding) → O(m × n)
→ Each cell is visited once to compute next state
Neighbor counting per cell → O(8) (constant)
→ 8 directions checked, but constant work
Second pass (final conversion 2 → 0, 3 → 1) → O(m × n)

👉 Total work:
O(m × n + m × n) = O(m × n)

# 🧠 Space Complexity
## ✅ O(1) (Constant extra space)

Why?
No extra matrix is created. We modify the board in-place using encoding:

0 → dead → dead
1 → live → live
2 → live → dead
3 → dead → live

We only use:

direction array (fixed size 8)
a few integer variables (m, n, row, col, count)
