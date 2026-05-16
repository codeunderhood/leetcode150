# ⚡ Key difference (VERY IMPORTANT)
#### Feature -->	Trapping Rain Water	-- Container With Most Water
#### Goal -->	total water at every index	-- max water between 2 lines
#### Scope -->	whole array	 -- two pointers only
#### Water depends on --> 	leftMax & rightMax per index --	min(height[i], height[j])
#### Width matters -->	implicit (unit width per bar) --	explicit (distance between i & j)
#### Nature -->	accumulation problem --	optimization problem

## 🌊 1. Trapping Rain Water (your current problem)
Problem idea:

You are given heights and you want to know:

“How much water gets trapped between bars after raining?”

Key rule:

Water depends on boundaries on BOTH sides for every index.

For each index i:

#### water[i]=min(leftMax[i],rightMax[i])−height[i]

## 🏢 2. Container With Most Water
Problem idea:

You pick two lines and form a container:

“Which two bars can hold the maximum water?”

Key rule:

Only the two chosen boundaries matter, not all points.

#### area=min(height[i],height[j])×(j−i)
