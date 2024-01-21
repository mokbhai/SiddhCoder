import java.util.Scanner;
public class input {
    public static void main(String[] arg) {

        Scanner scan = new Scanner(System.in);
        String txt = scan.next(); // scans till first space or "\n"
        String txt2 = scan.nextLine(); // for whole next line
        System.out.println(txt + txt2);
    }
}
