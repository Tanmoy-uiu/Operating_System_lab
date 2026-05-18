# CPU Scheduling Algorithms in C++

This project contains implementations of several classic CPU Scheduling Algorithms using C++.

The project demonstrates both preemptive and non-preemptive scheduling techniques and calculates important scheduling metrics such as:

- Completion Time
- Turnaround Time
- Response Time
- Average Turnaround Time
- Average Response Time

---

# Implemented Algorithms

## 1. FIFO / FCFS (First Come First Serve)

Processes are executed in the exact order they arrive.

### Characteristics
- Non-preemptive
- Simple scheduling algorithm
- Can suffer from convoy effect

---

## 2. SJF (Shortest Job First)

The process with the smallest burst time is selected first.

### Characteristics
- Non-preemptive
- Minimizes average waiting time
- Requires burst time prediction

---

## 3. STCF / SRTF (Shortest Time to Completion First)

Preemptive version of SJF.

At every time unit, the CPU selects the process with the shortest remaining burst time.

### Characteristics
- Preemptive
- Better average turnaround time
- Higher context switching

---

## 4. Round Robin (RR)

Each process gets CPU for a fixed time quantum.

After the quantum expires, the process is moved to the back of the ready queue.

### Characteristics
- Preemptive
- Fair scheduling
- Good for time-sharing systems

---

# Project Structure

```text
.
├── fifo.cpp
├── sjf.cpp
├── stcf.cpp
├── round_robin.cpp
└── README.md
```

---

# Example Input Processes

| Process | Arrival Time | Burst Time |
|----------|--------------|-------------|
| P1 | 0 | 8 |
| P2 | 1 | 4 |
| P3 | 2 | 9 |
| P4 | 3 | 5 |

---

# Metrics Calculated

## Completion Time (CT)

The time at which a process finishes execution.

---

## Turnaround Time (TAT)

```text
Turnaround Time = Completion Time - Arrival Time
```

---

## Response Time (RT)

```text
Response Time = First CPU Allocation Time - Arrival Time
```

---

# Requirements

- C++11 or later
- g++ compiler

---

# Compilation Instructions

## FIFO

Compile:

```bash
g++ fifo.cpp -o fifo
```

Run:

```bash
./fifo
```

Windows:

```bash
fifo
```

---

## SJF

Compile:

```bash
g++ sjf.cpp -o sjf
```

Run:

```bash
./sjf
```

Windows:

```bash
sjf
```

---

## STCF / SRTF

Compile:

```bash
g++ stcf.cpp -o stcf
```

Run:

```bash
./stcf
```

Windows:

```bash
stcf
```

---

## Round Robin

Compile:

```bash
g++ round_robin.cpp -o rr
```

Run:

```bash
./rr
```

Windows:

```bash
rr
```

---

# Sample Output

```text
ID      ARR     BURST   COMP    TAT     RESP
P1      0       8       8       8       0
P2      1       4       12      11      7
P3      2       9       26      24      15
P4      3       5       17      14      9
```

---

# Scheduling Types Comparison

| Algorithm | Preemptive | Selection Rule |
|------------|------------|----------------|
| FIFO / FCFS | No | Arrival Order |
| SJF | No | Shortest Burst |
| STCF / SRTF | Yes | Shortest Remaining Time |
| Round Robin | Yes | Fixed Time Quantum |

---

# Concepts Used

- CPU Scheduling
- Operating Systems
- Queues
- Process Management
- Preemptive Scheduling
- Non-preemptive Scheduling
- Turnaround Time
- Response Time

---

# Future Improvements

Possible future additions:

- Priority Scheduling
- Lottery Scheduling
- Multi-Level Feedback Queue (MLFQ)
- Gantt Chart Visualization
- Waiting Time Calculation

---

# Author

Tanmoy

---
