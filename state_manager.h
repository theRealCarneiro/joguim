#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

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

StateStack *create_stack();

int push_state_stack(StateStack **head, State *c);

int pop_state_stack(StateStack **s);

int update_state_stack(StateStack *s, float deltatime);

State *top_state_stack(StateStack *head);

#endif /* STATE_MANAGER_H */
