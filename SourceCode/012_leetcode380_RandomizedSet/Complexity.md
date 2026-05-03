# ⚡ Time Complexity
## ✅ O(1) (Average Case)
Why?

All operations are designed using HashMap + Array, which allows constant-time operations on average.

#### 🔹 Insert → O(1)

We directly:

push element at end of array
store its index in hashmap

👉 Both operations are constant time.

#### 🔹 Remove → O(1)

We:

find index using hashmap → O(1)
swap with last element → O(1)
pop from array → O(1)
update hashmap → O(1)

👉 No shifting or traversal is required.

#### 🔹 GetRandom → O(1)

We:

generate random index
directly access array element

👉 Array indexing is constant time.

👉 Key Point:

Even though multiple internal operations happen, each step is constant time, so overall complexity remains O(1) average for all operations.

# 🧠 Space Complexity
## ✅ O(n)
Why?

We store all elements in two data structures:

#### 🔹 Array (vector)

Stores all inserted values → O(n)

#### 🔹 HashMap (value → index)

Stores mapping of each value to its position → O(n)

👉 Key Point:

Every inserted element is stored once in array and once in hashmap, so total space grows linearly with number of elements.

🚀 Final Insight

✔ Array → supports fast random access
✔ HashMap → supports fast lookup
✔ Together → guarantee O(1) operations

👉 This trade-off of extra space enables optimal time performance.
