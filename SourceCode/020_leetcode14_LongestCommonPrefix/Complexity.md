# ⚡ Time Complexity
## ✅ O(n × m)

Why?
n = number of strings
m = length of smallest string

We compare each character with all strings.

Breakdown:
Traverse characters → O(m)
Compare with all strings → O(n)

👉 Total work:

O(n × m)

# 🧠 Space Complexity
## ✅ O(1) (Constant extra space)

Why?

No extra data structure grows with input size.

We only use:

i, j, current
prefix array (fixed size)

👉 Extra memory remains constant.
