# 🧩 One-line summary
## 🟦 Stock I: Max difference between two points
## 🟩 Stock II: Sum of all increasing slopes
## ============================================
## | Problem             | Strategy                     |
## | ------------------- | ---------------------------- |
## | Stock I             | 1 transaction only           |
## | Stock II            | sum all upward moves         |
## | Stock with cooldown | DP required (state tracking) | --> need to check this later
## ============================================

This question BuySellStock_2 feels confusing at first because it looks like you need to decide the best single buy and sell point. But the key twist is:

You are allowed to buy and sell multiple times, as long as you never hold more than one stock at a time.

That rule completely changes the strategy.

## 🧠 First, understand what “profit” really means here

Profit is only made when:

you buy at a lower price and sell at a higher price later

So the real goal is:

capture all upward movements in price
ignore downward movements
## 🔍 Why compare with previous day?

Because every movement in price can be broken into tiny steps:

Instead of:

1 → 5

We think of it as:

1 → 2 → 3 → 4 → 5

Now observe:

1 → 2 = +1 profit
2 → 3 = +1 profit
3 → 4 = +1 profit
4 → 5 = +1 profit

Total = 4

👉 This is exactly the same as:

buy at 1, sell at 5 → profit = 4

So instead of finding one big transaction, we just add all small increases.

📌 Core Idea (Greedy Insight)

Whenever:

prices[i] > prices[i - 1]

It means:

price went up today
so if you had bought yesterday and sold today → profit exists

So we simply take:

profit += prices[i] - prices[i - 1]
🧠 Intuition in Simple Words

Think of it like this:

“If the price went up from yesterday to today, I pretend I bought yesterday and sold today.”

Even though we are not actually doing multiple trades explicitly, mathematically it gives the same result.

📊 Example Breakdown
prices = [7, 1, 5, 3, 6, 4]

Let’s visualize:

Step 1: 7 → 1 ❌

Price dropped → no profit

Step 2: 1 → 5 ✔

Gain = 4

Step 3: 5 → 3 ❌

Drop → ignore

Step 4: 3 → 6 ✔

Gain = 3

Step 5: 6 → 4 ❌

Drop → ignore

Total:

4 + 3 = 7
🔥 Why this works (important insight)

Instead of choosing:

best buy day
best sell day

We are using this trick:

Every upward slope is a small independent profit opportunity

And summing them gives the optimal answer.

🧩 Another way to think about it

Imagine you always:

buy at the bottom of every small dip
sell at the next peak

But instead of tracking peaks and dips manually, we shortcut it by:

just adding every positive difference between consecutive days

⚡ One-line intuition

“Total profit is the sum of all increases between consecutive days.”

## =======================================
🧠 What the rule actually allows

“You can buy and sell multiple times, but you can hold at most one stock.”

This means:

You are allowed to close one trade and open another immediately
But you can’t hold two stocks at once

So practically:
👉 You can “reset” your position every day

🔥 Why this changes the strategy

Because now you are allowed to do:

Instead of:

Buy → wait → Sell (once)

You can do:

Buy → Sell → Buy → Sell → Buy → Sell ...

Even on consecutive days.

📊 What this enables (key insight)

Suppose prices are:

[1, 2, 3, 4, 5]
With rule (multiple transactions allowed)

You can do:

buy 1, sell 2 → +1
buy 2, sell 3 → +1
buy 3, sell 4 → +1
buy 4, sell 5 → +1

Total = 4

❌ What if this rule did NOT exist?

Now imagine:

You are allowed only ONE transaction total.

That means:

you can buy once
and sell once

You must choose best pair (i, j):

Example:

[1, 2, 3, 4, 5]

Best choice:

buy at 1
sell at 5
= profit 4

Still same result here

But now consider:

[7, 1, 5, 3, 6, 4]
Only ONE transaction allowed:

Best is:

buy at 1
sell at 6
= profit 5
🧠 So what changes conceptually?
With multiple transactions allowed:

You can:

capture every upward movement separately

So:

sum of all small increases
Without that rule (only 1 transaction):

You must:

find the single best low → high pair

So:

max(prices[j] - prices[i]) for j > i
⚡ Key Difference (Very Important)
Rule	Strategy
Only 1 buy + 1 sell	Find best single interval
Multiple transactions allowed	Sum all upward slopes
🧩 Intuition (simple mental model)
If multiple transactions are allowed:

“I can lock profit every time price goes up.”

If NOT allowed:

“I must wait for the best possible peak, ignoring small gains.”

🔥 Why greedy works only with this rule

Because:

every increase is independent
no need to “save capacity” for later trades
you are never penalized for selling early

So:

local gains = global optimal answer

## =======================================
Here’s a clear comparison between Stock I (Best Time to Buy and Sell Stock) and Stock II (multiple transactions allowed) so you can see exactly how the rules change the strategy.

# 📊 Stock I vs Stock II
#### Feature	     ----->         🟦 Stock I	      ---->   🟩 Stock II
#### Transactions allowed	 --> Only 1 buy + 1 sell	 --> Multiple buy/sell allowed
#### Holding stock	--> Can hold only 1 stock -->	Can hold only 1 stock
#### Goal	 --> Max profit from single trade	 --> Max profit from all small trades
#### Strategy type -->	Dynamic programming / greedy min-max	--> Greedy accumulation
#### Core idea	--> Find best (sell - buy) pair	 --> Sum all positive increases
#### Time complexity	--> O(n)	--> O(n)
#### Example input	--> [7,1,5,3,6,4]	--> [7,1,5,3,6,4]
#### Output	--> 5	--> 7

🧠 Stock I Logic (Single Transaction)
Idea:

Buy at lowest point, sell at highest point after it

You track:

minimum price so far
maximum profit
Example:
[7, 1, 5, 3, 6, 4]

Best:

buy = 1
sell = 6
profit = 5

👉 You ignore all other opportunities because only one trade is allowed.

🧠 Stock II Logic (Multiple Transactions)
Idea:

Take every upward movement

You add:

(2 - 1)
(3 - 2)
(4 - 3)
(5 - 4)
Same array:
[7, 1, 5, 3, 6, 4]

Profit:

1→5 = 4
3→6 = 3
total = 7
🔥 Key Insight Difference
🟦 Stock I (One trade only)

You must wait for best global peak

“Pick one perfect buy and sell moment”

🟩 Stock II (Multiple trades)

You can lock profit anytime price increases

“Collect every small rise”

📉 Visual intuition
Prices:
7 → 1 → 5 → 3 → 6 → 4
Stock I thinking:
Ignore small ups and downs
Focus only on best valley → peak

1 → 6 = +5
Stock II thinking:
Break into small rises:

1 → 5 = +4
3 → 6 = +3

Total = 7
⚡ Why both give different answers

Because Stock II allows:

“cash out profit multiple times”

Stock I does NOT allow that:

“you must wait for one final exit”

# 🧩 One-line summary
## 🟦 Stock I: Max difference between two points
## 🟩 Stock II: Sum of all increasing slopes
