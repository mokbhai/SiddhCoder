public class QueueUsingLL {

    static void enqueue (LinkedList head, int data) {
        head.addFromLast(data);
    }

    static int dequeue (LinkedList head) {
        return head.removeFromFirst();
    }

    boolean isEmpty (LinkedList head) {
        return head == null;
    }

    public static void main(String[] args) {
        LinkedList ll = new LinkedList();

        enqueue(ll, 10);
        enqueue(ll, 20);
        enqueue(ll, 30);

        System.out.println(dequeue(ll));
        System.out.println(dequeue(ll));
        System.out.println(dequeue(ll));
        System.out.println(dequeue(ll));
    }
}
