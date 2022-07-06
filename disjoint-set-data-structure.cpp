/*
A disjoint–set is a data structure that keeps track of a set of elements partitioned into several disjoint (non-overlapping) subsets. In other words, a disjoint 
set is a group of sets where no item can be in more than one set. It is also called a union–find data structure as it supports union and find operation on subsets. 
Let’s begin by defining them:

Find: It determines in which subset a particular element is in and returns the representative of that particular set. An item from this set typically acts as 
a “representative” of the set.

Union: It merges two different subsets into a single subset, and the representative of one set becomes representative of another.
*/

void makeSet(vector<int> &parent, vector<int> &rank) {
  int n = parent.size();
  for(int i=0; i<n; i++) {
    parent[i] = i;
    rank[i] = 0;
  }
}

// Finds parent/representative of a set
int findParent(int node, vector<int> &parent) {
		if(node == parent[node])
			return node;
		int par = findParent(parent[node], parent);
		parent[node] = par; // path compression
		return parent[node];
}
	
// Combines a node into a set
void union(int u, int v, vector<int> &parent, vector<int> &rank) {
		u = findParent(u);
		v = findParent(v);
		if(rank[u] < rank[v]) {
			parent[u] = v;
		}
    else if(rank[v] < rank[u]) {
			parent[v] = u;
		}
    else {
			parent[v] = u;
			rank[u]++;
		}
}
