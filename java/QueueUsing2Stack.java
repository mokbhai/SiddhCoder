import java.util.Stack;

public class QueueUsing2Stack {

    public static void enqueue(Stack<Integer> stack1, Stack<Integer> stack2, int data) {
        stack1.push(data);
    }

    public static int dequeue(Stack<Integer> stack1, Stack<Integer> stack2) {
        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }
        if (stack2.isEmpty()) {
            return -1;
        }
        return stack2.pop();
    }

    public boolean isEmpty(Stack<Integer> stack1, Stack<Integer> stack2) {
        return stack1.empty() && stack2.empty();
    }

    public static void main(String[] args) {
        Stack<Integer> stack1 = new Stack<Integer>();
        Stack<Integer> stack2 = new Stack<Integer>();

        enqueue(stack1, stack2, 10);
        enqueue(stack1, stack2, 20);
        enqueue(stack1, stack2, 30);

        System.out.println(dequeue(stack1, stack2));
        System.out.println(dequeue(stack1, stack2));
        System.out.println(dequeue(stack1, stack2));
        System.out.println(dequeue(stack1, stack2));
    }
}
