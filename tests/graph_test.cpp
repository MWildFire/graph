#include <catch.hpp>
#include <sstream>
#include "graph_t.hpp"

TEST_CASE ("creating, printing graph, adding edge")
{
    graph_t graph(4);
    grapg.addEdge(1,2);
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
    graph.print(stream);
    REQUIRE(stream.str()==output);
}

TEST_CASE ("removing edges")
{
    graph_t graph(6);
    grapg.addEdge(1,2);
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
    graph.print(stream);
    REQUIRE(stream.str()==output);
}
    
    
}

TEST_CASE ("testing DFS")
{
    graph_t graph(6);
    grapg.addEdge(1,2);
    graph.addEdge(2, 3);
    graph.addEdge(3,4);
    graph.DFS();
    VertexState *state = new VertexState[vertexCount];
    for (int i = 0; i < vertexCount; i++)
        REQUIRE (state[i] = Black);
}
