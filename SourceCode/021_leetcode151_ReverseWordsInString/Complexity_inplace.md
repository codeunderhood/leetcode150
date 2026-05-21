# ⚡ Time Complexity

## ✅ O(n)

Why?

Each character is visited a constant number of times.

Breakdown:
Reverse whole string → O(n)
Reverse each word → O(n)
Remove extra spaces → O(n)

👉 Total work: O(n)

# 🧠 Space Complexity

## ✅ O(1) (Constant extra space)

Why?

No extra array/vector/string used for storing words.

We only use:

pointers/indices
temporary variables

All operations happen inside the same string.

👉 Extra space remains constant.
