# ⚡ Time Complexity
## ✅ O(m + n)
Why?
Each element from:
nums1 (first m elements)
nums2 (all n elements)
is processed exactly once.

#### Two-pointer approach:
We compare elements one by one
Each move reduces either i, j, or both
Total operations = m + n

# 🧠 Space Complexity
## ✅ O(1) (Constant extra space)
Why?
We do in-place merging inside nums1
No extra arrays used
Only variables used:
i, j, k → pointers

👉 So extra memory does NOT grow with input size.
