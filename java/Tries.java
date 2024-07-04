public class Tries {

    static class Node {
        Node[] children = new Node[26];
        boolean eow = false; // end of word

        Node() {
            for (int i = 0; i < 26; i++) {
                children[i] = null;
            }
        }
    }

    static Node root = new Node();

    // Insert a word into the Trie
    static void insert(String word) {
        Node curr = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            int idx = c - 'a';

            if (curr.children[idx] == null) {
                curr.children[idx] = new Node();
            }
            curr = curr.children[idx];
        }
        curr.eow = true;
    }

    // Search for a word in the Trie
    static boolean search(String word) {
        Node curr = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            int idx = c - 'a';
            if (curr.children[idx] == null) {
                return false;
            }
            curr = curr.children[idx];
        }
        return curr.eow;
    }

    // Print all words in the Trie
    static void print(Node root, StringBuilder prefix) {
        if (root.eow) {
            System.out.println(prefix.toString());
        }
        for (int i = 0; i < 26; i++) {
            if (root.children[i] != null) {
                char c = (char) (i + 'a');
                prefix.append(c);
                print(root.children[i], prefix);
                prefix.deleteCharAt(prefix.length() - 1); // backtrack
            }
        }
    }

    public static void main(String[] args) {
        String[] words = { "the", "a", "there", "their", "any", "thee" };
        for (String word : words) {
            insert(word);
        }

        // Search for a word
        System.out.println(search("thee")); // true
        System.out.println(search("these")); // false

        // Print all words in the Trie
        print(root, new StringBuilder());
    }
}
