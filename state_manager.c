#include <stdio.h>
#include <stdlib.h>
#include "state_manager.h"

StateStack *create_stack(){
	return (StateStack*)malloc(sizeof(StateStack));
}

int push_state_stack(StateStack **head, State *c){
	StateStack *s = create_stack();
	s->state = c;
	s->next = *head;
	*head = s;
	if (c->init != NULL) return c->init();
	return 1;
}

int pop_state_stack(StateStack **s){
	StateStack *stack = *s;
	State *state = stack->state;
	*s = stack->next;
	free(stack);
	if(state->destroy != NULL) return state->destroy();
	return 1;
}

int update_state_stack(StateStack *s, float deltatime){
	if (s->state->update != NULL) return s->state->update(deltatime);
	return 1;
}

State *top_state_stack(StateStack *head){
	return head->state;
}
