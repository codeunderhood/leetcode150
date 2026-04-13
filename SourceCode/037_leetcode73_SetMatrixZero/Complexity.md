# ⚡ Time Complexity
## ✅ O(m × n)

Why?

Matrix size = m × n
Every step scans the matrix a constant number of times

Breakdown:

Check first row → O(n)
Check first column → O(m)
Marking step → O(m × n)
Apply markers → O(m × n)
Fix first row → O(n)
Fix first column → O(m)

👉 Total work:
O(mn + mn + m + n) ≈ O(m × n)

# 🧠 Space Complexity
## ✅ O(1) (Constant extra space)

Why?

No extra arrays used (like row[m] or col[n])
Only a few variables used:
firstRowZero
firstColZero
Matrix is modified in-place using first row & column as markers

👉 Extra memory does NOT grow with input size → constant space
