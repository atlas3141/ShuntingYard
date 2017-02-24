#include <iostream>
#include "Node.h"


using namespace std;

Node::Node(char d){
  next = NULL;
  data.c = d;
  type = 1;
}
Node::Node(int d){
  next = NULL;
  data.i = d;
  type = 2;
}
//deconstructor, clear memory
Node::~Node(){

}
//returns a pointer to the next node
Node* Node::getNext(){
  return next;
}
//sets the pointer to the next node
void Node::setNext(Node* n){
  next = n;
}
//returns a pointer to the Student class
int Node::getIntData(){
  return data.i;
}
char Node::getCharData(){
  if (type == 1){
    return data.c;
  }
  else return 0;
}
int Node::getType(){
  return type;
}


