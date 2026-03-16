# 🚀 Clean Recursive Quadtree Construction (Divide & Conquer)

## Intuition

A **Quadtree** recursively divides a 2D grid into four equal quadrants
until each region contains only **one value (all `0` or all `1`)**.

For any subgrid:

1.  Check whether all cells contain the same value.
2.  If they do, create a **leaf node**.
3.  If not, divide the grid into four equal quadrants and recursively
    build a node for each quadrant.

This naturally forms a **divide-and-conquer recursive structure**.

------------------------------------------------------------------------

## Approach

We use a recursive function:

    dfs(grid, size, row, col)

Where:

-   `size` → length of the current square region
-   `(row, col)` → top-left corner of that region

### Step 1 --- Check if the region is uniform

Scan the square:

    [row, row + size)
    [col, col + size)

If all values match the first cell, the region is uniform.

### Step 2 --- Create a leaf node

If the region is uniform:

    return new Node(value == 1, true)

This node represents a leaf of the quadtree.

### Step 3 --- Divide the region

If the region is not uniform, split it into four quadrants of size
`size / 2`:

-   topLeft
-   topRight
-   bottomLeft
-   bottomRight

Each quadrant is built recursively.

### Step 4 --- Create an internal node

Create a non-leaf node and attach the four recursively constructed
children.

------------------------------------------------------------------------

## Complexity

### Time Complexity

Worst case occurs when the grid must be subdivided at every level.

O(n² log n)

Each recursion level scans a region of the grid.

### Space Complexity

O(log n)

This comes from the recursion stack depth of the quadtree.

------------------------------------------------------------------------

## Code

``` cpp
class Solution {
public:
    Node* dfs(vector<vector<int>>& grid, int n, int r, int c) {

        bool isLeaf = true;
        int value = grid[r][c];

        int rowEnd = r + n;
        int colEnd = c + n;

        // Check if the region is uniform
        for (int i = r; i < rowEnd && isLeaf; i++) {
            for (int j = c; j < colEnd; j++) {
                if (grid[i][j] != value) {
                    isLeaf = false;
                    break;
                }
            }
        }

        // If uniform, return a leaf node
        if (isLeaf) {
            return new Node(value == 1, true);
        }

        // Otherwise split into four quadrants
        Node* node = new Node(false, false);
        int half = n / 2;

        node->topLeft     = dfs(grid, half, r, c);
        node->topRight    = dfs(grid, half, r, c + half);
        node->bottomLeft  = dfs(grid, half, r + half, c);
        node->bottomRight = dfs(grid, half, r + half, c + half);

        return node;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return dfs(grid, n, 0, 0);
    }
};
```
