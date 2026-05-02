# ⚡ Time Complexity
## ✅ O(n)

Why?

We traverse the array once from index 1 to n-1.

For each element, we do only constant-time work:

comparison: prices[i] > prices[i-1]
possible addition to profit

So total operations:

(n - 1) comparisons + (at most n - 1) additions
≈ 2n operations

👉 Each element is processed exactly once
👉 No nested loops or repeated scanning

So:

each element is visited O(1) times
total work grows linearly with input size

#### ✔ Final complexity: O(n)

# 🧠 Space Complexity
## ✅ O(1) (Constant extra space)

Why?

We use only a fixed number of variables:

profit
loop index i

And input storage (vector<int> prices) is not counted as extra space.

👉 No additional arrays, stacks, or recursion used
👉 No memory grows with input size

So:

extra space remains constant regardless of n

#### ✔ Final complexity: O(1)
