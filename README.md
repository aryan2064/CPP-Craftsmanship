# C-Craftsmanship

A curated C++ monorepo of terminal-first projects focused on core programming concepts like game logic, finite state machines, expression parsing, and graph traversal algorithms.

## Repository Structure

| # | Project | Description | Folder | GitHub link |
|---|---|---|---|---|
| 1 | Tic-Tac-Toe | Classic two-player terminal game with input validation and win/draw detection. | `1 Tic-Tac-Toe` | [View](https://github.com/aryan2064/C-Craftsmanship/tree/main/1%20Tic-Tac-Toe) |
| 2 | Traffic Light Simulator | FSM-based traffic light cycle simulator with configurable timings and pedestrian mode. | `2 Traffic-Light-Simulator` | [View](https://github.com/aryan2064/C-Craftsmanship/tree/main/2%20Traffic-Light-Simulator) |
| 3 | Expression Evaluator | Infix-to-postfix parser and evaluator with operator precedence and runtime checks. | `3 Expression-Evaluator` | [View](https://github.com/aryan2064/C-Craftsmanship/tree/main/3%20Expression-Evaluator) |
| 4 | Maze Solver (DFS & BFS) | Grid pathfinding using DFS/BFS with optional diagonal movement and path visualization. | `4 Maze-Solver` | [View](https://github.com/aryan2064/C-Craftsmanship/tree/main/4%20Maze-Solver) |

## Featured Projects


### 1. Expression Evaluator
An interactive C++ evaluator that converts infix math expressions to postfix notation and computes results using stack-based evaluation. It highlights expression parsing, operator precedence handling, and defensive error checks.

- **Key Features:** Infix-to-postfix conversion (Shunting-yard), support for `+ - * / ^`, parentheses and floating-point parsing, interactive REPL, syntax/runtime error handling.

- **Technologies:** C++, Standard Library (Stacks, Strings), Console I/O.

- **View Project:** [3 Expression-Evaluator](https://github.com/aryan2064/C-Craftsmanship/tree/main/3%20Expression-Evaluator)

### 2. Maze Solver (DFS & BFS)
A pathfinding project that solves mazes using both Depth-First Search and Breadth-First Search, with optional diagonal movement and side-by-side algorithm comparison. It demonstrates traversal strategies, shortest-path reasoning, and grid-based modeling.

- **Key Features:** DFS and BFS implementations, predefined/custom maze input, optional 4-direction or 8-direction movement, ASCII path visualization, solution path statistics.

- **Technologies:** C++, Standard Library, Graph Traversal Algorithms (DFS/BFS), Console I/O.

- **View Project:** [4 Maze-Solver](https://github.com/aryan2064/C-Craftsmanship/tree/main/4%20Maze-Solver)

## How To Run Any Project

1. Open the project directory.
2. Compile with `g++`.
3. Run the generated executable.

Example:

```bash
g++ main.cpp -o app
./app
```

> Note: The Traffic Light Simulator uses `windows.h` for sleep timing.

## Goals

This repository is designed to strengthen practical C++ fundamentals through self-contained, buildable projects.
