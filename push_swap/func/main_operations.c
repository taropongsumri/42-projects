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