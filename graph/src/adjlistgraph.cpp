#include "graph.h"
#include <iostream>
#include <vector>
#include <memory>
#include <cassert>

namespace Graph
{
    // AdjacencyListGraph : implmentation of Undirected Graph
    class AdjacencyListGraph : public Graph
    {
    private:
        int m_v;
        int m_e;
        std::vector<std::vector<int>> m_adj;

    public:
        AdjacencyListGraph(int v) : m_v(v), m_e(0), m_adj(v, std::vector<int>())
        {
            std::cout << "empty constructor\n";
        }

        AdjacencyListGraph(const GraphData *gd)
        {
            std::cout << "GraphData constructor\n";
            m_v = gd->v;
            m_e = gd->e;
            if (static_cast<std::size_t>(m_e) != gd->edges.size())
            {
                throw std::range_error("error in file data : edge count doesn't match edge list size ");
            }
            m_adj = std::vector<std::vector<int>>(gd->e);
            for (auto e : gd->edges)
            {
                addEdgeNV(e.v, e.w);
            }
        }

        // rule of 5 not needed, no required destructor
        // Empty destructors 
            // make the type no longer trivial 
            // Have no functional use 
            // Can affect inlining of destruction 
            // Implicitly disable move operations
        // Jason Turner.C++ Best Practices(Kindle Locations 516 - 517).leanpub.com.
        //virtual ~AdjacencyListGraph() = default;
        //AdjacencyListGraph(AdjacencyListGraph&&) = delete;
        //AdjacencyListGraph(const AdjacencyListGraph &alg) = delete;
        //AdjacencyListGraph& operator=(const AdjacencyListGraph& alg) = delete;
        //AdjacencyListGraph& operator=(const AdjacencyListGraph&& alg) = delete;


        // V : number of vertices
        virtual int v() const { return m_v; }

        // E : number of edges
        virtual int e() const { return m_e; }

        // addEdge: add an edge to the specified vertex
        virtual void addEdge(int v, int w)
        {
            m_adj[v].push_back(w);
            m_adj[w].push_back(v);
        }

        // addEdgeNV: nonvirtual for constructor
        void addEdgeNV(int v, int w)
        {
            m_adj[v].push_back(w);
            m_adj[w].push_back(v);
        }

        // adj: get a list of vertices adjacent to v
        virtual const std::vector<int> &adj(int v) const
        {
            return m_adj[v];
        }

        // toString : return string representation
        virtual std::string toString() const
        {
            char buffer[1024];
            snprintf(buffer, sizeof(buffer), "%zu", m_adj.size());
            // avoid implicit conversion rule
            return std::string(buffer);
        }
    };

    // adjacency list graph factory
    std::unique_ptr<Graph> NewAdjacencyListGraph(int v)
    {
        return std::make_unique<AdjacencyListGraph>(v);
    }

    std::unique_ptr<Graph> NewAdjacencyListGraph(const GraphData *gd)
    {
        return std::make_unique<AdjacencyListGraph>(gd);
    }
}
