# 📊 ⚡ Bucket Sort Method (Frequency / Count Array)
## ⚡ Time Complexity

#### ✅ O(n)

Why?
We traverse the citations array once to build the frequency (bucket) array.

Then we traverse the bucket array once from right to left to compute the H-index.

So total operations are linear in the size of input:

First pass: count frequencies → O(n)
Second pass: compute cumulative papers → O(n)

👉 Key point: Even though we use a bucket array, each element is processed a constant number of times, so overall complexity remains linear.

## 🧠 Space Complexity

#### ✅ O(n)

Why?
We use an extra frequency array (bucket) of size n + 1 to store citation counts.

bucket[0] to bucket[n] → extra storage proportional to input size

👉 Key point: Auxiliary space grows linearly with input size due to frequency mapping.

# 📊 ⚡ Sorting Method (Descending / Greedy Scan)
## ⚡ Time Complexity

#### ✅ O(n log n)

Why?
The dominant cost is sorting the array:

Sorting citations → O(n log n)
Single traversal from right to left → O(n)

So total:

👉 O(n log n + n) = O(n log n)

👉 Key point: Sorting dominates the runtime.

## 🧠 Space Complexity

#### ✅ O(1) or O(log n) (depending on sorting implementation)

Why?

If in-place sort (like heap sort / optimized quicksort variants): auxiliary space is O(1)
If recursive quicksort: recursion stack uses O(log n) space

👉 No extra arrays are used for computation (unlike bucket method)

👉 Key point: Space usage is minimal compared to bucket approach.

# 🧾 Final Comparison Summary
## Method	  ->  Time Complexity  ->  Space Complexity
## Bucket   ->  (Count Array) O(n)	->  O(n)
## Sorting + Scan	->  O(n log n)	->  O(1) / O(log n)
