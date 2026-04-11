# ⚡ Time Complexity
## ✅ O(n)
Why? We traverse the array once
For each element:
We compare it with the current candidate
If same → increase count
If different → decrease count

### Key point:
Each element is visited exactly one time

# 🧠 Space Complexity
## ✅ O(1) (Constant extra space)
Why? We do not use any extra data structures
We only use a few variables:

candidate → stores current majority candidate
count → tracks frequency balance

👉 No extra arrays or hash maps are used
