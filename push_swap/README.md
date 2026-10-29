*This project has been created as part of the 42 curriculum by ponsumri, kpiwan*

# Description
Push_swap is the project that we sort numbers by using only 2 stacks (a and b) and a small set of operations (sa, pb, ra ...).
The program don't sort for real, it print the list of operations that will make stack a sorted.
- Less operations = better score
- We write 4 strategies
    - Simple   → O(n²)
    - Medium   → O(n√n)
    - Complex  → O(n log n)
    - Adaptive → look how messy the input is first, then pick one of the 3
- Wrong input → print "Error" on stderr

# Instructions
- Compile
    ```sh
    make        # build ./push_swap
    make clean  # remove .o files
    make fclean # remove .o files and ./push_swap
    make re     # fclean + make
    ```
- Run
    ```sh
    ./push_swap 3 1 2           # numbers as many args
    ./push_swap "3 1 2" 5       # or in one string, can mix
    ./push_swap 1 2 3           # already sorted → print nothing
    ./push_swap                 # no args → print nothing
    ```
- Flags (put before the numbers)
    - `--simple`   force simple
    - `--medium`   force medium
    - `--complex`  force complex
    - `--adaptive` choose by disorder (this is the default)
    - `--bench`    print stats on stderr (disorder, strategy, how many of each op)
    ```sh
    ./push_swap --complex --bench 5 4 3 2 1
    ```
- Error cases (all print `Error`)
    ```sh
    ./push_swap 1 1                     # duplicate
    ./push_swap 1 abc                   # not a number
    ./push_swap 2147483648              # bigger than int
    ./push_swap ""                      # empty arg
    ./push_swap --simple --complex 3 1 2 # 2 strategy flags
    ```

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

# Why Linked list
## Array Problems
- pa/pb = memmove O(n), bad for stack ops repeated thousands times.
- ra/rra = shift all elements O(n).
- Good: random access for value lookup, median calc, no malloc/free churn per op.
- Bad fit here, push_swap ops are stack-native (top manipulation), array fights that.
## Why Circular Doubly
- last node is just `top->prev`, no need to walk the list
- ra / rra = only move the head pointer (`top->next` / `top->prev`) → O(1)

# Header & Struct
```c
typedef struct s_ps_node
{
    int					nb;     // the number from input
    int					index;  // rank by value 0..n-1, -1 = not ranked yet
    struct s_ps_node	*next;  // next node (top → bottom)
    struct s_ps_node	*prev;  // prev node, top->prev is the bottom
}	t_ps_node;
```
- index (rank) = how many numbers are smaller than me
    - input `50 20 60` → rank `1 0 2`
    - all sorts use rank not nb, bc rank is always 0..n-1 (no negative, no gap)

# 4 Sorting Algorithm
## Helpers (used by many sorts)
- ft_sort_three (for handle case stack_size <= 3, at most 2 ops)
    Is it sorted ? then just return.
        Is it size == 2? then just switch.
            Then find max and then Put the biggest at the bottom.
                Then fix the top two by swap them.

- ft_find_min(ps->a)        → "which box is the smallest?" (just loop, cost 0 ops)
- ft_find_max(ps->b)        → "which box is the biggest?" (same, cost 0 ops)
- ft_get_pos(ps->a, box)    → "how far is it from the top?"
- ft_rotate_a_to(ps, 3)     → "turn a until position 3 is on top, the shorter way"
    - top half → ra, bottom half → rra
    - ft_rotate_b_to is the same but for b (rb / rrb)

- ft_sort_small (selection sort, only used by adaptive when n ≤ 5)
    - While stack a has more than 3 numbers and is not sorted:
        - find the smallest number in a
        - find its position (how far from the top)
        - rotate a until it is on top (ra if it is in the top half, rra if in the bottom half)
        - pb: push it to b
    - ft_sort_three: sort the 3 numbers left in a (at most 2 ops)
    - pa until b is empty: b only holds the smallest numbers, with the
    second smallest on top, so pushing them back keeps a sorted (bc we need stack b to be empty)
    - At most 12 operations for 5 numbers
    ```c
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

## Simple (Insertion Sort) O(n²)
- n <= 3 → ft_sort_three
- Idea: take the top of a and put it in the right place in b, one by one
    - b is always kept "biggest on top, going down" like a circle
- ft_insert_pos (where should this number go in b ?)
    - find the biggest number in b that is still smaller than me → I go on top of it
    - no one smaller ? (I am the new min) → go on top of the max (bc the circle wraps there)
- ft_sort_simple
    ```c
    while (ps->a)
    {
        if (ps->b)
            ft_rotate_b_to(ps, ft_insert_pos(ps->b, ps->a->nb));
        pb(ps);
    }
    ft_rotate_b_to(ps, ft_get_pos(ps->b, ft_find_max(ps->b)));  // max on top
    while (ps->b)
        pa(ps);                                                 // back to a sorted
    ```AI
- Why O(n²) ? every number can need up to n/2 rotations in b → n * n/2
- Why still good when almost sorted ? the slot is next to the top → almost 0 rotations

## Medium (Chunk Sort) O(n√n)
- n <= 3 → ft_sort_three

- ft_sqrt ()
    find the biggest r where r * r ≤ n (rounded down, bc we can't use sqrt() from math.h)
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

- ft_push_chunks (phase 1: send a → b, roughly sorted)
    range = ft_sqrt(n) * 3 / 2  (≈ 1.5·√n, 1.5 chosen by testing)
    i = how many numbers are already in b
    For the top of a, one at a time:
    ```c
    if (ps->a->index <= i)              // small / late: push, then rb
    {                                   //   sink it to b's bottom so it
        pb(ps);                         //   doesn't cover the big ones
        rb(ps);
        i++;
    }
    else if (ps->a->index <= i + range) // in range: push, stays on b's top
    {
        pb(ps);
        i++;
    }
    else                                // too big for now: ra, wait in a
        ra(ps);                         //   it will be pushed later
    ```
    Result: b has big numbers at the top and bottom, small in the middle.
    Cost to reach a position in b (phase 2 takes the shorter way):
        position:   0   1   2   3   4   5   6   7   8
        cost:       0   1   2   3   4   4   3   2   1
    → the big ones (pulled first) are where it's cheapest.

    Why a range and not exact order (500 numbers, measured):
        push only the exact next smallest  → 63986 ops (too many ra)
        push everything immediately        → 27274 ops (b too messy)
        push any of the next ~1.5√n        →  5048 ops ✔

- ft_sort_medium (phase 2: b → a)
    Find the max of b (free, no operations), rotate it to the top the
    shorter way (rb or rrb), pa. Repeat until b is empty.
    Biggest first, so a is built from the bottom up: 0 1 2 ... n-1.
    ```c
    while (ps->b)
    {
        ft_rotate_b_to(ps, ft_get_pos(ps->b, ft_find_max(ps->b)));
        pa(ps);
    }
    ```

## Complex (LSD binary radix sort) O(n log n)
- n <= 3 → ft_sort_three
- Idea: look at the rank in binary, sort by the last digit first, then the next one ...
    like sorting 170 45 75 90 by ones, then tens, then hundreds, but each digit is only 0 or 1

- ft_max_bits (int n)
    count how many binary digits the biggest rank (n - 1) has = how many passes we need
        n = 8   → biggest rank 7 = 111       → 3 bits → 3 passes
        n = 100 → biggest rank 99 = 1100011  → 7 bits → 7 passes

- ft_radix_pass (one pass for one bit)
    for every number in a (n times):
        `(index >> bit) & 1` = read digit number `bit` of the rank
            `>> bit` slide the digit we want to the last place
            `& 1`    keep only the last digit (0 or 1)
        digit is 1 → ra (stay in a)
        digit is 0 → pb (go to b)
    then pa everything back

    Why 0 → b ? the group that goes to b comes back on top with pa,
    and the 0s are the smaller ones so they must be on top
    (flip it and you get the stack sorted backwards, biggest on top)

- ft_sort_complex (main caller)
    one pass per bit: 0, 1, 2 ... stop when bit == bits or a is already sorted
    ```c
    while (bit < bits && !ft_is_sorted(ps->a))
        ft_radix_pass(ps, n, bit++);    // bit++ send 0 first, then 1, 2 ...
    ```

- Trace `40 20 10 30` (rank `3 1 0 2` = `11 01 00 10`, 2 bits)
    ```
    pass bit 0:  40 ra, 20 ra, 10 pb, 30 pb, pa pa  → a: 10 30 40 20
    pass bit 1:  10 pb, 30 ra, 40 ra, 20 pb, pa pa  → a: 10 20 30 40 ✔
    12 ops
    ```

- Why it works ? every pass keep the order from the pass before (pb then pa flip twice = same order)
    so the last pass split small half / big half, and inside each half it's already sorted
- Why base 2 and not base 3 ? we have only 2 stacks → 2 groups are cheap
    3rd group must go to the bottom of b (pb + rb, then rrb + pa back) = more ops
    measured: base 2 → 1084 / 6784, base 3 → 1341 / 7371 (100 / 500 numbers)

## Adaptive (Measure Disorder)
- prediction by using disorder to look how messy input was
- disorder = how many pairs are in the wrong order ÷ all pairs
    - 0 = already sorted, 1 = fully reversed
    - measured only once before sorting, cost 0 ops
- choose
    ```
    n <= 5              → ft_sort_small
    disorder <  0.2     → simple   (almost sorted, insertion is cheap)
    disorder <  0.5     → medium
    disorder >= 0.5     → complex
    ```
- example
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

### Results (random input, measured)
|            | 100 numbers | 500 numbers |
|------------|-------------|-------------|
| medium     | ~577        | ~5034       |
| complex    | 1084        | 6784        |
| adaptive   | ≤ 1084      | ≤ 6784      |
| pass       | < 2000      | < 12000     |
| excellent  | < 700       | < 5500      |

# How To Test
- check if sorted correct (checker from the intra)
    ```sh
    ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG    # → OK
    ```
- count ops
    ```sh
    ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l
    ```
- see bench only (hide the ops)
    ```sh
    ./push_swap --bench $ARG 2> bench.txt > /dev/null; cat bench.txt
    ```

# Resources
- [Visualization 1](https://vscza.itch.io/push-swap)
- [Visualization 2](https://www.youtube.com/watch?v=4dMsuxfqufg)
- [Tester](https://github.com/LeoFu9487/push_swap_tester)
- [Tester](https://github.com/nirmal-gope/push_swap_tester)
- [Big O](https://medium.com/@princemeghani/big-o-notation-a-simple-explanation-with-examples-1ef0356825a7)
- [Stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Circular Doubly linked list](https://www.geeksforgeeks.org/dsa/introduction-to-circular-doubly-linked-list/)
- [Radix Sort](https://www.youtube.com/watch?v=nu4gDuFabIM)

## AI usage
- We used AI (Claude) to explain the algorithms and trace them step by step, so we can understand why they work and defend them
- Also used it to help write some parts of this README
