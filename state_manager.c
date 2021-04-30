#include <stdio.h>
#include <stdlib.h>

typedef unsigned int (*fn_ptr)();
typedef unsigned int (*fn_ptr_fl)(float);

typedef struct State{
	fn_ptr init;
	fn_ptr_fl update;
	fn_ptr_fl draw;
	fn_ptr destroy;
} State;

typedef struct StateStack{
	State *state;	
	struct StateStack *next;
} StateStack;

StateStack *create_stack(){
	return (StateStack*)malloc(sizeof(StateStack));
}

void push(StateStack **head, State *c){
	StateStack *s = create_stack();
	s->state = c;
	s->next = *head;
	*head = s;
}

StateStack *pop(StateStack **p){
	StateStack *temp = *p;
	*p = temp->next;
	free(temp);
	return *p;
}

State *top(StateStack *head){
	return head->state;
}
