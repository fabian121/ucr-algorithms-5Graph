/* 
 * File:   main.cpp
 * Author: user
 *
 * Created on January 24, 2014, 4:37 PM
 */

#include <cstdlib>
#include <stdio.h>

#include "MyGraph.h"
#include "MyQueue.h"

using namespace std;
void testGraph1();
void testQueue();

/*
 * 
 */
int main(int argc, char** argv) {
    
    //testQueue();
    testGraph1();

    return 0;
}

void testQueue(){
    MyQueue myQueue;
    myQueue.enQueue('a');
    myQueue.enQueue('b');
    myQueue.enQueue('c');
    myQueue.enQueue('d');
    myQueue.enQueue('e');
    myQueue.enQueue('f');
    myQueue.enQueue('g');
    
    myQueue.printQueue();
    printf("Call dequeue: %c\n", myQueue.deQueue());
    printf("Call dequeue: %c\n", myQueue.deQueue());
    printf("Call dequeue: %c\n", myQueue.deQueue());
    printf("Call dequeue: %c\n", myQueue.deQueue());
    printf("Call dequeue: %c\n", myQueue.deQueue());
    printf("Call dequeue: %c\n", myQueue.deQueue());
    printf("Call dequeue: %c\n", myQueue.deQueue());
    printf("Call dequeue: %c\n", myQueue.deQueue());
    
    printf("\n");
    myQueue.printQueue();
}


void testGraph1(){
    MyGraph myGraph;
    
    //PARA LA CLASE RECORDAR EXCLUIR EL NODO B EN LA PRIMER PARTE DE LA LECCION
    //INCLUIRLO CUANDO SE ESTA HACIENDO EL PRE/POST-ORDEN
    
    //node B
    myGraph.insertGraphNode('B');
    myGraph.insertNeighbor('B', 5, 'E');
    
    //node A
    myGraph.insertGraphNode('A');
    myGraph.insertNeighbor('A', 4, 'D');
    
    //node C
    myGraph.insertGraphNode('C');
    myGraph.insertNeighbor('C', 4, 'D');
    myGraph.insertNeighbor('C', 6, 'F');
    
    //node D
    myGraph.insertGraphNode('D');
    myGraph.insertNeighbor('D', 1, 'A');
    myGraph.insertNeighbor('D', 6, 'F');
    myGraph.insertNeighbor('D', 3, 'C');
    
    //node F
    myGraph.insertGraphNode('F');
    myGraph.insertNeighbor('F', 5, 'E');
    myGraph.insertNeighbor('F', 4, 'D');
    myGraph.insertNeighbor('F', 3, 'C');
    
    //node E
    myGraph.insertGraphNode('E');
    myGraph.insertNeighbor('E', 6, 'B');
    myGraph.insertNeighbor('E', 6, 'F');
    
//    myGraph.printGraphWithoutNeighbors();
//    printf("\n\n");
//    myGraph.printGraphWithNeighbors();
    
    //MyGraph::GRAPHNODEPTR myCurrentNode = myGraph.getNode(5, ' ');
    //printf("Searching result: %c\n", myCurrentNode->data);
    
    //depth first search travel
    myGraph.travelGraphDepthFirstSearch();
    
    printf("\n\n");
    
    //breadth first search
    myGraph.travelGraphBreadthFirstSearch();
}
