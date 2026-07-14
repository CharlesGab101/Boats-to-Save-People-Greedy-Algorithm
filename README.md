# CPSC 335: Algorithm Engineering - Project 2

## 👥 Team

| Name | Role / Email |
| --- | --- |
| **Charles Edwill Gabut** | Student ([charles_g@csu.fullerton.edu](mailto:cgabut@csu.fullerton.edu)) |

---

## 🛠 Project Components

### 1. Boats to Save People (Project 2)
An optimization algorithm designed to carry everyone safely using the minimum number of rescue boats under a strict weight capacity limit.
*   **Objective:** Calculate the minimum number of boats required to carry every person safely.
*   **Logic:**
    *   **Sorting:** The weights array is sorted and reversed to process individuals from heaviest to lightest.
    *   **Greedy Choice:** The algorithm attempts to pack the heaviest remaining individuals into the current boat. If adding the next person exceeds the `max_weight` limit, the current boat is dispatched and a new boat is started.
*   **Efficiency:** 
    *   **Time Complexity:** $\mathcal{O}(n \log n)$ due to the sorting step (`std::sort`), which acts as the main bottleneck.
    *   **Space Complexity:** $\mathcal{O}(n)$ as it creates a local copy `std::vector<int> A` to safely sort and reverse the data without mutating the original input.

---

## 💻 Tech Stack

| Category | Tools / Concepts |
| --- | --- |
| **Language** | C++ (Standard C++17) |
| **Algorithms** | Greedy Algorithms |
| **Operations** | Array Manipulation, Sorting, Greedy Optimization |

---

## 🚀 Getting Started

### Compilation
To compile the **Boats to Save People** executable, run the following command in your terminal:
```bash
g++ -std=c++17 main_two_2_.cpp -o algorithm_2.out
