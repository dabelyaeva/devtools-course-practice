// Copyright 2016 Malkov Stanislav

#include "../include/PathFinder.h"

#include <iostream>
#include <exception>

const int PathFinder::PATH_NOT_EXISTS = -1;
const int PathFinder::MAX_DISTANCE = 100000000;

PathFinder::PathFinder() {
    _IsInitialized = false;
}

PathFinder::PathFinder(int** graph, int vertice_num, int start_vertex) {
    _IsInitialized = false;
    SetGraph(graph, vertice_num, start_vertex);
}

void PathFinder::SetGraph(int** graph, int vertice_num, int start_vertex) {
    if (graph == 0)
        throw std::exception();
    if (vertice_num < 0)
        throw std::exception();
    if (start_vertex < 0 || start_vertex >= vertice_num)
        throw std::exception();

    _Size = vertice_num;
    _StartVertex = start_vertex;
    _Graph = new int*[_Size];
    for (int i = 0; i < _Size; i++) {
        _Graph[i] = new int[_Size];
        for (int j = 0; j < _Size; j++)
            _Graph[i][j] = graph[i][j];
    }

    Reset();
    UpdateGraph();

    _IsInitialized = true;
}

void PathFinder::UpdateGraph() {
    for (int i = 0; i < _Size; i++) {
        int max_distance = MAX_DISTANCE;
        int index_of_min_distance = -1;
        for (int k = 0; k < _Size; k++)
            if (!_Visited[k] && _Distance[k] < max_distance)
                index_of_min_distance = k;
        if (index_of_min_distance == -1)
            break;
        int im = index_of_min_distance;
        for (int j = 0; j < _Size; j++)
            if (im != j && _Graph[im][j] &&
                _Distance[im] + _Graph[im][j] < _Distance[j])
                _Distance[j] = _Distance[im] + _Graph[im][j];
        _Visited[im] = true;
    }
    CheckVetricesWithoutPath();
}

void PathFinder::CheckVetricesWithoutPath() {
    for (int i = 0; i < _Size; i++)
        if (_Distance[i] == MAX_DISTANCE)
            _Distance[i] = PATH_NOT_EXISTS;
}

void PathFinder::Reset() {
    if (_IsInitialized) {
        delete _Distance;
        delete _Visited;
    }
    _Distance = new int[_Size];
    _Visited = new bool[_Size];
    for (int i = 0; i < _Size; i++) {
        _Distance[i] = MAX_DISTANCE;
        _Visited[i] = false;
    }
    _Distance[_StartVertex] = 0;
}

int PathFinder::GetDistance(int vertex) const {
    if (!_IsInitialized)
        throw std::exception();
    if (vertex < 0 || vertex >= _Size)
        throw std::exception();
    return _Distance[vertex];
}

int* PathFinder::GetDistances() const {
    if (!_IsInitialized)
        throw std::exception();
    return _Distance;
}

void PathFinder::SetStartVertex(int vertex) {
    if (!_IsInitialized)
        throw std::exception();
    if (vertex < 0 || vertex >= _Size)
        throw std::exception();
    SetGraph(_Graph, _Size, vertex);
}

void PathFinder::SetPath(int from, int to, int distance) {
    if (!_IsInitialized)
        throw std::exception();
    if (from < 0 || from >= _Size)
        throw std::exception();
    if (to < 0 || to >= _Size)
        throw std::exception();
    if (distance < 0)
        throw std::exception();
    if (distance == MAX_DISTANCE)
        throw std::exception();
    if (from == to && distance != 0)
        throw std::exception();
    _Graph[from][to] = distance;
    SetGraph(_Graph, _Size, _StartVertex);
}

PathFinder::~PathFinder() {
    if (_IsInitialized) {
        delete _Distance;
        delete _Visited;
    }
}
