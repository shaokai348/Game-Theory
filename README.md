# game-theory-appeal-
# Network Creation Game: Brute-Force Equilibrium Search

A small C++ program that finds every Nash equilibrium of the SumGame
(Fabrikant et al., 2003) for networks of 3–5 players.

## The game
Each player chooses which edges to buy, at a cost of α each.
A player's cost = α × (edges bought) + sum of distances to all other players.

## What the program does
For each n = 3, 4, 5 and α = 0.5, 1.0, …, 10:
1. Checks every strategy profile (who buys which edges)
2. Checks whether each is a Nash equilibrium by testing every possible deviation
3. Reports the number of equilibria, whether any contain a cycle, the social
   optimum, the worst equilibrium, and the Price of Anarchy

## Key findings
- Equilibria with cycles disappear once α exceeds roughly n − 1
- The worst Price of Anarchy found was 1.2 (n = 5, α = 1)
- The 5-cycle at α = 4 is stable only by an exact tie: dropping an edge
  saves 4 and costs exactly 4 in extra distance

## Limitations
The search grows as 2^(n(n−1)), so it is only feasible for n ≤ 5.
These results are small-n evidence, not a proof. Ties count as equilibria,
and α is tested in steps of 0.5, so thresholds are approximate.

## Running it
g++ -std=c++17 -O2 Gametheory.cpp -o ncg && ./ncg   (runs in about 2 seconds)

## Results

Columns: **α** = edge price, **#NE** = number of equilibrium strategy profiles (labelled, so isomorphic graphs are counted separately), **Non-tree NE** = whether any equilibrium contains a cycle, **Optimum** = social optimum cost, **Worst NE** = highest social cost among equilibria, **PoA** = Worst NE / Optimum.


### n = 3

| α | #NE | Non-tree NE | Optimum | Worst NE | PoA |
|---:|---:|:---:|---:|---:|---:|
| 0.5 | 8 | yes | 7.5 | 7.5 | 1.0000 |
| 1.0 | 20 | yes | 9.0 | 10.0 | 1.1111 |
| 1.5 | 12 | no | 10.5 | 11.0 | 1.0476 |
| 2.0 | 12 | no | 12.0 | 12.0 | 1.0000 |
| 2.5 | 12 | no | 13.0 | 13.0 | 1.0000 |
| 3.0 | 12 | no | 14.0 | 14.0 | 1.0000 |
| 3.5 | 12 | no | 15.0 | 15.0 | 1.0000 |
| 4.0 | 12 | no | 16.0 | 16.0 | 1.0000 |
| 4.5 | 12 | no | 17.0 | 17.0 | 1.0000 |
| 5.0 | 12 | no | 18.0 | 18.0 | 1.0000 |
| 5.5 | 12 | no | 19.0 | 19.0 | 1.0000 |
| 6.0 | 12 | no | 20.0 | 20.0 | 1.0000 |
| 6.5 | 12 | no | 21.0 | 21.0 | 1.0000 |
| 7.0 | 12 | no | 22.0 | 22.0 | 1.0000 |
| 7.5 | 12 | no | 23.0 | 23.0 | 1.0000 |
| 8.0 | 12 | no | 24.0 | 24.0 | 1.0000 |
| 8.5 | 12 | no | 25.0 | 25.0 | 1.0000 |
| 9.0 | 12 | no | 26.0 | 26.0 | 1.0000 |
| 9.5 | 12 | no | 27.0 | 27.0 | 1.0000 |
| 10.0 | 12 | no | 28.0 | 28.0 | 1.0000 |

### n = 4

| α | #NE | Non-tree NE | Optimum | Worst NE | PoA |
|---:|---:|:---:|---:|---:|---:|
| 0.5 | 64 | yes | 15.0 | 15.0 | 1.0000 |
| 1.0 | 528 | yes | 18.0 | 21.0 | 1.1667 |
| 1.5 | 38 | yes | 21.0 | 22.5 | 1.0714 |
| 2.0 | 62 | yes | 24.0 | 26.0 | 1.0833 |
| 2.5 | 56 | no | 25.5 | 27.5 | 1.0784 |
| 3.0 | 56 | no | 27.0 | 29.0 | 1.0741 |
| 3.5 | 56 | no | 28.5 | 30.5 | 1.0702 |
| 4.0 | 56 | no | 30.0 | 32.0 | 1.0667 |
| 4.5 | 56 | no | 31.5 | 33.5 | 1.0635 |
| 5.0 | 56 | no | 33.0 | 35.0 | 1.0606 |
| 5.5 | 56 | no | 34.5 | 36.5 | 1.0580 |
| 6.0 | 56 | no | 36.0 | 38.0 | 1.0556 |
| 6.5 | 56 | no | 37.5 | 39.5 | 1.0533 |
| 7.0 | 56 | no | 39.0 | 41.0 | 1.0513 |
| 7.5 | 56 | no | 40.5 | 42.5 | 1.0494 |
| 8.0 | 56 | no | 42.0 | 44.0 | 1.0476 |
| 8.5 | 56 | no | 43.5 | 45.5 | 1.0460 |
| 9.0 | 56 | no | 45.0 | 47.0 | 1.0444 |
| 9.5 | 56 | no | 46.5 | 48.5 | 1.0430 |
| 10.0 | 56 | no | 48.0 | 50.0 | 1.0417 |

### n = 5

| α | #NE | Non-tree NE | Optimum | Worst NE | PoA |
|---:|---:|:---:|---:|---:|---:|
| 0.5 | 1024 | yes | 25.0 | 25.0 | 1.0000 |
| 1.0 | 43728 | yes | 30.0 | 36.0 | 1.2000 |
| 1.5 | 624 | yes | 35.0 | 38.0 | 1.0857 |
| 2.0 | 1104 | yes | 40.0 | 42.0 | 1.0500 |
| 2.5 | 104 | yes | 42.0 | 42.5 | 1.0119 |
| 3.0 | 584 | yes | 44.0 | 48.0 | 1.0909 |
| 3.5 | 584 | yes | 46.0 | 50.0 | 1.0870 |
| 4.0 | 644 | yes | 48.0 | 56.0 | 1.1667 |
| 4.5 | 620 | no | 50.0 | 58.0 | 1.1600 |
| 5.0 | 620 | no | 52.0 | 60.0 | 1.1538 |
| 5.5 | 620 | no | 54.0 | 62.0 | 1.1481 |
| 6.0 | 620 | no | 56.0 | 64.0 | 1.1429 |
| 6.5 | 620 | no | 58.0 | 66.0 | 1.1379 |
| 7.0 | 620 | no | 60.0 | 68.0 | 1.1333 |
| 7.5 | 620 | no | 62.0 | 70.0 | 1.1290 |
| 8.0 | 620 | no | 64.0 | 72.0 | 1.1250 |
| 8.5 | 620 | no | 66.0 | 74.0 | 1.1212 |
| 9.0 | 620 | no | 68.0 | 76.0 | 1.1176 |
| 9.5 | 620 | no | 70.0 | 78.0 | 1.1143 |
| 10.0 | 620 | no | 72.0 | 80.0 | 1.1111 |

## Creator's Note
This was written as an independent project after reading Mihalák & Schlegel,
"The Price of Anarchy in Network Creation Games Is (Mostly) Constant."
I received guidance on the algorithm design (From my best buddy claude), then wrote the code myself
and verified the n = 3 cases by hand, was fun.