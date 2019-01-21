#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

class Graph
{
private:
	int numNodes;
	int numEdges;
	std::list<int>  *adj;
	std::vector<int> components;

public:
	Graph(int N, int M);
	void addEdge(int start, int end);
	void printComponents();
	void findComponents();
	void fillOrder(int v, bool visited[], stack<int> &stack);
	void dfs(int v, bool visited[], int iter);
	Graph getTranspose();
};

Graph::Graph(int N, int M) {
    numNodes = N;
    numEdges = M;
    adj = new list<int>[numNodes];
}

void Graph::addEdge(int start, int end) {
    adj[start-1].push_back(end);
    cout << "added edge from " << start << " to " << end;
}

void Graph::printComponents() {
    for (int i = 0; i < numNodes; i++) {
        cout << components[i];
    }
}

void Graph::fillOrder(int v, bool visited[], stack<int> &stack) {

    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++) {
        if (! visited[*i]) {
            fillOrder(*i, visited, stack);
        }
    }
    stack.push(v);
}

Graph Graph::getTranspose() {
    Graph g = Graph(numNodes, numEdges);
    for (int v = 0; v < numNodes; v++) {
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i) {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::dfs(int v, bool visited[], int iter) {

    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i]) {
            components[*i] = iter;
            dfs(*i, visited, iter);
        }

}

void Graph::findComponents() {
    stack<int> stack;
    bool *visited = new bool[numNodes];

    for (int i = 0; i < numNodes; i++){
        visited[i] = false;
    }

    for(int i = 0; i < numNodes; i++) {
        if (visited[i] == false) {
            fillOrder(i, visited, stack);
        }
    }

    for (int i = 0; i < numNodes; i++){
        visited[i] = false;
    }

    Graph reverse = getTranspose();

    int iter = 1;
    while (stack.empty() == false) {

        int v = stack.top();
        stack.pop();

        if (visited[v] == false) {
            reverse.dfs(v, visited, iter);
        }
        iter ++;
    }

    reverse.printComponents();

}

int main() {
	// input
    int n, m, start, dest;
    cin >> n >> m;

	Graph g = Graph(n, m);

	for (int x = 0; x < m; x++){
	    cin >> start >> dest;
	    g.addEdge(start, dest);

	}

	g.findComponents();
	cout << "test4" << std::flush;

	return 0;

}
