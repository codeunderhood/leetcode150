# Full Dry Run

#### Input:  
58  
#### Start  
#### result = ""  
num = 58  
#### Check 1000  

58 < 1000 → skip  

#### Check 900  

58 < 900 → skip  

#### Check 500  

58 < 500 → skip  

#### Check 400  

58 < 400 → skip  

#### Check 100  

58 < 100 → skip  

#### Check 90  

58 < 90 → skip  

#### Check 50  

58 >= 50  

Append:  

L  

Now:  

#### result = "L"  
num = 8  
#### Check 10  

8 < 10 → skip  

#### Check 9  

8 < 9 → skip  

#### Check 5  

8 >= 5  

Append:  

V  

Now:  

#### result = "LV"  
num = 3  
#### Check 1  

3 >= 1  

Append:  

I  

Now:  

#### result = "LVI"  
num = 2  

Again:  

#### result = "LVII"  
num = 1  

Again:   

#### result = "LVIII"  
num = 0  

#### Finished.  

Final Answer:

LVIII
