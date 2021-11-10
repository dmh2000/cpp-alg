#include <memory>
#include <deque>
#include <vector>
#include "graph.h"

/*
C++ code in this file is based on the Java implementation from
Sedgewick, Robert. Algorithms . Pearson Education. Kindle Edition. Chapter 4
*/

// DFS : depth first search on an undirected graph
namespace Graph {

	class DFSImpl : public DFS {
	private:
		std::vector<bool> m_marked;
		std::vector<int>  m_edgeTo;
		int m_source;


		// search : private function that
		void search(const Graph* g, int v) {
			m_marked[v] = true;
			// for all connections from v to other nodes
			for (auto w : g->adj(v)) {
				// if not yet visited
				if (!m_marked[w]) {
					// edge w from v
					m_edgeTo[w] = v;
					// search from w
					search(g, w);
				}
			}
		}

	public:
		DFSImpl(const Graph* g, int source) : m_source(source)
		{
			for (auto v = 0; v < g->v(); v++) {
				m_marked.emplace_back(false);
				m_edgeTo.emplace_back(0);
			}

			// update the search results
			search(g, source);
		}

		/**
		* HasPathTo : return true if there is a path from source to v
		*/
		virtual bool hasPathTo(int v) const {
			return m_marked[v];
		}

		/**
		* pathTo : returns list of nodes in path from source to v
		*/
		virtual std::deque<int> pathTo(int v)  {
			std::deque<int> path;

			// if there is no path from source to v
			if (!hasPathTo(v)) {
				return path;
			}

			// prepend each node from destination to source
			for (int x = v; x != m_source; x = m_edgeTo[x]) {
				path.emplace_front(x);
			}
			// add source to beginning of path
			path.emplace_front(m_source);

			return path;
		}
	};

	std::unique_ptr<DFS> NewDFS(const Graph* g, int source) {
		return std::make_unique<DFSImpl>(g, source);
	}
}
