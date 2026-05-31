# ⚡ Time Complexity ✅ O(n)

Why?

We traverse the string only once and then concatenate all rows once.

Breakdown:
Initialize rows → O(numRows)

Traverse all characters → O(n)

Merge all rows → O(n)

## 👉 Total work: O(n)

where n = length of string.

# 🧠 Space Complexity ✅ O(n)

Why?

We store all characters inside row strings before building the final answer.

We use:

rows[0]
rows[1]
...
rows[numRows-1]

## Total stored characters: n

👉 Extra space grows with input size.

Space = O(n)

because all characters are temporarily stored in row containers before creating the final output string.
