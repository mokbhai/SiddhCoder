import java.util.*;


// Basics of Recurssion.

public class hello {  
    public static void main(String[] args) {  
        Scanner scanner = new Scanner(System.in);

        // int size = scanner.nextInt();
        // int[] numbers = takeInput(scanner, size);
        // String str = scanner.nextLine();

        // printArray(numbers);

        // int max = findMax(numbers);
        // System.out.println("The maximum number is: " + max);

        // binarySearch(numbers, 100);

        // reverseArray(numbers);

        // printCombinations(numbers);

        // System.out.println(sumTillNRecursion(size));
        // System.out.println(factorialOfNRecursion(size));
        // System.out.println(fibonacciNumberRecursion(size));
        // System.out.println(powerOfARecursion(10, size));
        // System.out.println(powerOfARecursionInLogN(10, size));
        // System.out.println(checkPalindrom(str, 0, str.length() - 1));
        // printNumberTillNRecursion(size);

        scanner.close();
    }

    public static int[] takeInput(Scanner scanner, int size) {
        int[] array = new int[size];
        System.out.println("Enter " + size + " integers:");
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }
        return array;
    }

    public static void printArray(int[] array) {
        System.out.println("Integers in array are: ");  
        for (int i = 0; i < array.length; i++) {
            System.out.println(array[i]);  
        }
    }

    public static int findMax(int[] array) {
        int max = array[0];
        for (int i = 1; i < array.length; i++) {
            if (array[i] > max) {
                max = array[i];
            }
        }
        return max;
    }

    public static void binarySearch(int arr[], int x) {
        int l = 0, r = arr.length - 1;
        int m = 0;
        boolean isFound = false;
        while (l <= r) {
            m = l + (r - l) / 2;

            if (arr[m] == x) {
                isFound = true;
                break;
            }

            if (arr[m] < x)
                l = m + 1;

            else
                r = m - 1;
        }

        if (isFound) {
            System.out.println("The number is found at : " + m);
        } else {
            System.out.println("The number is not found");
        }
    }

    public static void reverseArray(int[] array) {
        int n = array.length;
        
        for (int i = 0; i < n / 2; i++) {
            int temp = array[i];
            array[i] = array[n - i - 1];
            array[n - i - 1] = temp;
        }
        
        for (int i = 0; i < n; i++) {
            System.out.print(array[i] + " ");
        }
    }

    public static void printCombinations(int[] array) {
        int n = array.length;
        System.out.println("Printing combinations:");
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                System.out.print("[");
                for (int k = i; k <= j; k++) {
                    System.out.print(array[k]);
                    if (k != j) {
                        System.out.print(",");
                    }
                }
                System.out.print("] ");
            }
            System.out.println();
        }
    }

    public static int sumTillNRecursion(int n) {
        if (n == 1) {
            return 1;
        }
        int temp = sumTillNRecursion(n-1); // function constant
        return  temp + n;
    }

    public static int factorialOfNRecursion(int n) {
        if (n == 1) {
            return 1;
        }
        int temp = factorialOfNRecursion(n-1); // function constant
        return  temp * n;
    }

    public static int fibonacciNumberRecursion(int n) {
        if (n <= 1) {
            return n;
        } else {
            return fibonacciNumberRecursion(n - 1) + fibonacciNumberRecursion(n - 2);
        }
    }

    public static void printNumberTillNRecursion(int n) {
        if (n == 0) {
            return;
        }
        printNumberTillNRecursion(n-1);
        System.out.println(n);
    }

    public static long powerOfARecursion(long a, int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return a;
        }

        return powerOfARecursion(a, n-1) * a;
    }

    public static long powerOfARecursionInLogN(long a, int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return a;
        }
        if (n%2 != 0) {
            return powerOfARecursion(a, n-1) * a;
        } else {
            return powerOfARecursion(a, n/2) * powerOfARecursion(a, n/2);
        }
    }

    public static boolean checkPalindrom(String str, int s, int e) {
        if (str.charAt(s) != str.charAt(e)) {
            return false;
        }
        if (s >= e) {
            return true;
        }
        return checkPalindrom(str, s+1, e-1);
    }

}
