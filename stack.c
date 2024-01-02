#include<malloc.h>
#include<stdio.h>
//Stack Implimentation using DoublyLinklist
//..................Stack Structure................//
typedef struct Node{
	struct Node* next;
	struct Node* prev;
        void* val;
}Node;


typedef struct stack{
	Node* top;
	unsigned int size;
}stack;

//...............Stack Interface API................//

int len(stack* s);

void push(void* data, stack* s);

void pop(stack* s);

int top(stack* s);

stack* createStack()
{
  stack* st = (stack*) malloc(sizeof(stack));
  return st;
}
//..............................//

Node* createNode(void* data)
{
  struct Node* newNode = (Node*)malloc(sizeof(Node));
  //new->next = NULL;
  //new->prev = NULL;
  newNode->val = data;

  return newNode;
}


int len(stack* s)
{
  return s->size;
}


void push(void* data, stack* s)
{
  Node* newNode = createNode(data);

  if (!s->size)
  {
    s->top = newNode;
    s->top->prev= NULL;
    s->size++;
  }
  else
    {
      newNode->prev = s->top;
      s->top->next = newNode;
      //new->next = NULL;
      s->top = newNode;
      s->size = s->size+1;
    }
}

void pop(stack *s)
{
 
  if(!s->size)
    {
      printf("Empty");
    }
  else if(s->size == 1)
    {
      s->top = NULL;
      //s->top->next = NULL;
      s->size--;
    }
  else
    {
      s->top = s->top->prev;
      s->top->next = NULL;
      s->size--;
    }
}

int main()
{
  stack* s = createStack();

  /* for(int i=0; i<5; i++) */
  /*   { */
  /*     push(i*2,s); */
  /*   } */

  /* for(int i=0; i<5; i++) */
  /*   { */
  /*     printf("%d",s->top->val); */
  /*     s->top = s->top->prev; */
  /*   } */

  push("121",s);
  push("322",s);
  push("sddfui",s);

  int p = len(s);
    printf("%d\n",p);
  
  for(int i=0;i<3; i++){
  printf("%s\n",s->top->val);
  pop(s);
}
  return 0;
 
}
      
