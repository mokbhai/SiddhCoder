import java.util.*;

public class stackQuestions {
    public static void main(String[] args) {  
        Scanner scanner = new Scanner(System.in);
        
        Stack<Integer> stack = new Stack<>();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        System.out.println("Original Stack: " + stack);
        // pushToBottom(stack, 0);
        reverseAStack(stack);
        System.out.println("Modified Stack: " + stack);

        // reverseString("mokshit");

        scanner.close();
    }
 
    // MOST LOGICAL // MUST KNOW // push to bottom of stack without using extra space
    static void pushToBottom(Stack<Integer> stack, int item) {
        if (stack.isEmpty()) {
            stack.push(item);
        } else {
            int temp = stack.pop();
            pushToBottom(stack, item);
            stack.push(temp);
        }
    }

    static void reverseString(String s) {
        Stack<Character> chr = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            chr.push(s.charAt(i));
        }
        while (!chr.isEmpty()) {
            System.out.print(chr.pop());
        }
    }
        
        // MOST LOGICAL 2 // MUST KNOW // Reverse a stack without using extra space
    static void reverseAStack(Stack<Integer> stack) {
        if (stack.isEmpty()) {
            return;
        } else {
            int temp = stack.pop();
            reverseAStack(stack);
            pushToBottom(stack, temp);
        }
    }

}
