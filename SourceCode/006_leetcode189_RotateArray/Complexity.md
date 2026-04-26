# ⚡ Time Complexity

## ✅ O(n)

Why?

We perform 3 reversals:

reverse whole array → O(n)
reverse first k elements → O(k)
reverse remaining n−k elements → O(n−k)

So total work:

n + k + (n - k) = 2n → O(n)

👉 Every element is swapped a constant number of times (at most a few swaps total).

So:

each element is touched O(1) times
total operations scale linearly
# 🧠 Space Complexity

## ✅ O(1) (Constant extra space)

Why?

We do everything in-place:

only swapping elements inside the same array
no extra arrays created
only a few variables used:
start
end
temp
k

👉 These do NOT grow with input size.

So:

extra space = constant → O(1)
