#include "graph.h"
#include "gtest/gtest.h"
#include <algorithm>
#include <deque>
#include <iostream>

const int tinyPathLen[13] = {
	0, 2, 2, 4, 3, 2, 4, 0, 0, 0, 0, 0, 0};

TEST(GraphDFSTest, GraphDfsFSHasPathTo)
{
	// read the graph data
	std::unique_ptr<const Graph::GraphData> gd = Graph::getGraphData("../data/tinyG.txt");

	// create the graph
	const std::unique_ptr<Graph::Graph> graph = NewAdjacencyListGraph(gd.get());
	int source = 0;

	// create a processed DFS starting at source = 0
	const auto dfs = Graph::NewDFS(graph.get(), source);

	// test if there is a path from 0 to the other nodes in the graph
	for (auto i = 1; i < graph->v(); i++)
	{
		auto b = dfs->hasPathTo(i);
		if (b)
		{
			auto p = dfs->pathTo(i);
			EXPECT_EQ(p.size(), static_cast<size_t>(tinyPathLen[i]));
			for (auto w : p)
			{
				std::cerr << w << ",";
			}
			std::cerr << "\n";
		}
		else
		{
			std::cerr << "no path from " << source << " to " << i << "\n";
		}
	}
}