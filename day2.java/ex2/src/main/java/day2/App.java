package day2;

import java.io.File;
import java.util.Scanner;
import java.util.Vector;
import java.io.FileNotFoundException;


public class App 
{
    public static void main( String[] args )
    {
        try {
            Vector<Integer> vec = new Vector<>();
            Scanner scanner = new Scanner(new File("input.txt")).useDelimiter(",");
            while(scanner.hasNextInt()) {
                vec.add(scanner.nextInt());
            }
            scanner.close();

            vec.set(1, 12);
            vec.set(2, 2);
            boolean ok = true;

            for(int i=0; i<vec.size() && ok;) {
                if(vec.get(i) == 1) {
                    int a = vec.get(vec.get(i+1));
                    int b = vec.get(vec.get(i+2));

                    vec.set(vec.get(i+3), a + b);
                }
                else if(vec.get(i) == 2) {
                    int a = vec.get(vec.get(i+1));
                    int b = vec.get(vec.get(i+2));

                    vec.set(vec.get(i+3), a * b);                }
                else if(vec.get(i) == 99) ok=false;
                else {
                    System.out.println("error");
                    ok=false;
                }
                i=i+4;
            }
            System.out.println(vec.get(0));

        } catch (FileNotFoundException e) {
            System.out.println("Error");
            e.printStackTrace();
        }
    }
    
}
