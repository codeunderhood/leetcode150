# ⚡ Time Complexity

## ✅ O(m + n)

Why?
r moves from 0 → m-1 → m steps
l also moves from 0 → m-1 → m steps max
building need[] takes O(n)

So total:

O(m + n)

👉 Each character is processed at most twice (once by r, once by l)

# 🧠 Space Complexity

## ✅ O(1) (constant space)

Why?
We use fixed-size arrays:
vector<int> need(128)
vector<int> window(128)
Size does NOT depend on input length

So:

O(128 + 128) → O(1)
