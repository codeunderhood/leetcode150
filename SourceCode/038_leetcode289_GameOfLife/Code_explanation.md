# ⚙️ Step-by-step Strategy
## Step 1: Define directions

Store all 8 neighbor movements:

(-1,-1), (-1,0), (-1,1),
(0,-1),         (0,1),
(1,-1), (1,0), (1,1)
## Step 2: Traverse the grid

Loop through every cell:

for each row in [0, m)
  for each col in [0, n)
## Step 3: Count live neighbors

For each cell:

Check all 8 directions
Make sure indices are within bounds
Count neighbors that are:
1 (live → live)
2 (live → dead, but originally live)

👉 So condition:

if (board[newRow][newCol] == 1 || board[newRow][newCol] == 2)
## Step 4: Apply rules using encoding

Now decide the new state:

If current cell is live (1):
Live neighbors < 2 → dies → mark 2
Live neighbors 2 or 3 → stays alive → keep 1
Live neighbors > 3 → dies → mark 2
If current cell is dead (0):
Live neighbors == 3 → becomes alive → mark 3
## Step 5: Second pass (finalize board)

Convert encoded values:

2 → 0 (dead)
3 → 1 (alive)
