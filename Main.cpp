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
  cin.get(input, 50);
  shuntingYard(input);
}
Stack* shuntingYard(char* input){
  int i = 0;
  Stack* operatorStack = new Stack();
  Stack* outputStack = new Stack();
  while (input[i]){
    if(isdigit(input[i])){
      outputStack->push(new Node(atoi(&input[i])));
      cout << outputStack->peek()->getIntData() << " ";
      while(isdigit(input[i+1])){
	i++;
      }
    }
    else if (isOperator(input[i])){
      while(operatorStack->peek()){
	if (precedence(input[i]) >= precedence(operatorStack->peek()->getCharData())){
	    break;
	  }
	outputStack->push(operatorStack->pop());
	cout << outputStack->peek()->getCharData() << " ";
	  }
      operatorStack->push(new Node(input[i]));
      }
    else if (input[i] == '('){
      operatorStack->push(new Node(input[i]));
    }
    else if (input[i] == ')'){
      while(operatorStack->peek()->getCharData() != '('){
	outputStack->push(operatorStack->pop());
	cout << outputStack->peek()->getCharData() <<  " ";
      }
      delete operatorStack->pop();
    }
    i++;
  }
  while(operatorStack->peek()){
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
int precedence(char c){
  int precedence[256];
  precedence['-'] = 1;
  precedence['+'] = 1;
  precedence['*'] = 2;
  precedence['/'] = 2;
  precedence['^'] = 3;
  precedence['('] = -1;
  return precedence[c];
}
