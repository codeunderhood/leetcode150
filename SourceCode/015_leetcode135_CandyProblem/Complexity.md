# ⚡ Time Complexity
## ✅ O(n)

Why?

We traverse the ratings array only two times:

Left → Right pass
Right → Left pass

Each loop visits every child only once.

Breakdown
Initialize candies array → O(n)
for(i = 0; i < n; i++)

Every child gets 1 candy initially.

Left → Right traversal → O(n)
for(i = 1; i < n; i++)

Checks:

ratings[i] > ratings[i-1]

Ensures higher-rated child gets more candies than LEFT neighbor.

Each index visited once.

Right → Left traversal → O(n)
for(i = n-2; i >= 0; i--)

Checks:

ratings[i] > ratings[i+1]

Ensures higher-rated child gets more candies than RIGHT neighbor.

Each index visited once.

Final sum calculation → O(n)
for(i = 0; i < n; i++)

Adds all candies.

##### 👉 Total work:

O(n) + O(n) + O(n) + O(n)
= O(4n)

Ignoring constants:

#### ✅ Final Time Complexity = O(n)

# 🧠 Space Complexity
## ✅ O(n)

Why?

We use an extra candies array of size n.

int candies[n];

or

vector<int> candies(n);

This array stores candies for every child.

Extra Space Used
candies array → O(n)

Stores candy count for all children.

Other variables → O(1)

We only use:

i, total, needed

which are constant-size integer variables.

#### 👉 Since the candies array grows proportionally with input size n:

##### ✅ Final Space Complexity = O(n)
