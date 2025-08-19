package abc;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input message and generator
        System.out.print("Enter message bits: ");
        String message = sc.nextLine();
        System.out.print("Enter generator: ");
        String generator = sc.nextLine();

        int[] data = new int[message.length() + generator.length() - 1];
        int[] divisor = new int[generator.length()];

        // Initialize data array with message bits
        for (int i = 0; i < message.length(); i++) {
            data[i] = Integer.parseInt(message.charAt(i) + "");
        }

        // Initialize divisor array with generator bits
        for (int i = 0; i < generator.length(); i++) {
            divisor[i] = Integer.parseInt(generator.charAt(i) + "");
        }

        // Perform division to calculate checksum remainder
        for (int i = 0; i < message.length(); i++) {
            if (data[i] == 1) {
                for (int j = 0; j < divisor.length; j++) {
                    data[i + j] ^= divisor[j];
                }
            }
        }

        // Build the full codeword: message bits + checksum bits (remainder)
        int[] codeword = new int[message.length() + generator.length() - 1];
        for (int i = 0; i < message.length(); i++) {
            codeword[i] = Integer.parseInt(message.charAt(i) + "");
        }
        for (int i = 0; i < generator.length() - 1; i++) {
            codeword[message.length() + i] = data[message.length() + i];
        }

        // Print the full codeword
        System.out.print("The checksum code is: ");
        for (int bit : codeword) {
            System.out.print(bit);
        }
        System.out.println();

        // Now, verify the codeword for correctness

        // Copy codeword into received array for validation
        int[] received = new int[codeword.length];
        for (int i = 0; i < codeword.length; i++) {
            received[i] = codeword[i];
        }

        // Perform division on received codeword
        for (int i = 0; i <= received.length - divisor.length; i++) {
            if (received[i] == 1) {
                for (int j = 0; j < divisor.length; j++) {
                    received[i + j] ^= divisor[j];
                }
            }
        }

        // Check the remainder bits in received for any non-zero bits
        boolean valid = true;
        int remainderStart = received.length - (generator.length() - 1);
        for (int i = remainderStart; i < received.length; i++) {
            if (received[i] == 1) {
                valid = false;
                break;
            }
        }

        if (valid) {
            System.out.println("Data stream is valid");
        } else {
            System.out.println("Data stream is invalid. CRC error occurred.");
        }

        sc.close();
    }
}



/*
 * 
 * Enter message bits: 1101011011
Enter generator: 10011
The checksum code is: 11010110111110
Enter checksum code: 11010110111110
Enter generator: 10011
Data stream is valid
 */
 
