# 🧠 Understanding PREFIX vs SUFFIX for "abab"

We take substring: 

"abab"  

Now we list proper prefixes and proper suffixes.  

## 🔵 1. PREFIXES (start from index 0)  

Prefixes = starting parts, but NOT full string.  

For "abab":  

Prefixes:  
"a"  
"ab"  
"aba"  

## ❌ we do NOT include "abab"  

## 🔴 2. SUFFIXES (end at last index)  

Suffixes = ending parts, but NOT full string.  

For "abab":  

Suffixes:  
"b"  
"ab"  
"bab"  
## 🔥 3. NOW FIND COMMON MATCH

We compare both sets:  

Prefixes:  
a, ab, aba  
Suffixes:  
b, ab, bab  
✔ COMMON MATCH:  
"ab"  
#### 🧠 WHAT THIS MEANS  

We found:  

#### 👉 longest string which is BOTH prefix and suffix = "ab"

So:  

length = 2  
## 🎯 FINAL RESULT
lps[3] = 2  
