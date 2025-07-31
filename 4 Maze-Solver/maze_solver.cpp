#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

class MazeSolver {
private:
    vector<vector<int>> maze;
    int rows, cols;
    Point start, end;
    bool allowDiagonal;
    int dx[8] = { 0,  0, -1,  1, -1, -1,  1,  1};
    int dy[8] = {-1,  1,  0,  0, -1,  1, -1,  1};

    bool isValid(int x, int y, const vector<vector<bool>>& visited) {
        if (x < 0 || x >= rows || y < 0 || y >= cols) return false;
        if (maze[x][y] == 1) return false;
        if (visited[x][y]) return false;
        return true;
    }

    int getDirectionCount() {
        return allowDiagonal ? 8 : 4;
    }

    // DFS using recursion with backtracking
    bool dfsHelper(int x, int y, vector<vector<bool>>& visited, vector<Point>& path) {
        visited[x][y] = true;
        path.push_back(Point(x, y));

        if (Point(x, y) == end) return true;

        for (int i = 0; i < getDirectionCount(); i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny, visited)) {
                if (dfsHelper(nx, ny, visited, path)) return true;
            }
        }

        // Backtrack: no path found from this cell
        path.pop_back();
        return false;
    }

    // BFS using queue; tracks parent to reconstruct shortest path
    bool bfsSolve(vector<Point>& path) {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<Point>> parent(rows, vector<Point>(cols, Point(-1, -1)));

        queue<Point> q;
        q.push(start);
        visited[start.x][start.y] = true;

        bool found = false;

        while (!q.empty()) {
            Point curr = q.front();
            q.pop();

            if (curr == end) {
                found = true;
                break;
            }

            for (int i = 0; i < getDirectionCount(); i++) {
                int nx = curr.x + dx[i];
                int ny = curr.y + dy[i];
                if (isValid(nx, ny, visited)) {
                    visited[nx][ny] = true;
                    parent[nx][ny] = curr;
                    q.push(Point(nx, ny));
                }
            }
        }

        if (found) {
            // Reconstruct path from end to start using parent pointers
            Point curr = end;
            while (!(curr == start)) {
                path.push_back(curr);
                curr = parent[curr.x][curr.y];
            }
            path.push_back(start);
            // Reverse to get start-to-end order
            reverse(path.begin(), path.end());
        }

        return found;
    }

public:
    MazeSolver(const vector<vector<int>>& m, Point s, Point e, bool diagonal = false)
        : maze(m), start(s), end(e), allowDiagonal(diagonal) {
        rows = maze.size();
        cols = maze[0].size();
    }

    void printMaze(const vector<Point>& path = {}) {
        vector<vector<char>> display(rows, vector<char>(cols));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (maze[i][j] == 1)
                    display[i][j] = '#';
                else
                    display[i][j] = ' ';
            }
        }

        for (const auto& p : path) {
            if (p == start || p == end) continue;
            display[p.x][p.y] = '*';
        }

        display[start.x][start.y] = 'S';
        display[end.x][end.y] = 'E';

        cout << "+";
        for (int j = 0; j < cols; j++) cout << "--";
        cout << "+" << endl;

        for (int i = 0; i < rows; i++) {
            cout << "|";
            for (int j = 0; j < cols; j++) {
                cout << " " << display[i][j];
            }
            cout << " |" << endl;
        }

        cout << "+";
        for (int j = 0; j < cols; j++) cout << "--";
        cout << "+" << endl;
    }

    void solveDFS() {
        cout << "\n========== Solving with DFS ==========\n";
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<Point> path;

        // DFS explores as deep as possible before backtracking
        // This finds A path but not necessarily the shortest
        bool found = dfsHelper(start.x, start.y, visited, path);

        if (found) {
            cout << "Path found! (length = " << path.size() << " steps)\n";
            cout << "Path: ";
            for (size_t i = 0; i < path.size(); i++) {
                cout << "(" << path[i].x << "," << path[i].y << ")";
                if (i < path.size() - 1) cout << " -> ";
            }
            cout << endl;
            printMaze(path);
        } else {
            cout << "No path exists from S to E!\n";
            printMaze();
        }
    }

    void solveBFS() {
        cout << "\n========== Solving with BFS ==========\n";
        vector<Point> path;

        // BFS explores all neighbors at the current depth before going deeper
        // This guarantees the shortest path in an unweighted grid
        bool found = bfsSolve(path);

        if (found) {
            cout << "Shortest path found! (length = " << path.size() << " steps)\n";
            cout << "Path: ";
            for (size_t i = 0; i < path.size(); i++) {
                cout << "(" << path[i].x << "," << path[i].y << ")";
                if (i < path.size() - 1) cout << " -> ";
            }
            cout << endl;
            printMaze(path);
        } else {
            cout << "No path exists from S to E!\n";
            printMaze();
        }
    }
};

vector<vector<int>> getPredefinedMaze() {
    return {
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0}
    };
}

int main() {
    cout << "========================================\n";
    cout << "         MAZE SOLVER (DFS & BFS)        \n";
    cout << "========================================\n\n";

    int choice;
    cout << "Choose input method:\n";
        cout << "1. Use predefined maze\n";
        cout << "2. Enter custom maze\n";
        cout << "Choice: ";
        cin >> choice;

        vector<vector<int>> mazeGrid;
        Point startPt, endPt;

        if (choice == 1) {
            mazeGrid = getPredefinedMaze();
            startPt = Point(0, 0);
            endPt = Point(9, 9);
            cout << "\nUsing predefined 10x10 maze.\n";
            cout << "Start: (0,0)  End: (9,9)\n";
        } else {
            int r, c;
            cout << "Enter number of rows: ";
            cin >> r;
            cout << "Enter number of columns: ";
            cin >> c;

            mazeGrid.resize(r, vector<int>(c));
            cout << "\nEnter maze row by row (0 = open path, 1 = wall).\n";
            cout << "Separate values with spaces. Example for a 3x3 row: 0 1 0\n\n";
            for (int i = 0; i < r; i++) {
                cout << "Row " << i << ": ";
                for (int j = 0; j < c; j++) {
                    cin >> mazeGrid[i][j];
                }
            }

            int sx, sy, ex, ey;
            cout << "\nEnter START point (row col): ";
            cin >> sx >> sy;
            cout << "Enter END point (row col): ";
            cin >> ex >> ey;
            startPt = Point(sx, sy);
            endPt = Point(ex, ey);
        }

        char diagChoice;
        cout << "\nAllow diagonal movement? (y/n): ";
        cin >> diagChoice;
        bool allowDiagonal = (diagChoice == 'y' || diagChoice == 'Y');

        MazeSolver solver(mazeGrid, startPt, endPt, allowDiagonal);

        cout << "\n----- Original Maze -----\n";
        cout << "Legend: # = Wall, S = Start, E = End, * = Path, . = Visited\n\n";
        solver.printMaze();

        int algoChoice;
        cout << "\nChoose algorithm:\n";
        cout << "1. DFS (Depth-First Search)\n";
        cout << "2. BFS (Breadth-First Search)\n";
        cout << "3. Both (compare results)\n";
        cout << "Choice: ";
        cin >> algoChoice;

        if (algoChoice == 1 || algoChoice == 3) {
            solver.solveDFS();
        }
        if (algoChoice == 2 || algoChoice == 3) {
            solver.solveBFS();
        }

        cout << "\nPress Enter to exit...";
        cin.ignore();
        cin.get();

    return 0;
}