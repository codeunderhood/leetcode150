# ⚡ Time Complexity : ✅ Normal Solution (Two Pointers)
## ✅ O(n)
Why? We scan string t once using two pointers. Each character is visited at most one time. Key point: Linear traversal with no backtracking.

# ⚡ Time Complexity : 🚀 Follow-up Solution (Many Queries)
## ✅ Preprocessing: O(n)
Why? We traverse string t once and store indices of each character.

## ⚡ Per Query: O(m log n)
Why? For each character in s, we use binary search (or upper_bound) on stored index list to find next valid position.

👉 If there are k queries:
➡ Total = O(n + k * m log n)

# 🧠 Space Complexity : ✅ Normal Solution
## ✅ O(1)
Why? We use only two pointers (i, j). No extra data structures are used.

👉 No additional memory apart from input variables.

# 🧠 Space Complexity : 🚀 Follow-up Solution
## ✅ O(n)
Why? We store positions of each character of string t in arrays / vectors. In worst case, all characters are stored.

👉 Extra space is required for preprocessing only.

# 🔥 SUMMARY
## 👉 Normal approach: single pass, two pointers → O(n) time, O(1) space
## 👉 Follow-up: preprocess + binary search → O(n + k * m log n) time, O(n) space
