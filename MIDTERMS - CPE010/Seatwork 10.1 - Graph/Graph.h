#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <map>

class Vertex {
    public:
        int id;
        std::map<int, int> connectedTo;

        Vertex() {
        }

        Vertex(int key) {
            id = key;
        }

        void addNeighbor(int nbr, int weight = 0) {
            connectedTo[nbr] = weight;
        }

        std::vector<int> getConnections() {
            std::vector<int> keys;
            for (std::map<int, int>::iterator it = connectedTo.begin();
                it != connectedTo.end();
                ++it) {
                keys.push_back(it->first);
            }
            return keys;
        }

        int getId() {
            return id;
        }

        int getWeight(int nbr) {
            return connectedTo[nbr];
        }

        friend std::ostream &operator<<(std::ostream &, Vertex &);
};

inline std::ostream &operator<<(std::ostream &stream, Vertex &vert) {
    std::vector<int> connects = vert.getConnections();
    for (unsigned int i = 0; i < connects.size(); i++) {
        stream << "( " << vert.id << " , " << connects[i] << " ) \n";
    }
    return stream;
}

class Graph {
    public:
        std::map<int, Vertex> vertList;
        int numVertices;

        Graph() {
            numVertices = 0;
        }

        Vertex addVertex(int key) {
            numVertices++;
            Vertex newVertex = Vertex(key);
            this->vertList[key] = newVertex;
            return newVertex;
        }

        Vertex *getVertex(int n) {
            for (std::map<int, Vertex>::iterator it = vertList.begin(); it != vertList.end(); ++it) {
                if (it->first == n) {
                    Vertex *vpntr = &vertList[n];
                    return vpntr;
                }
            }
            return nullptr;
        }

        bool contains(int n) {
            for (std::map<int, Vertex>::iterator it = vertList.begin(); it != vertList.end(); ++it) {
                if (it->first == n) {
                    return true;
                }
            }
            return false;
        }

        void addEdge(int f, int t, int cost = 0) {
            if (!this->contains(f)) {
                std::cout << f << " was not found, adding!" << std::endl;
                this->addVertex(f);
            }
            if (!this->contains(t)) {
                std::cout << t << " was not found, adding!" << std::endl;
                this->addVertex(t);
            }
            vertList[f].addNeighbor(t, cost);
        }

        std::vector<int> getVertices() {
            std::vector<int> verts;
            for (std::map<int, Vertex>::iterator it = vertList.begin(); it != vertList.end();  ++it) {
                verts.push_back(it->first);
            }
            return verts;
        }

        friend std::ostream &operator<<(std::ostream &, Graph &);
};

inline std::ostream &operator<<(std::ostream &stream, Graph &grph) {
    for (std::map<int, Vertex>::iterator it = grph.vertList.begin(); it != grph.vertList.end(); ++it) {
        stream << it->second;
    }
    return stream;
}

#endif