import java.util.*;

public class Solution {

    private static final String command_insert = "Insert";
    private static final String command_delete = "Delete";

    public static void main(String[] args) {
        int n, q;
        ArrayList<Integer> list = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            list.add(scanner.nextInt());
        }

        q = scanner.nextInt();

        for (int i = 0; i < q; i++) {
            String command = scanner.next();
            if (command.equals(command_insert)) {
                list.add(scanner.nextInt(), scanner.nextInt());
            }
            else if (command.equals(command_delete)) {
                list.remove(scanner.nextInt());
            }
        }

        scanner.close();

        for (int ans : list) {
            System.out.print(ans + " ");
        }
    }
}
