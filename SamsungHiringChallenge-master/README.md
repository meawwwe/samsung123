# SamsungHiringChallenge
Two problems of coding were given - Tortoise and Hare Earthquake problem. Happened on Techgig platform 2019 

Challenge - 2

Africa has been hit by an earthquake. There are total N cities in Africa out of which K have been affected by this earthquake. The cities are numbered from 1 to N.
United Nations has decided to establish a relief base in one of these (N - K) non-affected cities. Although the UN has lot of relief packets, but it has a single carrier truck to distribute these packets. The truck starts at the base in the morning and goes to all the K cities one by one. It finally returns to the base again in the evening after distributing relief packets to all the K cities.
Note that the truck may have to visit some non-affected cities also while going from one affected city to some other affected city. There are M bi-directional roads between the cities.
It is guaranteed that all the cities are reachable via some combination of roads. You can also assume that the truck has infinite petrol and it needs not to refill during its trip.
Please help UN to find the best city to establish the relief base so that it minimizes the total distance traveled by the truck in a day.
Input Format
Line 1 : Three space separated integers N, M, and K - number of cities, number of roads, and number of affected cities respectively.
Next K lines contains an integer in each line in the range 1...N identifying an affected city.
Next M lines: Each line contains three space separated integers u, v(1 <= u, v <= N), and l (1 <= l <= 1000) indicating the presence of a road between cities u and v.
Constraints
1 <= N <= 10000
1 <= M <= 50000
1 <= K < N
1 <= u, v <= N
1 <= l <= 1000

Output Format
The minimum distance the truck needs to travel in a day if the base is set in an optimal location.
Sample TestCase 1
Input
6 9 3
3
4
5
1 2 7
1 6 6
2 3 1
2 6 5
3 4 1
3 5 3
4 5 1
4 6 4
5 6 10
Output
6
Explanation
The optimal location to build base is city 2. The truck then goes like this : 2->3->4->5->4->3->2. Total distance is 1 + 1 + 1 + 1 + 1 + 1 = 6.

Sample TestCase 2
Input
3 3 1
3
1 2 1
1 3 3
2 3 2
Output
4

