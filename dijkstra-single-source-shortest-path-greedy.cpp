// For priority queue tracking
class Node {
	public:
	int vertex, weight;
};

// Comparator for minheap priority queue
class Comp {
	public:
	bool operator()(const Node &lhs, const Node &rhs) {
        return lhs.weight > rhs.weight;
    }
};

class Edge {
public:
  int source, dest, weight;
};

// Class to store graph data
class Graph {
public:

  // vector of vectors to represent an adjacency list
  vector<vector<pair<int,int>>> adjList;

  // total number of nodes in the graph
  int n;

  Graph(vector<Edge> &edges, int size) {
    n = size;
    adjList.resize(n);

    for (Edge &edge: edges) {
      adjList[edge.source].push_back(make_pair(edge.dest, edge.weight));
    }
  }
};

class Solution {
public:
	set<vector<int>> findShortestPaths(Graph const &graph, int source) {
		set<vector<int>> paths;

		priority_queue<Node, vector<Node>, Comp> minheap; // For retreiving min distance node
		minheap.push({source, 0}); // Starting with source vertex
		
		int n = graph.n;
		vector<int> dist(n, INT_MAX); // For storing shortest distance
		dist[source] = 0;
		
		vector<bool> visited(n, false); // For marking node as visited (We can use set as well)
		visited[source] = true; // source is being visited first.
		
		while(!minheap.empty()) { // explore all other nodes
			Node node = minheap.top();
			minheap.pop();
			
			int u = node.vertex;
			for(auto i: graph.adjList[u]) { // explore all neighbors
				int v = i.first;
				int weight = i.second;
        
        			// Principle of relaxation
				if(!visited[v] && (dist[u]+weight) < dist[v]) {
					dist[v] = dist[u]+weight;
					minheap.push({ v, dist[v] });
				}
			}
			visited[u] = true;
		}

		for(int i=0; i<n; i++) { // storing distances, except source and non-reachable nodes
			if(i!=source && dist[i]!=INT_MAX) {
				paths.insert({source, i, dist[i]});
			}
		}
		
		return paths;
	}
};
