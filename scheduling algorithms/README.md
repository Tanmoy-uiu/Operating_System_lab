<div align="center">

# ⚡ CPU Scheduling Algorithms in C++

### FIFO • SJF • STCF • Round Robin

<img src="https://img.shields.io/badge/C%2B%2B-11-blue.svg">
<img src="https://img.shields.io/badge/Algorithms-CPU%20Scheduling-green.svg">
<img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg">
<img src="https://img.shields.io/badge/Platform-Linux%20%7C%20Windows-orange.svg">

---

A collection of classic CPU Scheduling Algorithm implementations using C++.

</div>

---

# 📚 Implemented Algorithms

| Algorithm | Type | Description |
|---|---|---|
| FIFO / FCFS | Non-Preemptive | Executes processes in arrival order |
| SJF | Non-Preemptive | Selects shortest burst time |
| STCF / SRTF | Preemptive | Selects shortest remaining time |
| Round Robin | Preemptive | Uses fixed time quantum |

---

# 🗂️ Project Structure

```text
.
├── fifo.cpp
├── sjf.cpp
├── stcf.cpp
├── round_robin.cpp
└── README.md
```

---

# ⚙️ Features

✅ Completion Time Calculation  
✅ Turnaround Time Calculation  
✅ Response Time Calculation  
✅ Average Metrics  
✅ Preemptive Scheduling  
✅ Non-Preemptive Scheduling  
✅ Queue-Based Scheduling  

---

# 🧠 Algorithms Overview

---

## 🔹 FIFO / FCFS

### 📌 Description
Processes are executed exactly in the order they arrive.

### 📌 Characteristics
- Non-preemptive
- Simple implementation
- Can suffer from convoy effect

---

## 🔹 SJF (Shortest Job First)

### 📌 Description
The process with the smallest burst time is selected first.

### 📌 Characteristics
- Non-preemptive
- Efficient average waiting time
- Requires burst time prediction

---

## 🔹 STCF / SRTF

### 📌 Description
Preemptive version of SJF.

CPU always selects the process with the shortest remaining burst time.

### 📌 Characteristics
- Preemptive
- Better turnaround time
- More context switching

---

## 🔹 Round Robin

### 📌 Description
Each process receives CPU for a fixed time quantum.

After quantum expiration, the process moves to the back of the ready queue.

### 📌 Characteristics
- Preemptive
- Fair scheduling
- Suitable for time-sharing systems

---

# 📥 Example Input

| Process | Arrival Time | Burst Time |
|---|---|---|
| P1 | 0 | 8 |
| P2 | 1 | 4 |
| P3 | 2 | 9 |
| P4 | 3 | 5 |

---

# 📊 Metrics Calculated

## ✅ Completion Time (CT)

The time when a process finishes execution.

---

## ✅ Turnaround Time (TAT)

```text
TAT = Completion Time - Arrival Time
```

---

## ✅ Response Time (RT)

```text
RT = First CPU Allocation Time - Arrival Time
```

---

# 🛠️ Requirements

- C++11 or later
- g++ compiler

---

# 🚀 Compilation & Execution

---

## 🔹 FIFO

### Compile

```bash
g++ fifo.cpp -o fifo
```

### Run

```bash
./fifo
```

Windows:

```bash
fifo
```

---

## 🔹 SJF

### Compile

```bash
g++ sjf.cpp -o sjf
```

### Run

```bash
./sjf
```

Windows:

```bash
sjf
```

---

## 🔹 STCF / SRTF

### Compile

```bash
g++ stcf.cpp -o stcf
```

### Run

```bash
./stcf
```

Windows:

```bash
stcf
```

---

## 🔹 Round Robin

### Compile

```bash
g++ round_robin.cpp -o rr
```

### Run

```bash
./rr
```

Windows:

```bash
rr
```

---

# 🖥️ Sample Output

```text
ID      ARR     BURST   COMP    TAT     RESP
P1      0       8       8       8       0
P2      1       4       12      11      7
P3      2       9       26      24      15
P4      3       5       17      14      9
```

---

# 📈 Scheduling Comparison

| Algorithm | Preemptive | Selection Rule |
|---|---|---|
| FIFO / FCFS | ❌ No | Arrival Order |
| SJF | ❌ No | Shortest Burst |
| STCF / SRTF | ✅ Yes | Shortest Remaining Time |
| Round Robin | ✅ Yes | Time Quantum |

---

# 🎯 Concepts Covered

- CPU Scheduling
- Operating Systems
- Queues
- Process Management
- Time Sharing
- Turnaround Time
- Response Time
- Preemptive Scheduling
- Non-Preemptive Scheduling

---

# 🔮 Future Improvements

- Priority Scheduling
- Lottery Scheduling
- Multi-Level Feedback Queue (MLFQ)
- Waiting Time Calculation
- Gantt Chart Visualization

---

<div align="center">

# 👨‍💻 Author

## Tanmoy

Made with ❤️ using C++

</div>
