# ⚡ Time Complexity

## ✅ O(m × n)
Why? Every element of the matrix is visited exactly once during spiral traversal, regardless of direction changes.

# 🧠 Space Complexity

## ✅ O(m × n) (output array)
Why? We store all matrix elements in a result array of size m × n.

## ✅ O(1) extra space
Why? Only a constant number of variables are used (top, bottom, left, right pointers), which do not grow with input size.
