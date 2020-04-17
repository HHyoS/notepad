Image : https://www.acmicpc.net/problem/2630

As shown in Figure 1 below, a square of paper consisting of several squares is given, each of which is painted white or blue. To cut a given paper according to a certain rule to make a square-shaped white or blue colored paper of various sizes.

If the total size of the paper is N×N (N=2k, k is a natural number of not less than 1 but not more than 7), the rules for cutting paper are as follows.

If the whole paper is not painted in the same color, cut the middle part horizontally and vertically and divide it into four N/2 × N/2 colored papers of the same size, as shown in Figure 2, I, II, III, and IV. For each of the divided papers I, II, III and IV, if they are not all painted the same color as before, divide them into four colored papers of the same size in the same way. Repeat this process until all the cut-off paper is painted white or all blue, or a single square box and can no longer be cut.

When cut according to the above rules, 3Figure 3> shows the status after the first division of the paper in <Figure 1 1, <Figure 4 4 shows the status after the second division, and <Figure 5> shows the nine white colored papers and seven blue colored papers of various sizes finally made.

Write a program that asks the number of white and blue colored papers cut when the length of one side of a given piece of paper as input is N and the color (white or blue) of each square box is given.

Input The first line is given the length of one side of the whole paper, N. N is one of 2, 4, 8, 16, 32, 64, and 128. The colors of squares on each horizontal line of colored paper are given from the top to the second to the last line. The white-painted compartments are given as 0, and the blue-painted compartments are given as 1, with one blank between each number.

Output The first line prints the number of cut white colored papers, and the second line prints the number of blue colored papers.
