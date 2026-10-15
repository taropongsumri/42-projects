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
- Simple
- Medium
- Complex
- Adaptive

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


# Steps
1. ~~**Stack helpers**~~ **DONE** — `utils/ft_stack_utils.c`: `ft_stack_size`, `ft_is_sorted`, `ft_find_min`, `ft_find_max`, `ft_get_pos`.
   Read-only: they never mutate a stack and never print an operation. That is why they live in `utils/` and not `func/` — everything in `func/` emits output.
   Named `ft_get_pos`, **not** `ft_get_index`: position-from-top and the `index` field are two different numbers, and naming them alike invites bugs.
   <!-- trap: ft_is_sorted compares n-1 pairs, never the wrap edge.      -->
   <!-- In a sorted ring bottom->top always runs high->low (2147483647   -->
   <!-- -> 42), so testing every edge calls every sorted stack unsorted  -->
   <!-- and silently kills the early exit.                              -->
2. ~~**Early exit**~~ **DONE** — `src/push_swap.c`: `if (ft_is_sorted(stack_a))` frees and returns 0 before any sort runs.
   <!-- must free in that branch or already-sorted input leaks the stack -->
   <!-- Not visible in stdout while there is no sort (both print         -->
   <!-- nothing). Proved with: gdb -batch -ex 'break ft_index_stack'     -->
   <!-- -ex 'run 1 2 3' -> never hit. With 3 1 2 -> hit.                 -->
3. ~~**Index normalization**~~ **DONE** — `utils/ft_index.c`: `ft_index_stack` sets `index` to the rank of each value.
   Rank = how many nodes hold something smaller, so no allocation and no second list to keep in sync. O(n^2) but costs zero push_swap operations.
4. **Small sorts** — `sort_2` (one `sa`), `sort_3` (5 hardcoded cases), `sort_5` (push 2 smallest to b, `sort_3`, `pa` twice).
5. **Big sort** — pick one: chunk/bucket (easier to reason about) or Turk/cost-based (fewer ops). Needs steps 1 and 3 first.
6. **Move optimization** — merge simultaneous rotations into `rr` / `rrr` when both stacks turn the same way.
7. **Op-count targets** — 3 → ≤ 3 · 5 → ≤ 12 · 100 → < 700 · 500 → < 5500.
8. **Test** — `checker_linux` for correctness, then the tester scripts in Resources for op counts at 100 and 500.
9. **Housekeeping** — rename `utils/ft_clear_args.c` → `ft_parse_args.c` (the file name no longer matches the function it holds).
10. **Bonus (optional)** — the `checker` program: reads operations on stdin, applies them, prints `OK`/`KO`. Needs `get_next_line` (you already have it as a sibling project) and a separate `bonus` rule in the Makefile.
