# Maze Solver (DFS & BFS)

A comprehensive C++ application that finds paths through mazes using Depth-First Search (DFS) and Breadth-First Search (BFS). It supports both predefined and custom mazes, optional diagonal movement, and compares pathfinding results.

## Features
- **Multiple Algorithms**:
    - **DFS (Depth-First Search)**: Finds any path using recursion and backtracking.
    - **BFS (Breadth-First Search)**: Guarantees the shortest path in an unweighted grid.
- **Custom Input**: Enter your own maze grid or use a predefined 10x10 challenge.
- **Diagonal Movement**: Choose whether to allow movement in 8 directions (including diagonals) or 4 directions (strictly cardinal).
- **ASCII Visualization**: Real-time rendering of the maze with walls (`#`), start (`S`), end (`E`), and the discovered path (`*`).
- **Path Statistics**: Displays total steps and provides the exact coordinates of the solution path.

## How to Run

### Compilation
Compile the source code using `g++`:

```bash
g++ maze_solver.cpp -o maze_solve
```

### Execution
Run the compiled executable:

```bash
./maze_solve
```

## Output

```bash
========================================
         MAZE SOLVER (DFS & BFS)        
========================================

Choose input method:
1. Use predefined maze
2. Enter custom maze
Choice: 1

Using predefined 10x10 maze.
Start: (0,0)  End: (9,9)

Allow diagonal movement? (y/n): y

----- Original Maze -----
Legend: # = Wall, S = Start, E = End, * = Path, . = Visited

+--------------------+
| S   #               |
| #   #   # # # #   # |
| #             #   # |
| # # # # # #   #   # |
| #             #   # |
| #   # # # # # #   # |
| #                   |
| # # # # # # # # #   |
|                     |
| # # # # # # # # # E |
+--------------------+

Choose algorithm:
1. DFS (Depth-First Search)
2. BFS (Breadth-First Search)
3. Both (compare results)
Choice: 3

========== Solving with DFS ==========
Path found! (length = 30 steps)
+--------------------+
| S * #               |
| # * #   # # # #   # |
| # * * * * * * #   # |
| # # # # # # * #   # |
| # * * * * * * #   # |
| # * # # # # # #   # |
| # * * * * * * * * * |
| # # # # # # # # # * |
|                 * * |
| # # # # # # # # # E |
+--------------------+

========== Solving with BFS ==========
Shortest path found! (length = 17 steps)
+--------------------+
| S   #   * * * *     |
| # * # * # # # # * # |
| #   *         # * # |
| # # # # # #   # * # |
| #             # * # |
| #   # # # # # # * # |
| #               *   |
| # # # # # # # # # * |
|                   * |
| # # # # # # # # # E |
+--------------------+

Press Enter to exit...
```
