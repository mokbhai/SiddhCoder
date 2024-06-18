public class StackUsingLL {
    static LinkedList ll = new LinkedList();
    public static void main(String[] args) {
        StackUsingLL stack = new StackUsingLL();
        
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);

        System.out.println("Top element (peek): " + stack.peek());

        while (!stack.isEmpty()) {
            System.out.println("Element popped from stack: " + stack.pop());
        }
    }

    public void push(int data) {
        ll.addFromFirst(data);
    }

    public static void print() {
        ll.print();
    }

    public  int pop() {
        return ll.removeFromFirst();
    }

    public  int peek() {
        if (isEmpty()) {
            return -1;
        }
        return ll.head.data;
    }

    public  boolean isEmpty() {
        return ll.empty();
    }
}
