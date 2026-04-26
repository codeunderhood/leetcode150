# 🧠 Role of k % n in array rotation

👉 k % n is used to normalize the number of rotations.

## ⚡ Simple meaning

If array size is n, rotating it n times brings it back to the same array.

So extra full cycles don’t matter.

rotate by n → same array
rotate by 2n → same array
rotate by 3n → same array
## 🧩 Simple example (n = 5)
#### Start:
[1,2,3,4,5]
#### After 1:
[5,1,2,3,4]
#### After 2:
[4,5,1,2,3]
#### After 3:
[3,4,5,1,2]
#### After 4:
[2,3,4,5,1]
#### After 5:
[1,2,3,4,5]  ✅ same as original
## 🧩 One-line memory trick
👉 “Array rotation is a circle — after one full circle (n steps), nothing changes.”

## 📌 Why we use k % n

We reduce unnecessary work:

k = k % n;

This means:

“Only keep the effective rotations”

## 🧩 Example 1
nums = [1,2,3,4,5]
n = 5
k = 7

Without mod:

rotate 7 times ❌

With mod:

k = 7 % 5 = 2

So we just rotate by 2 ✔️

## 🧩 Example 2 (bigger k)
n = 6
k = 100
k % n = 100 % 6 = 4

👉 So 100 rotations = same as 4 rotations

## 🧠 Why this works (intuition)

Because rotation is cyclic:

after every n steps → array repeats

## So anything beyond n is just repeating full cycles.

# ⚡ Without k % n problem

If you don’t use it:
unnecessary work
wasted time
sometimes wrong indexing in code

# 👉 k % n means:
“Remove full rotations, keep only what actually changes the array”
