#include <iostream>
#include <tuple>

struct Edge {
	int v;
	int w;
}

struct GraphData {
	int v;
	int e;
	std::vector<Edge> edges;
}

int scanInt() {
	return 0;
}

std::tuple<int, int> scanEdge() {
	return std::make_tuple(0,0)
}

GraphData readGraphData(string fname) {
	return GraphData();
}
