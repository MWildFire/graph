#include <catch.hpp>
#include <sstream>
#include "graph.cpp"

TEST_CASE ("creating, printing graph, adding edge")
{
    graph_t graph(6);
    graph.addEdge(4,5);
    graph.addEdge(1,4);
    graph.addEdge(4,2);
    graph.addEdge(5,3);
    std::string output
    {
        "\n0 0 0 0 0 0\n"
        "0 0 0 0 1 0\n"
        "0 0 0 0 1 0\n"
        "0 0 0 0 0 1\n"
        "0 1 1 0 0 1\n"
        "0 0 0 1 1 0"
    };
    std::ostringstream stream;
    graph.printMatrix(stream);
    REQUIRE(stream.str()==output);
}

TEST_CASE ("removing edges")
{
    graph_t graph(6);
    graph.addEdge(4,5);
    graph.addEdge(1,4);
    graph.addEdge(4,2);
    graph.addEdge(5,3);
    graph.removeEdge(5,3);
    std::string output
    {
        "\n0 0 0 0 0 0\n"
        "0 0 0 0 1 0\n"
        "0 0 0 0 1 0\n"
        "0 0 0 0 0 0\n"
        "0 1 1 0 0 1\n"
        "0 0 0 0 1 0"
    };
    std::ostringstream stream;
    graph.printMatrix(stream);
    REQUIRE(stream.str()==output);
}



TEST_CASE ("testing DFS")
{
    graph_t graph(6);
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(2,3);
    graph.addEdge(3,4);
    graph.DFS();
    REQUIRE (graph.DFSinfo(graph.DFS()) == true);
}


