#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
	int numNodes;
	int numEdges;
	std::vector<int> nodes;
	std::vector< vector<int> > edges;

public:
	void addNodes(vector<int> nodes);
	void addEdge(int start, int end);
};

void Graph::addNodes(vector<int> nodes) {

}

int main() {
	// input
    int n, m;
    cin >> n >> m;

	std::vector<int> listNodes;
    std::vector< vector<int> > listEdges;
    
    for (int x = 0; x < n; x++) {
        listNodes.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        cout << listNodes[i];
    }
    cout << "\n";
}
