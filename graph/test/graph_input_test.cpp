#include <iostream>
#include <fstream>
#include <algorithm>
#include "gtest/gtest.h"
#include "graph.h"

TEST(GraphInputTest, GraphInputFunctions)
{
	std::ifstream f;

	// open the file
	f.open("../data/tinyG.txt");
	if (!f.is_open())
	{
		FAIL();
	}

	EXPECT_TRUE(f.is_open());

	// read number of vertices
	int v = Graph::scanInt(f);
	EXPECT_EQ(v, 13);

	// read number of edges
	int e = Graph::scanInt(f);
	EXPECT_EQ(e, 13);

	// read an edge
	Graph::Edge edge = Graph::scanEdge(f);
	EXPECT_EQ(edge.v, 0);
	EXPECT_EQ(edge.w, 5);

	f.close();
}

// extracted test data from tinyG.txt
const int edges[13][2] = {
	{0, 5},
	{4, 3},
	{0, 1},
	{9, 12},
	{6, 4},
	{5, 4},
	{0, 2},
	{11, 12},
	{9, 10},
	{0, 6},
	{7, 8},
	{9, 11},
	{5, 3}};

TEST(GraphInputTest, GraphDataInput)
{
	std::ifstream f;

	// read the graph data
	auto gd = Graph::getGraphData("../data/tinyG.txt");

	// check the values
	EXPECT_EQ(gd->v, 13);
	EXPECT_EQ(gd->e, 13);

	EXPECT_EQ(gd->edges.size(), 13u);
	for (std::size_t i = 0; i < gd->edges.size(); i++)
	{
		auto edge = gd->edges[i];
		auto val = edges[i];
		EXPECT_EQ(edge.v, val[0]);
		EXPECT_EQ(edge.w, val[1]);
	}
}

const std::vector<int> test_adj[13] = {
	{5, 1, 2, 6},
	{0},
	{0},
	{4, 5},
	{3, 6, 5},
	{0, 3, 4},
	{4, 0},
	{8},
	{7},
	{12, 10, 11},
	{9},
	{12, 9},
	{9, 11}};

void checkV(const std::vector<int> &g, const std::vector<int> &t)
{
	EXPECT_EQ(g.size(), t.size());

	for (std::size_t i = 0; i < g.size(); i++)
	{
		auto v = std::find(g.begin(), g.end(), t[i]);
		// if its found, then its in the list
		if (v == g.end())
		{
			// one of them overflows
			EXPECT_NE(v, g.end());
		}
	}
}

TEST(GraphInputTest, GraphCreation)
{
	std::ifstream f;

	// read the graph data
	std::unique_ptr<const Graph::GraphData> gd = Graph::getGraphData("../data/tinyG.txt");

	std::unique_ptr<Graph::Graph> graph = NewAdjacencyListGraph(gd.get());

	EXPECT_EQ(graph->v(), 13);
	EXPECT_EQ(graph->e(), 13);
	for (auto v = 0; v < graph->v(); v++)
	{
		checkV(graph->adj(v), test_adj[v]);
	}
}
