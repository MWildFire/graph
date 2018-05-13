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
        "0 0 0 0 0 0\n"
        "0 0 0 0 1 0\n"
        "0 0 0 0 1 1\n"
        "0 0 0 0 0 1\n"
        "0 1 1 0 0 1\n"
        "0 0 0 1 1 0\n"
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
        "0 0 0 0 0 0\n"
        "0 0 0 0 1 0\n"
        "0 0 0 0 1 1\n"
        "0 0 0 0 0 0\n"
        "0 1 1 0 0 1\n"
        "0 0 0 0 1 0\n"
    };
    std::ostringstream stream;
    graph.printMatrix(stream);
    REQUIRE(stream.str()==output);
}




TEST_CASE ("testing DFS")
{
    graph_t graph(6);
    graph.addEdge(4,5);
    graph.addEdge(1,4);
    graph.addEdge(4,2);
    graph.addEdge(5,3);
    graph.DFS();
    graph_t::VertexState *state = new graph_t::VertexState[6];
    for (int i = 0; i < 6; i++)
    REQUIRE (state[i] == graph_t::Black);
}

