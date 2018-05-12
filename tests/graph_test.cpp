#include <catch.hpp>
#include <sstream>
#include "graph.cpp"

TEST_CASE ("creating, printing graph, adding edge")
{
    graph_t graph(4);
    graph.addEdge(1,2);
    graph.addEdge(2, 3);
    graph.addEdge(3,4);
    std::string output
    {
        "0 1 0 1\n"
        "1 0 1 0\n"
        "0 1 0 1\n"
        "0 0 1 0\n"
    };
    std::ostringstream stream;
    graph.printMatrix(stream);
    REQUIRE(stream.str()==output);
}

TEST_CASE ("removing edges")
{
    graph_t graph(6);
    graph.addEdge(1,2);
    graph.addEdge(2, 3);
    graph.addEdge(3,4);
    graph.removeEdge(3,4);
    std::string output
    {
        "0 1 0 1\n"
        "1 0 1 0\n"
        "0 1 0 0\n"
        "0 0 0 0\n"
    };
    std::ostringstream stream;
    graph.printMatrix(stream);
    REQUIRE(stream.str()==output);
}
    
    


TEST_CASE ("testing DFS")
{
    graph_t graph(6);
    graph.addEdge(1,2);
    graph.addEdge(2, 3);
    graph.addEdge(3,4);
    graph.DFS();
    graph_t::VertexState *state = new graph_t::VertexState[graph_t::vertexCount];
    for (int i = 0; i < graph_t::vertexCount; i++)
        REQUIRE (state[i] = graph_t::Black);
}
