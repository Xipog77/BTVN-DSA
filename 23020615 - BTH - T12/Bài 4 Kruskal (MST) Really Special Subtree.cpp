#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int find(int target, vector<int> &parent) {
    if (parent[target] != target) {
        parent[target] = find(parent[target], parent);
    }
    return parent[target];
}

void unionSets(int node1, int node2, vector<int> &parent, vector<int> &rank) {
    int root1 = find(node1, parent);
    int root2 = find(node2, parent);

    if (root1 != root2) {
        if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        } else if (rank[root1] < rank[root2]) {
            parent[root1] = root2;
        } else {
            parent[root2] = root1;
            rank[root1]++;
        }
    }
}

int kruskals(int g_nodes, int g_edges, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {

    vector<tuple<int, int, int>> graphs;
    for (int i = 0; i < g_edges; i++) {
        tuple<int, int, int> temp(g_weight[i], g_from[i], g_to[i]);
        graphs.push_back(temp);
    }

    sort(graphs.begin(), graphs.end());

    vector<int> parent(g_nodes + 1);
    vector<int> rank(g_nodes + 1, 0);
    for (int i = 1; i <= g_nodes; i++) {
        parent[i] = i;
    }

    int total_weight = 0;

    for (tuple<int, int, int> edge : graphs) {
        int weight = get<0>(edge);
        int node1 = get<1>(edge);
        int node2 = get<2>(edge);

        if (find(node1, parent) != find(node2, parent)) {
            unionSets(node1, node2, parent, rank);
            total_weight += weight;
        }
    }

    return total_weight;
}

int main() {
    int g_nodes, g_edges;

    cin >> g_nodes >> g_edges;

    vector<int> g_from(g_edges), g_to(g_edges), g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        cin >> g_from[i] >> g_to[i] >> g_weight[i];
    }

    cout << kruskals(g_nodes, g_edges, g_from, g_to, g_weight);

}
