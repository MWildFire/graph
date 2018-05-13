//
//  graph_t.cpp
//  graph
//
//  Created by Сурков Дмитрий Валерьевич on 13.05.2018.
//  Copyright © 2018 Сурков Дмитрий Валерьевич. All rights reserved.
//

#include <iostream>

class graph_t
{
private:
    bool** adjacencyMatrix;
    int vertexCount;
public:
    graph_t(int vertexCount)
    {
        this->vertexCount = vertexCount;
        adjacencyMatrix = new bool*[vertexCount];
        for (int i = 0; i < vertexCount; i++)
        {
            adjacencyMatrix[i] = new bool[vertexCount];
            for (int j = 0; j < vertexCount; j++)
                adjacencyMatrix[i][j] = false;
        }
    }
    
    void addEdge(int i, int j)
    {
        if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount)
        {
            adjacencyMatrix[i][j] = true;
            adjacencyMatrix[j][i] = true;
        }
    }
    
    
    void removeEdge(int i, int j)
    {
        if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount)
        {
            adjacencyMatrix[i][j] = false;
            adjacencyMatrix[j][i] = false;
        }
    }
    
    int vertexCount_()
    {
        return vertexCount;
    }
    
    bool isEdge(int i, int j)
    {
        if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount)
            return adjacencyMatrix[i][j];
        else
            return false;
    }
    
    void printMatrix(std::ostream & stream)
    {
        if (adjacencyMatrix)
        {
            for (int i = 0; i < vertexCount; ++i)
            {
                stream << "\n";
                for (int j = 0; j < vertexCount; ++j)
                {
                    stream << adjacencyMatrix[i][j];
                    if( j != vertexCount - 1 )
                        stream << ' ';
                }
            }
        }
    }
    
    
    ~graph_t()
    {
        for (int i = 0; i < vertexCount; i++)
            delete[] adjacencyMatrix[i];
        delete[] adjacencyMatrix;
    }
    
    enum VertexState { White, Gray, Black };
    
    void DFS()
    {
        VertexState *state = new VertexState[vertexCount];
        for (int i = 0; i < vertexCount; i++)
            state[i] = White;
        runDFS(0, state);
    }
    
    void runDFS(int u, VertexState state[])
    {
        state[u] = Gray;
        for (int v = 0; v < vertexCount; v++)
            if (isEdge(u, v) && state[v] == White)
                runDFS(v, state);
        state[u] = Black;
    }
    
    int VertexState()
    {
        VertexState *state = new VertexState[vertexCount];
        for (int i = 0; i < vertexCount; i++)
            return state[i];
    }
};
