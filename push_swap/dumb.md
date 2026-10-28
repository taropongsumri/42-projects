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