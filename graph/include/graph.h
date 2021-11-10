#ifndef GRAPH_H__
#define GRAPH_H__

#include <vector>
#include <deque>
#include <memory>
#include <string>

namespace Graph
{
    /*
    C++ code in this file is based on the Java implementation from
    Sedgewick, Robert. Algorithms . Pearson Education. Kindle Edition. Chapter 4
    */
    
    // forward references
    class Graph;

    /** data input */
    // Edge : data for one edge
    struct Edge
    {
        Edge() :v(0),w(0) {}
        Edge(int v, int w) : v(v), w(w) {}

        int v;
        int w;
    };

    // GraphData : input data
    struct GraphData
    {
        int v;
        int e;
        std::vector<Edge> edges;
    };
    

    int scanInt(std::ifstream& f);
    Edge scanEdge(std::ifstream& f);
    std::unique_ptr<GraphData> getGraphData(std::string fname);

    // Graph :  interface to undirected graph
    // this implemntation assumes the number of vertices are known at init time.
    // edges can be added dynamically
    // Sedgewick, Robert. Algorithms . Pearson Education. Kindle Edition. Chapter 4
    class Graph
    {
    public:
        /**
        * required for implementation destructors
        */
        virtual ~Graph() {}

        /**
        *  v : number of vertices
        */
        virtual int v() const = 0;

        /**
        *  e : number of edges
        */
        virtual int e() const = 0;

        /**
        *  addEdge : add an edge from v to w
        */
        virtual void addEdge(int v, int w) = 0;

        /**
        * Adj : get a list of vertices adjacent to v
        */
        virtual const std::vector<int>& adj(int v) const = 0;

        /**
        *  ToString : return string representation
        */
        virtual std::string toString() const = 0;
    };

    // graph factory
    std::unique_ptr<Graph> NewAdjacencyListGraph(int v);
    std::unique_ptr<Graph> NewAdjacencyListGraph(const GraphData *gd);

    class  DFS {

    public: 
        /**
        * HasPathTo : return true if there is a path from root to v
        */
        virtual bool hasPathTo(int v)  const = 0;

        /** 
        * pathTo : returns list of nodes in path from root to v
        */
        virtual std::deque<int> pathTo(int v)  = 0;
    };

    /** DFS factory
    * when called the DFS performs a search from the node 'source' on 
    * the selected Graph. 
    */
    std::unique_ptr<DFS> NewDFS(const Graph* g, int source);
};

#endif
