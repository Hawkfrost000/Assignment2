//
// Created by Gareth on 1/21/2019.
//

#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

class node {
private:
    int lable;
    vector<node> neighbors;
    int component;

public:
    node(int label);
    void addNeighbor(node node);
    int getLable();
    vector<node> getNeighbors();
    void setComponent(int i);
    int getComponent();
};

node::node(int l) {
    lable = l;
    component = 0;
}

void node::addNeighbor(node node) {
    neighbors.push_back(node);
}

void node::setComponent(int c) {
    component = c;
}

int node::getLable() {
    return lable;
}

int node::getComponent() {
    return component;
}

vector<node> node::getNeighbors() {
    return neighbors;
}

void fillOrder(int v, bool visited[], stack<int> &stack, vector<node> graph) {

    visited[v] = true;

    node currentNode = graph[v];
    vector<node> neighbors = currentNode.getNeighbors();
    for (int x = 0; x < neighbors.size(); x++) {
        if (! visited[neighbors[x].getLable()]) {
            fillOrder(neighbors[x].getLable(), visited, stack, graph);
        }
    }

    stack.push(v);
}

void dfs(int v, bool visited[], int iter, vector<node> graph) {

    visited[v] = true;

    node currentNode = graph[v];
    vector<node> neighbors = currentNode.getNeighbors();


}

void findComponents(vector<node> graph) {
    stack<int> stack;
    int numNodes = graph.size();
    bool *visited = new bool[numNodes];

    for (int i = 0; i < numNodes; i++){
        visited[i] = false;
    }

    for(int i = 0; i < numNodes; i++) {
        if (visited[i] == false) {
            fillOrder(i, visited, stack, graph);
        }
    }

    for (int i = 0; i < numNodes; i++){
        visited[i] = false;
    }

    int iter = 1;
    while (stack.empty() == false) {
        int v = stack.top();
        stack.pop();

        if (visited[v] == false) {
            dfs(v, visited, iter, graph);
        }
        iter ++;
    }
}

int main() {
    // input
    int n, m, start, dest;
    node ne(0);
    cin >> n >> m;

    vector<node> graph;

    for (int x = 0; x < n; x++) {
        ne = node(x + 1);
        graph.push_back(ne);
    }

    for (int x = 0; x < m; x++){
        cin >> start >> dest;
        graph[start-1].addNeighbor(graph[dest-1]);
    }

    findComponents(graph);

    return 0;
}