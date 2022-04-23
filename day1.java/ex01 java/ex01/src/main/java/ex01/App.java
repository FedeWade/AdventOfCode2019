package ex01;

import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;

public class App 
{
    public static void main( String[] args )
    {

        try {
            int sum = 0;

            Scanner scanner = new Scanner(new File("input.txt"));
            while (scanner.hasNextInt()) {
              int data = scanner.nextInt();
              sum += (data/3)-2;
            }
            System.out.println(sum);

            scanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
            }
        }
    }
