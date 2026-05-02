# ⚡ Time Complexity
## ✅ O(n)
Why?

We traverse the array only once.

For each element:

We either update minPrice
Or compute profit and update maxProfit

So total operations:

n iterations × O(1) work per iteration = O(n)

👉 Each element is processed exactly one time.

So:

each element is touched O(1) times
total work grows linearly with input size
#### ✔ Final result: O(n)

# 🧠 Space Complexity
## ✅ O(1) (Constant extra space)
Why?

We only use a fixed number of variables:

minPrice
maxProfit
i
profit (temporary)

👉 No extra arrays or data structures are created
👉 Memory usage does NOT grow with input size

So:

extra space = constant → O(1)
#### ✔ Final result: O(1)
