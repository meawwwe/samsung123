// A bishop is a piece used in the game of chess which can only
// move diagonally from its current position. Two bishops attack
// each other if one is on the path of the other. In the figure
// below, the dark squares represent the reachable locations for
// bishop B1 from its current position. Bishops B1 and B2 are
// in attacking position, while B1 and B3 are not. Bishops B2
// and B3 are also in non-attacking position.
// Given two numbers n and k, determine the number of
// ways one can put k bishops on an n × n chessboard so that
// no two of them are in attacking positions.

// Input
// The input file may contain multiple test cases. Each test
// case occupies a single line in the input file and contains two
// integers n (1 ≤ n ≤ 8) and k (0 ≤ k ≤ n^2 ). A test case containing two zeros terminates the input.

// Output
// For each test case, print a line containing the total number of ways one can put the given number of
// bishops on a chessboard of the given size so that no two of them lie in attacking positions. You may
// safely assume that this number will be less than 10^15.

// Sample Input
// 8 6
// 4 4
// 0 0

// Sample Output
// 5599888
// 260