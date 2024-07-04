import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class fileTaker {
    public String input() {
        String fileName = "input.txt";
        StringBuilder res = new StringBuilder();

        // Use try-with-resources to ensure the reader is closed automatically
        try (BufferedReader bufferedReader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = bufferedReader.readLine()) != null) {
                res.append(line).append("/n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return res.toString();
    }

    public static void main(String[] args) {
        fileTaker taker = new fileTaker();
        String fileContent = taker.input();
        System.out.println(fileContent);
    }
}
