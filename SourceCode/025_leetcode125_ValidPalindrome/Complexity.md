# ⚡ Time Complexity

## ✅ O(n)
Why? We traverse the string once using two pointers
For each character:
We check if it is alphanumeric
If not, we skip it
If yes, we compare characters from both ends

Key point:
Each character is visited at most one time

# 🧠 Space Complexity

## ✅ O(1) (Constant extra space)
Why? We do not create any new string
We use two pointers directly on the input string:

i → left pointer
j → right pointer

👉 No extra arrays or data structures are used
