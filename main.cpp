#include <string>
#include "graph.h"

using namespace std;

int main() {
    GraphType<string>g = GraphType<string>();

    g.AddVertex("Austin");
    g.AddVertex("Houston");
    g.AddVertex("New York");
    g.AddVertex("Orlando");

    g.AddEdge("Austin", "Orlando");
    g.AddEdge("New York", "Orlando");
    g.AddEdge("Houston", "New York");
}