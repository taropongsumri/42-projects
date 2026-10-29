*This project has been created as part of the 42 curriculum by ponsumri*

# Move Function
## Operations name
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
## Operations Visualizations


# Instructions

# Description

# Why Linked list
## Array Problems
- pa/pb = memmove O(n), bad for stack ops repeated thousands times.
- ra/rra = shift all elements O(n).
- Good: random access for value lookup, median calc, no malloc/free churn per op.
- Bad fit here, push_swap ops are stack-native (top manipulation), array fights that.

# 4 Sorting Algorithm
- Simple (Insertion Sort)
    - ft_sort_three (for handle case stack_size <= 3)
        Is it sorted ? then just return.
            Is it size == 2? then just switch.
                Then find max and then Put the biggest at the bottom.
                    Then fix the top two by swap them.

    - ft_find_min(ps->a)        → "which box is the smallest?" 
    - ft_get_pos(ps->a, box)    → "how far is it from the top?"
    - ft_rotate_a_to(ps, 3)     → "turn a until position 3 is on top, the shorter way" , this function also do ra and we use to make the min postion to the first number in stack then push to b

    - ft_sort_small (selection sort, used by adaptive when n ≤ 5)
        - While stack a has more than 3 numbers and is not sorted:
            - find the smallest number in a
            - find its position (how far from the top)
            - rotate a until it is on top (ra if it is in the top half, rra if in the bottom half)
            - pb: push it to b
        - ft_sort_three: sort the 3 numbers left in a (at most 2 ops)
        - pa until b is empty: b only holds the smallest numbers, with the
        second smallest on top, so pushing them back keeps a sorted (bc we need stack b to be empty)
        - At most 12 operations for 5 numbers


    - readable version
    ```
    c
    void	ft_sort_small(t_ps *ps)
    {
        t_ps_node	*min;
        int			pos;

        while (ft_stack_size(ps->a) > 3 && !ft_is_sorted(ps->a))
        {
            min = ft_find_min(ps->a);
            pos = ft_get_pos(ps->a, min);
            ft_rotate_a_to(ps, pos);
            pb(ps);
        }
        ft_sort_three(ps);
        while (ps->b)
            pa(ps);
    }
    ```


- Medium (Chunk Sort) 
    - ft_sort_three (for handle case stack_size <= 3)
        Is it sorted ? then just return.
            Is it size == 2? then just switch.
                Then find max and then Put the biggest at the bottom.
                    Then fix the top two by swap them.
    
    - ft_sqrt ()
        try to find the close sqrt by r+1 * r+1 until close to n 
    ``` in case not fit
        r = 0:  1  ≤ 74?  yes → r = 1
        r = 1:  4  ≤ 74?  yes → r = 2
        r = 2:  9  ≤ 74?  yes → r = 3
        r = 3:  16 ≤ 74?  yes → r = 4
        r = 4:  25 ≤ 74?  yes → r = 5
        r = 5:  36 ≤ 74?  yes → r = 6
        r = 6:  49 ≤ 74?  yes → r = 7
        r = 7:  64 ≤ 74?  yes → r = 8
        r = 8:  81 ≤ 74?  NO  → stop
        return 8
    ```

    - ft_push_chunks (roughly sorted)


    - ft_sort_medium (real)
        - we also use same algorithm here to sort 
        ```c
            while (ps->b)
                {
                    ft_rotate_b_to(ps, ft_get_pos(ps->b, ft_find_max(ps->b)));
                    pa(ps);
                }
        ```


    
- Complex (LSD binary radix sort)
    - ft_sort_three (for handle case stack_size <= 3)
        Is it sorted ? then just return.
            Is it size == 2? then just switch.
                Then find max and then Put the biggest at the bottom.
                    Then fix the top two by swap them.


- Adaptive (Measure Disorder)
    - prediction by using disorder to look how messy input was
        input:  ./push_swap 50 20 60 10 40 30
                ↓
        look:   how messy?  → disorder = 0.60
                ↓
        choose: 0.60 ≥ 0.5 → messy → radix
                ↓
        sort:   run radix only, print the operations

        ./push_swap --bench 50 20 60 10 40 30

        [bench] disorder: 60.00%                ← known BEFORE sorting (measured)
        [bench] strategy: Adaptive / O(n log n) ← decided BEFORE sorting (from disorder)
        [bench] total_ops: 29                   ← known only AFTER sorting (counted while running)

# Resources
- [Visulization 1](https://vscza.itch.io/push-swap)
- [Visulization 2](https://www.youtube.com/watch?v=4dMsuxfqufg)
- [Tester](https://github.com/LeoFu9487/push_swap_tester)
- [Tester](https://github.com/nirmal-gope/push_swap_tester)
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
        int					index;  // rank by value 0..n-1, -1 = not ranked yet
        struct s_ps_node	*next;  // pointer to next struct
        struct s_ps_node	*prev;  // Circula Double linked list
    }	t_ps_node;
```

<!-- Detail and Position -->
<!-- REMOVED from the header - was never used anywhere. -->
```c
    typedef struct s_stack
    {
        t_ps_node	*top; // Collect first node
        int			size; // How many node in struct
    }	t_stack;
```

# How To Test
## To Check Paraser

<!-- old version, when ft_clear_args only validated and printed argv -->

    /// before ft_clear_args(argc, argv);
	// i = 0;
	// while (++i < argc)
	// {
	// 	j = 0;
	// 	while (argv[i][j] != '\0')
	// 		ft_printf("%c", argv[i][j++]);
	// }

## To Check the Stack
<!-- ft_parse_args now returns the built stack, so walk the ring -->
<!-- instead of re-reading argv. Walk forward n steps, then back -->
<!-- via prev: on "3 1 2" forward is 3 1 2 and backward is 2 1 3. -->
<!-- The backward pass is the cheap proof prev is really maintained. -->

	// t_ps_node *c = stack_a;
	// int i = 0;
	// while (i++ < size)
	// {
	// 	ft_printf("%d ", c->nb);
	// 	c = c->next;
	// }

# To Check Operations (Claude fill & delete this)
