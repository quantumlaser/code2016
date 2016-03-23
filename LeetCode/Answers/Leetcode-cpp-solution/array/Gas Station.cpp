/*
 There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique. 
*/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size(), start = 0, pos = 0;  // double pointer
        int sum = gas[pos] - cost[pos];
        while((pos+1)%n != start) {
            if(sum >= 0) sum += gas[++pos] - cost[pos];  //keep trying
            else {
                start = (start+n-1) % n;         // start pointer must step back 
                sum += gas[start] - cost[start];
            }
        }
        return sum>=0 ? start : -1;
    }
};