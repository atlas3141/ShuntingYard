//Shunting yard converts infix to postfix
//Josh Howell, Feb 2017

#include "Node.h"
#include "Stack.h"
#include <cstdlib>
#include <cstring>
using namespace std;

bool isOperator(char c);
int precedence(char c);
Stack* shuntingYard(char* input);
int main(){
  char input[50];
  cin.get(input, 50); //get the input and start the algorithim
  shuntingYard(input);
}
Stack* shuntingYard(char* input){ // the actuall shunting yard thing
  int i = 0;
  Stack* operatorStack = new Stack(); 
  Stack* outputStack = new Stack();
  while (input[i]){ //run through the string and pick it apart
    if(isdigit(input[i])){ // if its a number, put it on the output stack
      outputStack->push(new Node(atoi(&input[i])));
      cout << outputStack->peek()->getIntData() << " "; //im printing it at runtime because its easier
      while(isdigit(input[i+1])){ //move it off the number
	i++;
      }
    }
    else if (isOperator(input[i])){ //if its a * / + =
      while(operatorStack->peek()){ //if theres a number with lower precedence on the operator stack, move it to the output stack
	if (precedence(input[i]) >= precedence(operatorStack->peek()->getCharData())){
	    break;
	  }
	outputStack->push(operatorStack->pop()); //add the current operator to the operatorStack
	cout << outputStack->peek()->getCharData() << " ";
	  }
      operatorStack->push(new Node(input[i]));
      }
    else if (input[i] == '('){ //simply add the ( to the operator stack
      operatorStack->push(new Node(input[i]));
    }
    else if (input[i] == ')'){ //if its a ) add all the operators in the stack to the output
      while(operatorStack->peek()->getCharData() != '('){ //until theres a (
	outputStack->push(operatorStack->pop());
	cout << outputStack->peek()->getCharData() <<  " ";
      }
      delete operatorStack->pop();
    }
    i++;
  }
  while(operatorStack->peek()){ //put the operator stack on the output stack
    outputStack->push(operatorStack->pop());
    cout <<  outputStack->peek()->getCharData() << " ";
  }
  cout << endl;
  delete operatorStack;
  return outputStack;
}
bool isOperator(char c){
  if (c == '-' ||
      c == '+' ||
      c == '^' ||
      c == '*' ||
      c == '/'){
    return true;
  }
  return false;
}
int precedence(char c){ // gives things piority pemdos and all that
  int precedence[256];
  precedence['-'] = 1;
  precedence['+'] = 1;
  precedence['*'] = 2;
  precedence['/'] = 2;
  precedence['^'] = 3;
  precedence['('] = -1;
  return precedence[c];
}
