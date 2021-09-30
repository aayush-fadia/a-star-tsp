# Solving the Travelling Salesman Problem using A* with Minimum Spanning Tree Heuristic.
## To run
Clone the repo, cd into it, then
```bash
bazel run //solver:solver <path to graph file>
```

Sample Graphs are in the `sample_graphs/`
## Credits
Progress bar adapted from [aminnj/cpptqdm](https://github.com/aminnj/cpptqdm).
## Screenshots
![Small Graph](screenshots/A_star_5_nodes.png)
![25 Nodes](screenshots/A_star_25_nodes_dense.png)
![40 Unsolvable](screenshots/A_star_40_nodes_unsolvable.png)
![50 Nodes](screenshots/A_star_50_nodes_sparse.png)
![1000 Nodes](screenshots/A_star_1000_nodes_sparse.png)
