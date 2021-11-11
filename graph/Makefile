CPPSRC = graph.cpp \
	src/adjlistgraph.cpp\
	src/dfs.cpp\
	src/graphData.cpp\
	test/graph_dfs_test.cpp\
	test/graph_input_test.cpp

tidy: 
	clang-tidy $(CPPSRC)  -- -std=c++14 -I./include -I../googletest/googletest/include

