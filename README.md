There is a paper expressed in a matrix of N×N size. Each column of paper has one of three values, -1, 0, and 1. We're going to cut this matrix to the right size, when we're going to cut it according to the following rules.

If the paper is all in the same number, use it as it is.
If not (1), cut the paper into nine pieces of paper of the same size and repeat the process (1) for each cut.
When cutting paper like this, write a program to find the number of paper filled with only -1, the number of paper filled with only 0 and the number of paper filled with only 1.

Input
The first line is given  N (1 <= N <= 3^7, N = 3^k). The following N lines are given a matrix of N integers.

Output
Outputs the number of paper filled with only -1 on the first line, the number of paper filled with only 0 on the second line, and the number of paper filled with only 1 on the third line.
