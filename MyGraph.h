/* 
 * File:   MyGraph.h
 * Author: user
 *
 * Created on January 24, 2014, 4:39 PM
 */

#ifndef MYGRAPH_H
#define	MYGRAPH_H


class MyGraph {
public:
    MyGraph();
    MyGraph(const MyGraph& orig);
    virtual ~MyGraph();

    
    /**************************************************/
    /**************************************************/
    /*necessary data structures for manage my graph*/
    struct NeighborNode{
        char id;
        int cost;
        struct NeighborNode *nextNeighbor;
    };
    typedef struct NeighborNode NEIGHBORNODE;
    typedef NEIGHBORNODE *NEIGHBORNODEPTR;
    
    struct GraphNode{
        char id;
        NEIGHBORNODEPTR startNeighbor;
        int isVisited;
        struct GraphNode *nextGraphNode;
    };
    typedef struct GraphNode GRAPHNODE;
    typedef GRAPHNODE *GRAPHNODEPTR;
    /**************************************************/
    /**************************************************/
    
    void insertGraphNode(char id);
    void printGraphWithoutNeighbors();
    void printGraphWithNeighbors();
    void insertNeighbor(char idNode, int costNeighbor, char idNeighbor);
    GRAPHNODEPTR getNode(char id);
    void travelGraphDepthFirstSearch();
    void depthFirstSearch(GRAPHNODEPTR node);
    void travelGraphBreadthFirstSearch();
    void breadthFirstSearch(GRAPHNODEPTR node);
    
    //variables
    GRAPHNODEPTR startGraphNode;
private:
    
};

#endif	/* MYGRAPH_H */

