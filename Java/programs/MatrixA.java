import java.util.Scanner;

public class MatrixAddition {
    public static void main(String[] args) {
        // Check if command line argument is provided
        if (args.length < 1) {
            System.out.println(Please provide the size N as a command line argument.);
            return;
        }

        int n = Integer.parseInt(args[0]);
        int[][] matrix1 = new int[n][n];
        int[][] matrix2 = new int[n][n];
        int[][] sum = new int[n][n];

        Scanner sc = new Scanner(System.in);

        // Input first matrix
        System.out.println(Enter the elements of matrix1:);
        for (int i = 0; i < n; i++) {
            for  (int j = 0; j < n; j++) {
                matrix1[i][j] = sc.nextInt();
            }
        }

        // Input second matrix
        System.out.println(Enter the elements of matrix2:);
        for (int i = 0; i < n; i++) {
            for  (int j = 0; j < n; j++) {
                matrix2[i][j] = sc.nextInt();
            }
        }

        // Add the matrices
        for (int i = 0; i < n; i++) {
            for  (int j = 0; j < n; j++) {
                sum[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        // Display the result
        System.out.println(Sum of matrices is:);
        for (int i = 0; i < n; i++) {
            for  (int j = 0; j < n; j++) {
                System.out.print(sum[i][j] +  );
            }
            System.out.println();
        }

        sc.close();
    }
}
