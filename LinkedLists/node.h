/*********************************************************************
** Program Filename: node.h
** Author: Katie Blickenstaff
** Date: 8/14/2020
** Description: Header file for class Node
*********************************************************************/

#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int val;    // the value that this node stores
    Node *next; // a pointer to the next node in the list
    // you can add constructors or other functionality if you find it useful or necessary
};

#endif