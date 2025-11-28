int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int start = 0;
    int total = 0;     // 总剩余油量（判断是否有解）
    int tank = 0;      // 当前从 start 出发的油量

    for (int i = 0; i < gasSize; i++) {
        int diff = gas[i] - cost[i];
        total += diff;
        tank += diff;

        // 不能从 start 到 i
        if (tank < 0) {
            // 起点必须往后移
            start = i + 1;
            tank = 0;   // 重新开始模拟
        }
    }

    return total < 0 ? -1 : start;
}//太挫败了，写了一个半小时，最后不如ai写的转用ai了，哎
