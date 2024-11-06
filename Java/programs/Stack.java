import java.util.Scanner;

class Stack {
    private int[] elements;
    private int top;
    private static final int MAX_SIZE = 10;

    public Stack() {
        elements = new int[MAX_SIZE];
        top = -1;
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public boolean isFull() {
        return top == MAX_SIZE - 1;
    }

    public void push(int element) {
        if (isFull()) {
            System.out.println("Stack is full. Cannot push more elements.");
        } else {
            elements[++top] = element;
            System.out.println("Pushed: " + element);
        }
    }

    public void pop() {
        if (isEmpty()) {
            System.out.println("Stack is empty. Cannot pop elements.");
        } else {
            int poppedElement = elements[top--];
            System.out.println("Popped: " + poppedElement);
        }
    }

    public void display() {
        if (isEmpty()) {
            System.out.println("Stack is empty.");
        } else {
            System.out.print("Stack: ");
            for (int i = 0; i <= top; i++) {
                System.out.print(elements[i] + " ");
            }
            System.out.println();
        }
    }
}

public class StackDemo {
    public static void main(String[] args) {
        Stack stack = new Stack();
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.println("\nStack Operations");
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Display");
            System.out.println("4. Exit");
            System.out.print("Enter your Choice: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter Number to push: ");
                    int num = sc.nextInt();
                    stack.push(num);
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    stack.display();
                    break;
                case 4:
                    sc.close();
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
        }
    }
}
