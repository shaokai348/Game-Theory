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

## Creator's Note
This was written as an independent project after reading Mihalák & Schlegel,
"The Price of Anarchy in Network Creation Games Is (Mostly) Constant."
I received guidance on the algorithm design (From my best buddy claude), then wrote the code myself
and verified the n = 3 cases by hand, was fun.