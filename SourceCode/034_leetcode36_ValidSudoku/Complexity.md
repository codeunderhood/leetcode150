# 🟦 1. 2D Array Method
# ⚡ Time Complexity

## ✅ O(9 × 9) = O(81) = O(1)
Why? We traverse every cell of the 9×9 Sudoku board exactly once.

Each cell performs constant-time operations:

check in rows[i][num]
check in cols[j][num]
check in boxes[boxIndex][num]

Since the board size is fixed (9×9), total operations are always 81.

👉 Because Big-O ignores constants and does not consider fixed-size inputs, O(81) simplifies to O(1).

# 🧠 Space Complexity

## ✅ O(9 × 9 × 3) = O(243) = O(1)
Why? We use three fixed-size 2D arrays:

rows[9][9]
cols[9][9]
boxes[9][9]

Total storage = 243 integers.

👉 Since Sudoku size is fixed and does not grow with input, the extra memory is constant.
👉 Therefore space complexity is O(1).

# 🟪 2. Bitmask Method
# ⚡ Time Complexity

## ✅ O(9 × 9) = O(81) = O(1)
Why? We again visit every cell exactly once.

For each cell, we perform constant-time bitwise operations:

& (AND check)
| (OR update)
<< (bit shift)

Total work = 81 constant operations.

👉 Since input size is fixed (9×9), this is constant time.
👉 Therefore time complexity is O(1).

# 🧠 Space Complexity

## ✅ O(9 + 9 + 9) = O(27) = O(1)
Why? We use:

rows[9]
cols[9]
boxes[9]

Each integer stores 9 bits using bitmasking.

Total = 27 integers.

👉 This memory usage does not depend on input size (Sudoku is fixed 9×9).
👉 Therefore space complexity is O(1).
