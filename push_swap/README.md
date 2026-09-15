*This project has been created as part of the 42 curriculum by ponsumri*

# Move Function
- sa / sb / ss
    - sa : Swap the top two numbers in a
    - sb : Swap the top two numbers in b
    - ss : sa and sb at the same time
- pa / pb
    - pa : Move top of b to top of a
    - pb : Move top of a to top of b
- ra / rb / rr
    - ra : Rotate a up (top becomes bottom)
    - rb : Rotate b up (top becomes bottom)
    - rr : ra and rb at the same time
- rra / rrb / rrr
    - rra : Reverse rotate a (bottom becomes top)
    - rrb : Reverse rotate b (bottom becomes top)
    - rrr : rra and rrb at the same time

# Instructions

# Description

# Why Linked list
## Array Problems
- pa/pb = memmove O(n), bad for stack ops repeated thousands times.
- ra/rra = shift all elements O(n).
- Good: random access for value lookup, median calc, no malloc/free churn per op.
- Bad fit here, push_swap ops are stack-native (top manipulation), array fights that.

# 4 Sorting Algorithm
- Simple
- Medium
- Complex
- Adaptive

# Resources
- [Visulization 1](https://vscza.itch.io/push-swap)
- [Visulization 2](https://www.youtube.com/watch?v=4dMsuxfqufg)
- [Tester](https://github.com/LeoFu9487/push_swap_tester)
- [Big O](https://medium.com/@princemeghani/big-o-notation-a-simple-explanation-with-examples-1ef0356825a7)
- [Stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Circula Double Linked list](https://www.geeksforgeeks.org/dsa/introduction-to-circular-doubly-linked-list/)

# Explaination
## Header & Struct

<!-- - Main linked list Struct -->
```c
    typedef struct s_ps_node
    {
        int					nb;     // collect number
        struct s_ps_node	*next;  // pointer to next struct
        struct s_ps_node	*prev;  // Circula Double linked list
    }	t_ps_node;
```

<!-- Detail and Position -->
```c
    typedef struct s_stack
    {
        t_ps_node	*top; // Collect first node
        int			size; // How many node in struct
    }	t_stack;
```
<!-- Because Circula Doesn't know what is the first node -->