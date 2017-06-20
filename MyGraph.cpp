/* 
 * File:   MyGraph.cpp
 * Author: user
 * 
 * Created on January 24, 2014, 4:39 PM
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "MyGraph.h"
#include "MyQueue.h"

MyGraph::MyGraph() {
    startGraphNode = NULL;
}

MyGraph::MyGraph(const MyGraph& orig) {
}

MyGraph::~MyGraph() {
}

/*method for inserting a new node into the graph*/
void MyGraph::insertGraphNode(char id) {
    //allocate space for new node
    GRAPHNODEPTR newNode = (GRAPHNODEPTR) malloc(sizeof (GRAPHNODE));

    //put values on new node
    newNode->id = id;
    newNode->startNeighbor = NULL;
    newNode->isVisited = 0;

    //insert node into the beginning of the list
    GRAPHNODEPTR temporal = startGraphNode;
    newNode->nextGraphNode = temporal;
    startGraphNode = newNode;
}

/*gets a node from the graph, id criteria*/
MyGraph::GRAPHNODEPTR MyGraph::getNode(char id) {
    //variable
    GRAPHNODEPTR current = startGraphNode;

    while (current != NULL && current->id != id) {
        current = current->nextGraphNode;
    }
    
    //means that it could find the node!
    return current;
}

/*inserts a neighbor at the selected node*/
void MyGraph::insertNeighbor(char idNode, int costNeighbor, char idNeighbor) {
    //get the node
    GRAPHNODEPTR currentNode = getNode(idNode);
    
    //create a new neighbor
    NEIGHBORNODEPTR newNeighbor = (NEIGHBORNODEPTR)malloc(sizeof(NEIGHBORNODE));
    newNeighbor->id = idNeighbor;
    newNeighbor->cost = costNeighbor;
    
    //insert new node at the beginning of the list
    NEIGHBORNODEPTR neighborTemp = currentNode->startNeighbor;
    newNeighbor->nextNeighbor = neighborTemp;
    currentNode->startNeighbor = newNeighbor;
}

/*travel the whole graph with depth first search*/
void MyGraph::travelGraphDepthFirstSearch() {
    
    /*********************************/
    /*put all marks with not visited*/
    GRAPHNODEPTR graphTemp = startGraphNode;
    while(graphTemp != NULL){
        graphTemp->isVisited = 0;
        graphTemp = graphTemp->nextGraphNode;
    }
    /*********************************/
    
    //control message
    printf("Visited nodes order:\n      ");
    
    /***************************************************/
    /*travel on the graph for check marks and go deeper*/
    graphTemp = startGraphNode;
    while(graphTemp != NULL){
        
        //check if the node was already visited
        if(graphTemp->isVisited != 1){
            depthFirstSearch(graphTemp);
        }
        graphTemp = graphTemp->nextGraphNode;
    }
    /***************************************************/
    
    printf("NULL\n\n");
}

/*deepen into the received node*/
void MyGraph::depthFirstSearch(GRAPHNODEPTR node) {
    
    //put current node mark to one
    node->isVisited = 1;
    
    //control message
    printf("%c--> ", node->id);
    
    //travel through neighbors list
    NEIGHBORNODEPTR neighborTemp = node->startNeighbor;
    while(neighborTemp != NULL){
        //get current node from that neighbor
        GRAPHNODEPTR nodeFromNeighbor = getNode(neighborTemp->id);
        
        //check that node's mark
        if(nodeFromNeighbor->isVisited != 1){
            //deepens
            depthFirstSearch(nodeFromNeighbor);
        }//end if
        
        neighborTemp = neighborTemp->nextNeighbor;
    }//end while
    
}

/*breadth search into the graph*/
void MyGraph::travelGraphBreadthFirstSearch() {
    
    /*********************************/
    /*put all marks with not visited*/
    GRAPHNODEPTR graphTemp = startGraphNode;
    while(graphTemp != NULL){
        graphTemp->isVisited = 0;
        graphTemp = graphTemp->nextGraphNode;
    }
    /*********************************/
    
    //control message
    printf("Visited nodes order:\n      ");
    
    /***************************************************/
    /*travel on the graph for check marks and go deeper*/
    graphTemp = startGraphNode;
    while(graphTemp != NULL){
        
        //check if the node was already visited
        if(graphTemp->isVisited != 1){
            breadthFirstSearch(graphTemp);
        }
        graphTemp = graphTemp->nextGraphNode;
    }
    /***************************************************/
    
    printf("NULL\n\n");
}

void MyGraph::breadthFirstSearch(GRAPHNODEPTR node) {
    //variables
    char currentChar;
    
    //create an empty queue
    MyQueue myQueue;
    
    //mark node as visited
    node->isVisited = 1;
    //control message
    printf("%c--> ", node->id);
    
    //put current node into the queue
    myQueue.enQueue(node->id);
    
    //travel while current queue is not empty
    while(!myQueue.isEmpty()){
        //get the first element of the queue
        currentChar = myQueue.deQueue();
        
        //get the whole node from that char
        GRAPHNODEPTR nodeFromChar = getNode(currentChar);
        
        //get the neighbor list
        NEIGHBORNODEPTR nodeNeighbour = nodeFromChar->startNeighbor;
        
        //travel the whole neighbor list
        while(nodeNeighbour != NULL){
            //get the node from neighbor
            GRAPHNODEPTR currentNode = getNode(nodeNeighbour->id);
            
            //ask if the node was already visited
            if(currentNode->isVisited == 0){
                currentNode->isVisited = 1;
                myQueue.enQueue(currentNode->id);
                
                //control message
                printf("%c--> ", currentNode->id);
            }
            
            //go on
            nodeNeighbour = nodeNeighbour->nextNeighbor;
        }
        
    }//end while
}



/*prints the list without neighbors*/
void MyGraph::printGraphWithoutNeighbors() {
    GRAPHNODEPTR current = startGraphNode;
    while (current != NULL) {
        printf("%c--> ", current->id);
        current = current->nextGraphNode;
    }
    printf(" NULL\n\n");
}

/*prints the list with neighbors*/
void MyGraph::printGraphWithNeighbors() {
    //variables
    GRAPHNODEPTR currentNode = startGraphNode;
    NEIGHBORNODEPTR currentNeighbor;
    
    //go over the list
    while(currentNode != NULL){        
        //print current node
        printf("Node %c: \n     ", currentNode->id);
        
        //get the list of neighbors from that node
        currentNeighbor = currentNode->startNeighbor;
        
        //go over all neighbors
        while(currentNeighbor != NULL){
            printf("%c(%d)--> ", currentNeighbor->id, currentNeighbor->cost);
            currentNeighbor = currentNeighbor->nextNeighbor;
        }
        printf(" NULL\n\n");
        currentNode = currentNode->nextGraphNode;
    }//end while
}

