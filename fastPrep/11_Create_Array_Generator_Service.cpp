#include<bits/stdc++.h>

using namespace std;


int main(){


    return 0;
}







/*




Create Array Generator Service
Learn this problem
● Medium
Amazon logo
Amazon
NEW GRAD
FULLTIME
OA
See Amazon hiring insights
Problem statement
Your project team needs to work closely with a group of software testers. They have requested that your team create an array generator service to assist with testing software functionality. Create an array generator service.

Its input parameters are:

values[n] contains n positive integers.
state is a string that contains n characters.
Each character is either '0' or '1'.
If state[i] = '1', values[i] is available.
If state[i] = '0', values[i] is blocked.
To create an integer array, S, the following operation is performed exactly m times. S is initially empty.

Choose any values[i] that is available, that is, where state[i] = '1'. The same element can be chosen any number of times.
Append the value in values[i] to S.
For all state[i] = '0' such that i > 0 and state[i-1] = '1' before this unlock step, change state[i] to '1'. For example, if state = '0100101' before the operation, it equals '0110111' after the operation.
Find the lexicographically largest sequence S that can be obtained after m operations.

Note: A sequence x of length m is lexicographically larger than sequence y of length m if there exists an index i (0 ≤ i < m) such that x[i] > y[i], and for every j (0 ≤ j < i), x[j] = y[j].

Function
getOptimalSequence(values: int[], state: String, m: int) → int[]
Examples
Example 1
values = [10,5,7,6]
state = "0101"
m = 2
return = [6,7]
Start
0101
Blocked
Blocked
10
5
7
6
Available
Available
Available: 5, 6. Pick 6.
choose 6
After op 1
0111
Blocked
10
5
7
6
Available
Available: 5, 7, 6. Pick 7.
choose 7
Result
0111
Blocked
10
5
7
6
Available
S = [6, 7].
state = "0101", so indices 1 and 3 are available. Among values[1] = 5 and values[3] = 6, choose 6 and append it to S.
The unlock step changes state from "0101" to "0111", making index 2 available.
The highest available value is now values[2] = 7. After exactly m = 2 operations, return [6, 7].
Thank you to a kind friend for helping correct the mistakes in this example! 🌷（06-23-2026 :D

Example 2
values = [4,9,1,2,10]
state = "10010"
m = 4
return = [4,10,10,10]
Start
10010
Blocked
Blocked
4
9
1
2
10
Available
Available
Available: 4, 2. Pick 4.
choose 4
After op 1
11011
Blocked
4
9
1
2
10
Available
Available
Available: 4, 9, 2, 10. Pick 10.
choose 10
After op 2
11111
4
9
1
2
10
Available
Available: 4, 9, 1, 2, 10. Pick 10.
continue
Result
11111
4
9
1
2
10
Available
S = [4, 10, 10, 10].
state = "10010", so indices 0 and 3 are available. The available values are 4 and 2, so choose 4.
The unlock step uses the state before unlocking, so indices 1 and 4 become available and state becomes "11011". Now the largest available value is 10.
The next unlock step makes index 2 available, but 10 remains the largest available value. Choose 10 for the remaining operations and return [4, 10, 10, 10].
Thank you to a kind friend for helping correct the mistakes in this example! 🌷（06-23-2026 :D

Example 3
values = [5,3,4,6]
state = "1100"
m = 5
return = [5,5,6,6,6]
Start
1100
Blocked
5
3
4
6
Available
Available: 5, 3. Pick 5.
choose 5
After op 1
1110
Blocked
5
3
4
6
Available
Available: 5, 3, 4. Pick 5.
choose 5
After op 2
1111
5
3
4
6
Available
Available: 5, 3, 4, 6. Pick 6.
continue
Result
1111
5
3
4
6
Available
S = [5, 5, 6, 6, 6].
state = "1100", so indices 0 and 1 are initially available. The largest available value is values[0] = 5.
After the first unlock step, index 2 becomes available and state becomes "1110". The largest available value is still 5, so choose it again.
After the second unlock step, index 3 becomes available and state becomes "1111". The largest available value is 6, so choose 6 for the remaining three operations.
Constraints
values has length n and contains positive integers.
state has length n and contains only '0' and '1'.
The operation is performed exactly m times.

Problem Source



*/