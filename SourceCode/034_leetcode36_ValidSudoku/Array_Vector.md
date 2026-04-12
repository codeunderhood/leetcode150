# 📊 Array vs Vector in C++ (Complete Comparison)
## Feature	- Array (int arr[9])	- Vector (vector<int>)
🔹 Memory type	- Stack memory -	Heap memory

🔹 Size	 - Fixed at compile time	- Dynamic (can grow/shrink)

🔹 Performance	-  Faster access -	Slightly slower (extra overhead)

🔹 Memory overhead -	Very low -	Higher (size, capacity tracking)

🔹 Cache locality	- Excellent -	Good but slightly worse

🔹 Resizing -	Not possible	- Automatic resizing

🔹 Initialization	- Simple	- Needs constructor / runtime setup

🔹 Safety -	No bounds checking	- Optional bounds checking (at())

# Best use case	- Fixed-size problems -	Dynamic-size problems
# Example usage	- Sudoku, matrices (fixed) -	Lists, graphs, streams


# 🧠 Why ARRAY is used in THIS Sudoku problem?
## 🔹 1. Fixed size input (MOST IMPORTANT)
Sudoku board is ALWAYS: 9 × 9. So we already know the size in advance.
👉 No need for dynamic memory → vector is unnecessary.

## 🔹 2. Faster execution
We only do: 81 iterations. constant-time checks.
Arrays give:
direct memory access (no overhead)
👉 Slightly faster than vector in tight loops.

## 🔹 3. Simpler logic
We don’t need:
vector<int> rows(9);
We just write:
int rows[9];
👉 Cleaner and easier to explain in interviews.

## 🔹 4. No need for dynamic features
We never:
resize
push_back
shrink/grow
👉 So vector features are not used at all

# 🎯 Final Interview Answer (Perfect)
👉 We used arrays instead of vectors because the Sudoku board size is fixed (9×9), so we do not need dynamic memory allocation. Arrays provide faster access, lower memory overhead, and simpler implementation. Since the size is known at compile time, vectors would only add unnecessary overhead without any benefit.

# 💡 One-line memory trick
👉 “Fixed size → array (fast & simple), dynamic size → vector (flexible but heavier)”
