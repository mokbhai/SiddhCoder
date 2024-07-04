import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class filePrinter {
    public void print(String s) {
        // Specify the file name and path
        String fileName = "output.txt";

        // Use try-with-resources to ensure the writer is closed automatically
        try (FileWriter fileWriter = new FileWriter(fileName, true); // Open in append mode
                PrintWriter printWriter = new PrintWriter(fileWriter)) {

            // Append data to the file
            printWriter.println(s);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
    }
}
