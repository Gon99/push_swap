# Push Swap

42 Algorithm Project - Sort problem

Given a set of integers, sort it using a predefined set of instructions using
two stacks. The instruction set is defined below. This program outputs a program
in push_swap instructions that sorts the input integers.

## Instruction set
For the following instructions, if the instruction is not possible, the part of
it that can't be executed won't.

Code	| Instruction			| Action
--------|-----------------------|----------------------------------------------
`sa`	| swap a				| swaps the 2 top elements of stack a
`sb`	| swap b				| swaps the 2 top elements of stack b
`ss`	| swap a + swap b		| both `sa` and `sb`
`pa`	| push a				| moves the top element of stack b at the top of stack a
`pb`	| push b				| moves the top element of stack a at the top of stack b
`ra`	| rotate a				| shifts all elements of stack a from bottom to top
`rb`	| rotate b				| shifts all elements of stack b from bottom to top
`rr`	| rotate a + rotate b	| both `ra` and `rb`
`rra`	| reverse rotate a		| shifts all elements of stack a from top to bottom
`rrb`	| reverse rotate b		| shifts all elements of stack b from top to bottom
`rrr`	| reverse rotate a + reverse rotate b	| both `rra` and `rrb`

## Approach
I had three differents algorithms: one for 3 numbers or less, one for 100 numbers or less, and one for 500 numbers or less.

For 100 < numbers, I find the median and push everything below the median into stack b. Then I identify each the largest and smallest integer in stack b, and determine which is most efficient to rotate up/down and push back to stack a (along with the specific moves to make that happen). Then I execute those moves.

For 500 < numbers, I implemented the radix sort algorithm, here is a guide you can follow that is so useful to understand the algorithm https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e

## Usage

Run ```make```.

The ***push_swap*** program is used as follows:

```c
   ./push_swap 5 2 3 1 4
```
## Visualizer

Here you can see how my 100 sort algorithm works:

![push_swap visualizer](https://github.com/Gon99/push_swap/blob/master/100-short.gif)


