class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        List<int[]> ans = new ArrayList<>();
        int[] temp = intervals[0]; // Initialize temp with the first interval
        int n = intervals.length;

        for (int i = 1; i < n; i++) {
            // If the current interval overlaps with the temp, merge them
            if (intervals[i][0] <= temp[1]) {
                temp[1] = Math.max(temp[1], intervals[i][1]);
            } else {
                // Add the merged interval to the answer and update temp
                ans.add(temp);
                temp = intervals[i];
            }
        }
        // Add the last interval
        ans.add(temp);

        // Convert the list to a 2D array
        return ans.toArray(new int[ans.size()][]);
    }
}