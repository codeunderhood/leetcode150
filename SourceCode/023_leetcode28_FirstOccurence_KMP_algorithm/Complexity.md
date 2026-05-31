# ⚡ Time Complexity
## ✅ O(n + m)

Where:

n = length of haystack (text)
m = length of needle (pattern)
🔍 Why?
## 1️⃣ Build LPS array → O(m)

We scan the pattern once.

i moves from 1 → m-1
Each step either:
moves forward, or
falls back using LPS (but never reprocesses characters repeatedly)

👉 So total work = O(m)

## 2️⃣ Search phase → O(n)

We scan the text once.

i moves from 0 → n-1
j moves forward and sometimes jumps backward using LPS
BUT crucial rule:

👉 i never moves backward

So every character in text is processed at most once.

👉 Total work = O(n)

## 🚀 Final Time Complexity
## O(n + m)
# 🧠 Space Complexity
## ✅ O(m)

Where:

m = length of pattern
🔍 Why?

We only store:

## 1️⃣ LPS array → O(m)

Example:

ababd → [0, 0, 1, 2, 0]
## 2️⃣ Extra variables → O(1)

We use only:

i
j
len
## 🚀 Final Space Complexity
## O(m)
# ⚡ FINAL SUMMARY (INTERVIEW READY)
# ⏱ Time Complexity:
## O(n + m)
Build LPS → O(m)
Search text → O(n)
# 🧠 Space Complexity:
## O(m)
Only LPS array is extra space
