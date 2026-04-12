# ⚡ Time Complexity
## ✅ O(n²)

Why?

Matrix size = n × n
Every operation (transpose / reverse rows / reverse columns) touches each element at most once
Breakdown:
Transpose → visits upper triangle ≈ n²/2
Reverse rows → visits all elements ≈ n²
Reverse columns → visits all elements ≈ n²

👉 Total work is still proportional to:
n² + n² + n² ≈ O(n²)


# 🧠 Space Complexity
## ✅ O(1) (Constant extra space)

Why?

All operations are in-place
No extra matrix is created
