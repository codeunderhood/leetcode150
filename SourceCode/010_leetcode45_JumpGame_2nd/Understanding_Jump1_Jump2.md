# ⚔️ Jump Game I vs Jump Game II
#### Feature	--> 🟦 Jump Game I	--> 🟨 Jump Game II
#### Problem Type -->	Can you reach the last index?	 --> Minimum jumps to reach last index
####  Goal	Return  -->	true/false	 -->	Return minimum number of jumps
####  Decision vs Optimization  -->		Decision problem	 -->	Optimization problem
####  Output	 -->	Boolean (Yes/No)	  -->	Integer (min jumps)
####  Core Idea	 -->	Track farthest reachable index	 -->	Track farthest + jump boundaries
####  Greedy Strategy  -->		Maintain maxReach  -->		Maintain farthest + rangeEnd
## Key Condition	 -->	If i > maxReach → fail	 -->	If i == rangeEnd → make a jump
####  Complexity Goal  -->		Reachability check  -->		Minimum steps calculation
####  Time Complexity  -->		O(n)  -->		O(n)
####  Space Complexity  -->	O(1)	 -->	O(1)
####  Difficulty	 --> Easier -->	Medium
####  Real Insight -->	“Can I reach?” -->	“How efficiently can I reach?”
