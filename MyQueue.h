/* 
 * File:   MyQueue.h
 * Author: user
 *
 * Created on January 29, 2014, 9:22 AM
 */

#ifndef MYQUEUE_H
#define	MYQUEUE_H

class MyQueue {
public:
    MyQueue();
    MyQueue(const MyQueue& orig);
    virtual ~MyQueue();
    
    struct Queue{
        char id;
        struct Queue *nextPtr;
    };
    
    typedef struct Queue QUEUE;
    typedef QUEUE *QUEUEPTR;
    
    //metodos
    void enQueue(char id);
    char deQueue();
    void printQueue();
    int isEmpty();
    
    //variables
    QUEUEPTR headPtr, tailPtr;
private:

};

#endif	/* MYQUEUE_H */

