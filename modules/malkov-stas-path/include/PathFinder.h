// Copyright 2016 Malkov Stanislav

#ifndef MODULES_MALKOV_STAS_PATH_INCLUDE_PATHFINDER_H_
#define MODULES_MALKOV_STAS_PATH_INCLUDE_PATHFINDER_H_

class PathFinder {
 public:
    static const int PATH_NOT_EXISTS;
    static const int MAX_DISTANCE;

    PathFinder();
    PathFinder(int** graph, int vertice_num, int start_vertex);
    ~PathFinder();

    void SetGraph(int** graph, int vertice_num, int start_vertex);
    void SetStartVertex(int vertex);
    void SetPath(int from, int to, int distance);
    int GetDistance(int vertex) const;
    int* GetDistances() const;

 private:
    bool _IsInitialized;

    int ** _Graph;
    int _Size;
    int _StartVertex;

    int* _Distance;
    bool* _Visited;

    void UpdateGraph();
    void Reset();
    void CheckVetricesWithoutPath();
};

#endif  // MODULES_MALKOV_STAS_PATH_INCLUDE_PATHFINDER_H_
