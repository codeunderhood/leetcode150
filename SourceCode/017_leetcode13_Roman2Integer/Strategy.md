# Step-by-Step Strategy

Suppose:

s = "MCMXCIV"
## Step 1: Create Value Mapping

Store values of Roman symbols.

I → 1
V → 5
X → 10
L → 50
C → 100
D → 500
M → 1000
## Step 2: Traverse String

Check current character and next character.

## Step 3: Compare Values
##### Case 1: Smaller before larger

If:

current < next

then subtract.

Example:

IV
1 < 5
→ 5 - 1
##### Case 2: Normal addition

Otherwise add.

Example:

VI
5 > 1
→ 5 + 1


# Why This Works

Whenever smaller value appears before larger value:

Subtract smaller value

Otherwise:

Add value normally

##### This exactly follows Roman numeral rules.
