<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<title>Jump Game - Real vs Intuition</title>

<style>
body {
    font-family: Arial;
    background: #0f172a;
    color: white;
    text-align: center;
    padding: 20px;
}

.section {
    margin-top: 30px;
    padding: 15px;
    border-radius: 10px;
}

.real { background: #020617; }
.intuition { background: #111827; }

.container {
    display: flex;
    justify-content: center;
    gap: 8px;
    margin-top: 20px;
    flex-wrap: wrap;
}

.box {
    width: 50px;
    height: 50px;
    background: #334155;
    border-radius: 8px;
    display: flex;
    align-items: center;
    justify-content: center;
    position: relative;
}

.box::after {
    content: attr(data-i);
    position: absolute;
    bottom: -16px;
    font-size: 10px;
    color: #94a3b8;
}

/* STATES */
.active { background: #22c55e; }
.used { background: #3b82f6; }
.option { background: #f59e0b; }
.best { background: #38bdf8; }
.fail { background: #ef4444; }

button {
    margin: 10px;
    padding: 10px 18px;
    border: none;
    border-radius: 8px;
    background: #f59e0b;
    cursor: pointer;
}

.info {
    margin-top: 15px;
    background: #1e293b;
    padding: 12px;
    border-radius: 8px;
    text-align: left;
    line-height: 1.6;
}

.maxBox {
    font-size: 18px;
    margin-top: 10px;
    color: #22c55e;
}
</style>
</head>

<body>

<h2>Jump Game: REAL vs INTUITION</h2>

<button onclick="start()">Start</button>
<button onclick="next()">Next Step</button>

<!-- REAL -->
<div class="section real">
<h3>✅ REAL (maxReach logic)</h3>
<div id="realMax" class="maxBox">maxReach: 0</div>
<div class="container" id="realBoard"></div>
<div class="info" id="realInfo"></div>
</div>

<!-- INTUITION -->
<div class="section intuition">
<h3>🧠 INTUITION (only options)</h3>
<div class="container" id="intBoard"></div>
<div class="info" id="intInfo"></div>
</div>

<script>
let nums = [4,1,2,0,2,0,1,3,2,1,4];

let i = 0;
let maxReach = 0;
let done = false;

let realBoxes = [];
let intBoxes = [];

function start() {
    i = 0;
    maxReach = 0;
    done = false;

    realBoard.innerHTML = "";
    intBoard.innerHTML = "";

    nums.forEach((v, idx) => {
        let r = document.createElement("div");
        r.className = "box";
        r.innerText = v;
        r.setAttribute("data-i", idx);
        realBoard.appendChild(r);

        let t = document.createElement("div");
        t.className = "box";
        t.innerText = v;
        t.setAttribute("data-i", idx);
        intBoard.appendChild(t);
    });

    realBoxes = document.querySelectorAll("#realBoard .box");
    intBoxes = document.querySelectorAll("#intBoard .box");

    realInfo.innerHTML = "Start stepping...";
    intInfo.innerHTML = "";
    updateMax();
}

function updateMax() {
    realMax.innerText = "maxReach: " + maxReach;
}

function clearAll() {
    [...realBoxes, ...intBoxes].forEach(b =>
        b.classList.remove("active","used","option","best","fail")
    );
}

function next() {

    if (done || i >= nums.length) return;

    clearAll();

    // ===== REAL LOGIC =====
    realBoxes[i].classList.add("active","used");

    if (i > maxReach) {
        realBoxes[i].classList.add("fail");
        realInfo.innerHTML = `i=${i} > maxReach=${maxReach} ❌ cannot proceed`;
        done = true;
        return;
    }

    let reach = i + nums[i];
    let msg = `i=${i}<br>`;

    if (reach > maxReach) {
        msg += `✔ within range (i ≤ ${maxReach})<br>`;
        msg += `🚀 expands maxReach → ${reach}`;
        maxReach = reach;
    } else {
        msg += `✔ within range (i ≤ ${maxReach})<br>`;
        msg += `➖ no expansion`;
    }

    updateMax();
    realInfo.innerHTML = msg;

    if (maxReach >= nums.length - 1) {
        realInfo.innerHTML += "<br><br>🎉 can reach end";
        done = true;
    }

    // ===== INTUITION (ONLY OPTIONS) =====
    let jump = nums[i];
    let options = [];

    for (let j=1; j<=jump; j++) {
        let idx = i+j;
        if (idx < nums.length) options.push(idx);
    }

    options.forEach(idx => {
        intBoxes[idx].classList.add("option");
    });

    intBoxes[i].classList.add("active","used");

    // 🔥 ONLY INDEX LIST
    intInfo.innerHTML = options.length > 0
        ? `Options: ${options.join(", ")}`
        : `Options: none`;

    i++;
}
</script>

</body>
</html>
