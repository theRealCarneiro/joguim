#include "state_manager.h"
#include "stdio.h"

unsigned int init_state1() {
  printf("state 1 created\n");
  return 0;
}

int main(){
	StateStack *s = NULL;
	State state1 = {0};
	state1.init = init_state1;
	push_state_stack(&s, &state1);
	return 0;
}
