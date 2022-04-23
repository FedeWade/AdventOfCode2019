package ex02;

import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;

public class App {
    public static int fuel(int x) {
        x = (x / 3) - 2;
        if (x <= 0)
            return 0;
        return (x + fuel(x));
    }

    public static void main(String[] args) {
        try {
            int sum = 0;
            Scanner scanner = new Scanner(new File("input.txt"));
            while (scanner.hasNextInt()) {
                int data = scanner.nextInt();
                sum += fuel(data);
            }
            System.out.println(sum);
            scanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("Error");
            e.printStackTrace();
        }
    }
}
