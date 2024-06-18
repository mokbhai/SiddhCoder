import java.util.Stack;

public class ValidParentThesisProblem {
    public static void main(String[] args) {
        System.err.println(isValid("{([[({})]])}"));
        System.err.println(isValid("{([[(){}]])}"));
        System.err.println(isValid("{([({}]])}"));
    }

    public static boolean isValid(String str) {
        Stack<Character> stack = new Stack<>();
           
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                int c2 = stack.peek();
                if (c2 == '(' && c == ')')
                    stack.pop();
                else if (c2 == '{' && c == '}')
                    stack.pop();
                else if (c2 == '[' && c == ']')
                    stack.pop();
            }
        }

        return stack.empty();
    }
}
