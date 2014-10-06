/* 
 * File:   MyQueue.cpp
 * Author: user
 * 
 * Created on January 29, 2014, 9:22 AM
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "MyQueue.h"

MyQueue::MyQueue() {
    headPtr = NULL;
    tailPtr = NULL;
}

MyQueue::MyQueue(const MyQueue& orig) {
}

MyQueue::~MyQueue() {
}

/*enqueues a new node into the list*/
void MyQueue::enQueue(char id) {
    //creates the new node
    QUEUEPTR newNode = (QUEUEPTR) malloc(sizeof (QUEUE));
    newNode->id = id;
    newNode->nextPtr = NULL;

    if (headPtr == NULL) {
        headPtr = newNode;
    } else {
        tailPtr->nextPtr = newNode;
    }
    tailPtr = newNode;
}

/*dequeues a node from the list*/
char MyQueue::deQueue() {
    //variables
    char value = '\0';
    QUEUEPTR nodeTemp;

    if (!isEmpty()) {
        //store values
        value = headPtr->id;
        nodeTemp = headPtr;
        headPtr = headPtr->nextPtr;

        if (headPtr == NULL) {
            tailPtr = NULL;
        }

        free(nodeTemp);
    }
    return value;
}

int MyQueue::isEmpty() {
    return (headPtr == NULL)?1:0;
}


/*prints the whole queue*/
void MyQueue::printQueue() {
    //variables
    QUEUEPTR currentNode = headPtr;

    //ask if the queue is empty
    if (currentNode == NULL) {
        printf("The queue is empty.\n\n");
    } else {
        printf("Queue values: \n        ");
        while (currentNode != NULL) {
            printf("%c--> ", currentNode->id);
            currentNode = currentNode->nextPtr;
        }
        printf("NULL\n\n");
    }
}



