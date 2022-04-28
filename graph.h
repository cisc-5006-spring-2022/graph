#include <iostream>

/**
 * This file contains the implementation of a graph data structure using
 * an adjaceny matrix.
 */

using namespace std;

template <class VertexType>
class GraphType {
    public:
        GraphType() {
            // For simplicity, we hardcode the maximum number of nodes at 100.
            // At the time this constructor is called, we have an array of 100
            // strings (for vertex names) and a 100x100 matrix of booleans
            // (for the adjacency matrix) already allocated (see the private block).
            // Here, we initialize the matrix.
            this->max = 100;
            this->count = 0;
            for(int i=0; i< 100; i++) {
                for(int j = 0; j < 100; j++) {
                    edges[i][j] = false;
                }
            }
        }

        // Add a vertex to the graph.
        // Precondition: The vertex has not already been added to the graph.
        // Postcondition: The vertex is in the graph.
        void AddVertex(VertexType v) {
            // Perform a linear search to ensure the vertex is not already in the graph.
            // If it is, do nothing.
            for(int i = 0; i < count; i++) {
                if (v == vertices[i]) {
                    return;
                }
            }

            // Add the vertex to the graph like an unsorted list.
            vertices[count] = v;
            count++;
            cout << "Added " << v << endl;
        }

        // Add an edge connecting two vertices to the graph.
        // Precondition: The edge does not exist in the graph. Vertices "from"
        //               and "to" exist in the graph.
        // Postcondition: The vertices "from" and "to" are connected by an edge.
        void AddEdge(VertexType from, VertexType to) {
            // Step 1: Find the index of the "from" vertex in the vertex array.
            int fromIdx = 0;
            for(; fromIdx < 100; fromIdx++) {
                if (vertices[fromIdx] == from) {
                    break;
                }
            }

            // Step 2: Find the index of the "to" vertex in the vertex array.
            int toIdx = 0;
            for(; toIdx < 100; toIdx++) {
                if (vertices[toIdx] == to) {
                    break;
                }
            }

            // Set the corresponding space in the adjacency matrix to true.
            // Note it is impossible to add the same vertex twice: if
            // edges[fromIdx][toIdx] is already true, the statement below will
            // do nothing.
            edges[fromIdx][toIdx] = true;
        }
    private:
        int max;
        int count;
        VertexType vertices[100];
        bool edges[100][100];

};