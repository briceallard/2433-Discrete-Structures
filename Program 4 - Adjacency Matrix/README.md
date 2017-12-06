Write a program to read integers into an n x n array. Then determine whether that matrix is a valid adjacency matrix for
a simple undirected graph. If the matrix represents a valid adjacency matrix, find the degree of each vertex along with the
total number of edges. If the matrix does not represent a valid adjacency matrix, out INVALID.

Specific requirements include:
1. output name at top of output file
2. The first number in the input file indicates the number of adjacency matrices in the file
3. For each set of data, there will be an integer n indicating the number of vertices for the current graph
4. Following that will be n rows with n entries each of integers.
5. You must use arrays or vectors in this program.
6. If you use arrays, you must dynamically allocate memory for each array and properly free up that memory 
when you finish processing that particular matrix(array)
7. There will not be more than 26 vertices
8. No global variables allowed.
9. Label vertices A, B, C, etc.

Sample input file:
```
5
4
0 0 1 1
0 0 0 1
1 0 0 0
0 1 0 0
5
0 1 1 0 1
1 0 0 1 0
1 0 0 0 1
0 1 0 0 1
1 0 1 1 0
6
0 1 1 1 1 0
1 0 1 1 0 1
0 1 0 0 1 0
0 1 0 0 1 0
1 0 1 1 0 1
0 1 1 1 1 0
6
0 1 1 1 1 0
1 0 0 1 0 1
1 0 0 2 1 0
1 1 2 0 1 1
1 0 1 1 0 0
0 1 0 1 0 0
6
0 1 1 1 1 0
1 0 0 1 0 1
1 0 0 1 1 0
1 1 1 0 1 1
1 0 1 1 0 0
0 1 0 1 0 0
```

Output should be:
```
Brice Allard

Matrix #1
INVALID

Matrix #2
Vertex A: 3
Vertex B: 2
Vertex C: 2
Vertex D: 2
Vertex E: 3
Number of Edges: 6

Matrix #3
INVALID

Matrix #4
INVALID

Matrix #5
Vertex A: 4
Vertex B: 3
Vertex C: 3
Vertex D: 5
Vertex E: 3
Vertex F: 2
Number of Edges: 10
```
