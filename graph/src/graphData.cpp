#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include <cassert>
#include "graph.h"

namespace Graph {

	int scanInt(std::ifstream &f) {
		int i;
		f >> i;

		return i;
	}

	Edge scanEdge(std::ifstream& f) {
		int v = scanInt(f);
		int w = scanInt(f);
		return Edge(v, w);
	}

	// GetTestData get test data for union connectivity algorithms
	std::unique_ptr<const GraphData> getGraphData(std::string fname) {
		GraphData gd;
		
		std::ifstream f;
		// open the file
		f.open(fname);
		if (!f.is_open()) {
			throw std::runtime_error("can't open input file");
		}

		// 1. get number of vertices
		gd.v = scanInt(f);

		// 2. get number of edges
		gd.e = scanInt(f);

		// 3. get graph data
		for (auto i = 0; i < gd.e; i++) {
			gd.edges.push_back(scanEdge(f));
		}

		return std::make_unique<GraphData>(gd);
	}

}
