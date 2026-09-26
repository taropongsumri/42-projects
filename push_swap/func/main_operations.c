#include "../src/push_swap.h"

int swap(t_ps_node **s){
    t_ps_node *first_node;
    t_ps_node *sec_node;
    t_ps_node *third_node;

    first_node = (*s);
    if (first_node == NULL || first_node->next == NULL)
        return (0);

    sec_node = first_node->next;
    third_node = sec_node->next;
    sec_node->next = first_node;
    first_node->next = third_node;
    *s = sec_node;
    return (1);
}

int push(t_ps_node **get, t_ps_node **push){
    t_ps_node *first;

    if ((*get) == NULL)
        return (0);

    first = *get;
    *get = first->next;
    first->next = *push;
    *push = first;

    return (1);
}

int rotate(t_ps_node **stack){
    t_ps_node *first;
    t_ps_node *sec;

    if (!stack || !*stack || !(*stack)->next)
        return (0);

    first = *stack;
    sec = *stack;

    while (sec->next != NULL)
        sec = sec->next;

    *stack = first->next;
    sec->next = first;

    return (1);
}

int reverse_rotate(t_ps_node **stack){
    t_ps_node *first;
    t_ps_node *sec;
    t_ps_node *third;

    if (!stack || !*stack || !(*stack)->next)
        return (0);

    first = (*stack);
    sec = *stack;
    third = *stack;
    
    while (sec->next != NULL){
        third = sec;    
        sec = sec->next;
    }

    (*stack) = sec;
    (*stack)->next = first;
    third->next = NULL;
    return (1);
}