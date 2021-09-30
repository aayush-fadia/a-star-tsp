import numpy as np
import argparse


def generate_graph(num_nodes, avg_conn, path_mean, path_std, other_mean, other_std):
    graph = np.full((num_nodes, num_nodes), -1, dtype=int)
    visited = np.full(num_nodes, False, dtype=bool)
    visited[0] = True
    src_node = 0
    while not np.all(visited):
        dest_node = np.random.randint(0, num_nodes)
        while dest_node == src_node or visited[dest_node] or graph[src_node][dest_node] != -1:
            dest_node = (dest_node + 1) % num_nodes
        visited[dest_node] = True
        wt = max(0, int(np.random.normal(path_mean, path_std)))
        graph[src_node, dest_node] = wt
        graph[dest_node, src_node] = wt
        src_node = dest_node
    dest_node = 0
    wt = max(0, int(np.random.normal(path_mean, path_std)))
    graph[src_node, dest_node] = wt
    graph[dest_node, src_node] = wt
    src_dst = np.random.randint(0, num_nodes, (num_nodes * avg_conn // 2, 2))
    wts = np.random.normal(other_mean, other_std, num_nodes * avg_conn // 2)
    for (s, d), wt in zip(src_dst, wts):
        if s != d and graph[s, d] == -1:
            graph[s, d] = wt
            graph[d, s] = wt
    return graph


def write_graph(graph, out_file):
    with open(out_file, 'w') as f:
        f.write(str(graph.shape[0]))
        for row in graph:
            f.write('\n')
            for val in row:
                f.write(str(val))
                f.write(' ')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Generate a solvable TSP graph.')
    parser.add_argument('num_nodes', type=int)
    parser.add_argument('avg_degree', type=int)
    parser.add_argument('path_mean', type=int)
    parser.add_argument('path_std', type=int)
    parser.add_argument('other_mean', type=int)
    parser.add_argument('other_std', type=int)
    parser.add_argument('outfile', type=str)
    args = parser.parse_args()
    generated_graph = generate_graph(args.num_nodes, args.avg_degree, args.path_mean, args.path_std, args.other_mean,
                                     args.other_std)
    write_graph(generated_graph, args.outfile)
