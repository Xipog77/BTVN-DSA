import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
        
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            int m = scanner.nextInt();
            ArrayList<Integer> newArr = new ArrayList<>();
            for (int j = 0; j < m; j++) {
                newArr.add(scanner.nextInt());
            }
            arr.add(newArr);
        }
        int q = scanner.nextInt();
        for (int i = 0 ; i < q; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            x--;
            y--;
            
            if (x >= arr.size() || y >= arr.get(x).size()) {
                System.out.println("ERROR!");
            }
            else {
                System.out.println(arr.get(x).get(y));
            }
        }
        
        scanner.close();
    }
}
