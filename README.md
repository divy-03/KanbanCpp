# Simulation of card movement on a 2D grid

### Description

Consider an application that organizes information by arranging cards with notes on them into lists on a 2D grid. These notes can be moved across multiple lists.

Examples include billboard-based task management applications such as Trello or Jira. 

The first argument cards is given a value indicating the initial position of all cards in the board, each as a 2D array, with  the following rules. 
`[CardID, RowIndex, ColumnIndex]`

Here, the row and column indices are assumed to be zero-indexed, respectively.

The second argument, moves, is a 2D array of values indicating the movement of the cards, each with the following rules
`[CardID, Row index before move, Column index before move, Destination row index, Destination column index]`

The third argument, query, is passed an int type card ID for tracking the moves. 

Based on the given cards and moves, implement a function that returns the final position of the card specified in the third argument, query, as `[row index, column index]`.

The following rules are assumed to exist for moving cards at this time.
   - If a card is moved to the same row or column index as an existing card, the card's original position is shifted down. 
   - Also, when a card is moved, all cards in the row from which it was moved and in the column below it are moved up one by one. 
   - Cards may be moved to the same row and column.
   - There shall be no gaps in the initial placement.
   - We can assume that the pre-move coordinates given when specifying a move are correct.

### Examples

#### Exmaple 1

Input

```
7
1 1 0
3 0 0
6 0 1
4 0 2
5 2 0
7 1 1
2 1 2
1
6 0 1 2 0
5
```

Output

```
2 0
```

> This is a case where the target moves. In this case, the card with card ID 6 moves to `[2, 0]`, so `[2, 0]`is the correct value.

#### Example 2

Input

```
7
1 1 0
3 0 0
6 0 1
4 0 2
5 2 0
7 1 1
2 1 2
2
6 0 1 2 0
7 0 1 0 2
2
```

Output

```
2 2
```

> This is a case where a card existing in the same row as the target moves. In this case, the target does  not move but the row moves.
