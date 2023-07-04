
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

bool is_complete_graph(unordered_map<int, vector<int>>& graph) {
    int num_vertices = graph.size();
    
    for (auto& vertex : graph) {
        unordered_set<int> connected_vertices(vertex.second.begin(), vertex.second.end());
        if (connected_vertices.size() != num_vertices - 1) {
            return false;
        }
    }
    return true;
}

int main() {
    unordered_map<int, vector<int>> G = {
        {0, {0, 0, 3}},
        {1, {1, 3, 2}},
        {2, {0, 1, 3}},
        {3, {0, 1, 2}}
    };
    cout << "LENGTH " << G.size() << endl;
    bool result = is_complete_graph(G);
    if (result) {
        cout << "The graph is a complete graph" << endl;
    } else {
        cout << "The graph is not a complete graph" << endl;
    }
    return 0;
}
