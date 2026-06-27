import java.util.Scanner;

public class Day01 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n + 1];

        // Input array elements
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // Input position and element
        int pos = sc.nextInt();
        int x = sc.nextInt();

        // Shift elements to the right
        for (int i = n; i >= pos; i--) {
            arr[i] = arr[i - 1];
        }

        // Insert the element
        arr[pos - 1] = x;

        // Print updated array
        for (int i = 0; i <= n; i++) {
            System.out.print(arr[i] + " ");
        }

        sc.close();
    }
}