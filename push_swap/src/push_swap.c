#include "../src/push_swap.h"
#include <stdlib.h>

int main(int argc, char **argv){

    t_stack **stack_a;
    t_stack **stack_b;


    if (argc < 2)
        return 0;

    ft_clear_args(argc, argv);
    stack_a = (t_stack **)malloc(sizeof(t_stack));
    stack_b = (t_stack **)malloc(sizeof(t_stack));

    *stack_a = NULL;
    *stack_b = NULL;

    return (0);
}