# B. Monsters

**Time limit per test:** 2 seconds
**Memory limit per test:** 256 megabytes

Monocarp is playing yet another computer game. And yet again, his character is killing some monsters.

There are **n** monsters, numbered from `1` to `n`, and the `i`-th of them has `aᵢ` health points initially.

Monocarp's character has an ability that deals **k** damage to the monster with the highest current health. If there are several of them, the one with the smaller index is chosen.

If a monster's health becomes less than or equal to `0` after Monocarp uses his ability, then it dies.

Monocarp uses his ability until all monsters die.

Your task is to determine the **order in which monsters will die**.

## Input

The first line contains a single integer `t`:

* `1 ≤ t ≤ 10⁴` — the number of test cases.

The first line of each test case contains two integers `n` and `k`:

* `1 ≤ n ≤ 3 · 10⁵` — the number of monsters.
* `1 ≤ k ≤ 10⁹` — the damage which Monocarp's ability deals.

The second line contains `n` integers `a₁, a₂, ..., aₙ`:

* `1 ≤ aᵢ ≤ 10⁹` — the initial health points of the monsters.

The sum of `n` over all test cases doesn't exceed `3 · 10⁵`.

## Output

For each test case, print `n` integers — the indices of the monsters in the order they die.

## Example

### Input

```text
3
3 2
1 2 3
2 3
1 1
4 3
2 8 3 5
```

### Output

```text
2 1 3
1 2
3 1 2 4
```

## Note

In the first example, the health points change as follows:

```text
[1,2,3] → [1,2,1] → [1,0,1] → [-1,0,1] → [-1,0,-1]
```

The monster that is going to take damage the next time Monocarp uses his ability is underlined in the original statement.

In the second example:

```text
[1,1] → [-2,1] → [-2,-2]
```

In the third example:

```text
[2,8,3,5]
→ [2,5,3,5]
→ [2,2,3,5]
→ [2,2,3,2]
→ [2,2,0,2]
→ [-1,2,0,2]
→ [-1,-1,0,2]
→ [-1,-1,0,-1]
```

