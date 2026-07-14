# CPSC 335: Algorithm Engineering - Project 2

This repository includes the implementations for Project 2, where Algorithm 1 focuses on solving a maze using graph traversal.

## Algorithm 1: Maze Pathfinding with BFS

### Objective
Find the minimum number of moves needed to travel from a starting cell to a target cell in a grid-based maze.

### Logic
- The maze is entered as a matrix of 0s and 1s, where 0 represents an open path and 1 represents a wall.
- Each valid path cell is converted into a graph node.
- Neighboring open cells are connected with edges, creating an undirected graph.
- Breadth-First Search (BFS) is then used to find the shortest path from the start node to the target node.

### Efficiency
- The graph construction and BFS run in approximately linear time relative to the number of cells, or $O(R \times C)$ for a maze with $R$ rows and $C$ columns.
- Memory usage is also $O(R \times C)$ because the graph and visited structures store information for each cell.

## Instructions to Run the Program

Step 1: Type "chmod u+x algorithm_one_1_.sh algorithm_two2_.sh" in the Terminal
Step 2: Run "./algorithm_one_1_.sh" to run Algorithm 1
Step 3: Run "./algorithm_two2_.sh" to run Algorithm 2

Purpose of the .sh files: Using bash helps link and compile the programs in this project.