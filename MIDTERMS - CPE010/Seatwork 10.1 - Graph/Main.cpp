#include <iostream>
#include <vector>

// Structure to represent a weighted edge
template <typename T>
struct Edge {
    size_t src;
    size_t dest;
    T weight;
};

template <typename T>
class Graph {
private:
    size_t V;
    std::vector<Edge<T>> edge_list;
    std::vector<std::vector<T>> adj_matrix;
    std::vector<char> name;

public:
    Graph(size_t vertices) : V(vertices) {
        // Initialize adjacency matrix with 0 weight
        adj_matrix.resize(V, std::vector<T>(V, 0));
        // Creating the vertex labels
        name = {'A', 'B', 'C', 'D'};
    }

    // Adding a directed edge to the graph
    void add_edge(size_t src, size_t dest, T weight) {
        edge_list.push_back({src, dest, weight});
        adj_matrix[src][dest] = weight;
    }

    // Priting the Graph Edges
    void print_graph() const {
        std::cout << "Graph Edge List:\n";
        for (const auto& edge : edge_list) {
            char src_char = name[edge.src];
            char dest_char = name[edge.dest];
            std::cout << src_char << " -> " << dest_char << " \nWeight: " << edge.weight << "\n";
        }
        std::cout << "\n";
    }

    // Printing the Adjacency Matrix
    void print_adjacency_matrix() const {
        std::cout << "Adjacency Matrix:\n  ";
        for (size_t i = 0; i < V; ++i) {
            std::cout << name[i] << " ";
        }
        std::cout << "\n";

        for (size_t i = 0; i < V; ++i) {
            std::cout << name[i] << " ";
            for (size_t j = 0; j < V; ++j) {
                std::cout << adj_matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    // Initialize the Graph with 4 vertices
    Graph<int> g(4);

    // Adding the edges
    g.add_edge(0, 1, 3); // A -> B with a weight of 3
    g.add_edge(0, 2, 2); // A -> C with a weight of 2
    g.add_edge(2, 1, 1); // C -> B with a weight of 1
    g.add_edge(3, 0, 4); // D -> A with a weight of 4

    // Print the Graph Edge in a List along with the weight
    g.print_graph();
    // Print the Adjacency Matrix according to the edges and using the value in Graph for its Vertices
    g.print_adjacency_matrix();

    return 0;
}