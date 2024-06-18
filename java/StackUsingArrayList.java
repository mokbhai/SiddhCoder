import java.util.ArrayList;

public class StackUsingArrayList {
    private ArrayList<Integer> stackList;

    public StackUsingArrayList() {
        stackList = new ArrayList<>();
    }

    public void push(int value) {
        stackList.add(value);
    }

    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return -1;
        } else {
            return stackList.remove(stackList.size() - 1);
        }
    }

    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return -1;
        } else {
            return stackList.get(stackList.size() - 1);
        }
    }

    public boolean isEmpty() {
        return stackList.isEmpty();
    }

    public static void main(String[] args) {
        StackUsingArrayList stack = new StackUsingArrayList();
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);

        System.out.println("Top element (peek): " + stack.peek());

        while (!stack.isEmpty()) {
            System.out.println("Element popped from stack: " + stack.pop());
        }
    }
}
