package day2;

import java.io.File;
import java.util.Scanner;
import java.util.Vector;
import java.io.FileNotFoundException;

public class App2 {
    static int evaluate(Vector<Integer> vec, int noun, int verb) {
        boolean ok = true;
        vec.set(1, noun);
        vec.set(2, verb);
        for (int i = 0; i < vec.size() && ok;) {
            if (vec.get(i) == 1) {
                int a = vec.get(vec.get(i + 1));
                int b = vec.get(vec.get(i + 2));
                vec.set(vec.get(i + 3), a + b);
            } else if (vec.get(i) == 2) {
                int a = vec.get(vec.get(i + 1));
                int b = vec.get(vec.get(i + 2));
                vec.set(vec.get(i + 3), a * b);
            } else if (vec.get(i) == 99) ok = false;
            else ok = false;
            i = i + 4;
        }
        return vec.get(0);
    }

    public static void main(String[] args) {
        try {
            Vector<Integer> vec = new Vector<>();
            Scanner scanner = new Scanner(new File("input.txt")).useDelimiter(",");
            while (scanner.hasNextInt()) {
                vec.add(scanner.nextInt());
            }
            scanner.close();
            Integer ris;
            for (int noun = 31; noun < 100; noun++) {
                for (int verb = 46; verb < 100; verb++) {
                    Vector<Integer> testVec = vec;
                    ris = evaluate(testVec, noun, verb);
                    if (ris.equals(19690720)) {
                        System.out.println("noun " + noun);
                        System.out.println("verb " + verb);
                        System.out.println("result: " + (100 * noun + verb));
                        noun = 200;
                        verb = 200;
                    }
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("Error");
            e.printStackTrace();
        }
    }

}