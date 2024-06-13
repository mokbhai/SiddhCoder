public class LinkedList {

    public static class Node { 
        int data;
        Node next;
        
        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public static Node head;
    public static Node tail;
    public static int size;

    public void addFromLast(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = tail = newNode;
        } else {
            tail.next = newNode;
            tail = newNode;
        }
        size++;
    }

    public void addFromFirst(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = tail = newNode;
        } else {
            newNode.next = head;
            head = newNode;
        }
        size++;
    }

    public int removeFromFirst() {
        if (size == 0) {
            System.out.println("List is empty");
            return -1;
        }
        int removedData = head.data;
        head = head.next;
        if (head == null) {
            tail = null;
        }
        size--;
        return removedData;
    }

    public int removeFromLast() {
        if (size == 0) {
            System.out.println("List is empty");
            return -1;
        }
        if (size == 1) {
            int removedData = head.data;
            head = null;
            tail = null;
            size--;
            return removedData;
        }
        Node current = head;
        while (current.next != tail) {
            current = current.next;
        }
        int removedData = tail.data;
        tail = current;
        tail.next = null;
        size--;
        return removedData;
    }

    public int size() {
        return size;
    }

    public void print() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public int find(int data) {
        Node current = head;
        int n = 0;
        while (current != null) {
            if (current.data == data) {
                System.out.println("Element Found at: " + n);
                return n;
            }
            n++;
            current = current.next;
        }
        System.out.println("Element not Found");
        return -1;
    }

    public void findRecurssively(int data) {
        Node current = head;
        int ans = helper(current, data);
        if (ans != -1) {
            System.out.println("Element Found at: " + ans);
        } else {
            System.out.println("Element not Found");
        }
    }
    // one way
    public int helper(Node head, int data) {
        if (head == null) {
            return -1; 
        }
        if (head.data == data) {
            return 0; 
        }
        int index = helper(head.next, data);
        if (index == -1) {
            return -1; 
        } else {
            return index + 1;
        }
    }
    // other way
    // public static int index = 0;
    // public int helper(Node head, int data) {
    //     if (head == null) {
    //         return -1;
    //     }
    //     if (head.data == data) {
    //         return index;
    //     }
    //     index++;
    //     int result = helper(head.next, data);
    //     if (result == -1) {
    //         index--;
    //     }
    //     return result;
    // }


    public void addAtPosition(int data, int position) {
        if (position < 0 || position > size) {
            System.out.println("Invalid position");
            return;
        }
        if (position == 0) {
            addFromFirst(data);
        } else if (position == size) {
            addFromLast(data);
        } else {
            Node current = head;
            Node newNode = new Node(data);
            for (int i = 0; i < position - 1; i++) {
                current = current.next;
            }
            newNode.next = current.next;
            current.next = newNode;
            size++;
        }
    }

    public static void main(String[] args) {
        LinkedList ll = new LinkedList();
        ll.removeFromFirst(); // Output: List is empty
        ll.addFromLast(1);
        ll.addFromLast(2);
        ll.addFromLast(3);
        System.out.println("Size: " + ll.size()); // Output: Size: 3
        ll.print(); // Output: 1 2 3

        ll.addFromFirst(0);
        System.out.println("Size: " + ll.size()); // Output: Size: 4
        ll.print(); // Output: 0 1 2 3

        System.out.println("Removed from first: " + ll.removeFromFirst()); // Output: Removed from first: 0
        System.out.println("Size: " + ll.size()); // Output: Size: 3
        ll.print(); // Output: 1 2 3

        System.out.println("Removed from last: " + ll.removeFromLast()); // Output: Removed from last: 3
        System.out.println("Size: " + ll.size()); // Output: Size: 2
        ll.print(); // Output: 1 2

        ll.find(0); // Output: Element not Found
        ll.find(1); // Output: Element Found at: 0

        ll.addAtPosition(4, 2);
        System.out.println("\nSize: " + ll.size()); // Output: Size: 3
        ll.print(); // Output: 1 2 3
        ll.addAtPosition(3, 2);
        System.out.println("Size: " + ll.size()); // Output: Size: 4
        ll.print(); // Output: 0 1 2 3
        ll.addAtPosition(0, 0);
        System.out.println("Size: " + ll.size()); // Output: Size: 5
        ll.print(); // Output: 0 1 2 3

        ll.findRecurssively(3);
        ll.findRecurssively(10);

    }

}
