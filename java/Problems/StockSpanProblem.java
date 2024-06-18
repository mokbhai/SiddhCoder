import java.util.Stack;

public class StockSpanProblem {
    public static void main(String[] args) {
        Solution s = new Solution();

        int price[] = { 10, 4, 5, 90, 120, 80 };

        s.calculateSpan(price, price.length);
        
        int price2[] = { 100, 80, 60, 70, 60, 75, 85, 100 };

        s.calculateSpan(price2, price2.length);
    }
    
}

class Solution {
    // Function to calculate the span of stock's price for all n days.
    public void calculateSpan(int price[], int n) {
        int[] span = new int[n];
        Stack<Integer> s = new Stack<>(); // Initialize the stack

        for (int i = 0; i < n; i++) {
            // Ensure the stack is not empty and the price at the stack's top index is less than the current price
            while (!s.empty() && price[s.peek()] <= price[i]) {
                s.pop();
            }

            // If stack is empty, it means price[i] is greater than all previous prices
            if (s.empty()) {
                span[i] = i + 1;
            } else {
                // Otherwise, calculate the span as the difference between current index and index at stack's top
                span[i] = i - s.peek();
            }

            // Push current index onto the stack
            s.push(i);
        }
        for (Integer i : span) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
}

