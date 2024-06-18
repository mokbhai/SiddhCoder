public class StackUsingArray {
    private int[] stackArray;
    private int top;
    private int maxSize;

    public StackUsingArray(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1; 
    }

    public void push(int value) {
        if (top >= maxSize - 1) {
            System.out.println("Stack is full");
        } else {
            stackArray[++top] = value;
        }
    }

    public int pop() {
        if (top < 0) {
            System.out.println("Stack is empty");
            return Integer.MIN_VALUE;
        } else {
            return stackArray[top--];
        }
    }

    public int peek() {
        if (top < 0) {
            System.out.println("Stack is empty");
            return Integer.MIN_VALUE;
        } else {
            return stackArray[top];
        }
    }

    public boolean isEmpty() {
        return (top < 0);
    }

    public static void main(String[] args) {
        StackUsingArray stack = new StackUsingArray(10); 
        
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        stack.push(50);

        System.out.println("Top element (peek): " + stack.peek());

        while (!stack.isEmpty()) {
            System.out.println("Element popped from stack: " + stack.pop());
        }
    }
}
