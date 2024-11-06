import java.util.Scanner;

public class Employee {
    private int empId;
    private String name;
    private double salary;

    public Employee(int empId, String name, double salary) {
        this.empId = empId;
        this.name = name;
        this.salary = salary;
    }

    public void raiseSalary(double percentage) {
        if (percentage > 0) {
            double raiseAmount = salary * (percentage / 100);
            salary += raiseAmount;
            System.out.println("Salary raised by " + percentage + "%.");
        } else {
            System.out.println("Invalid percentage. Salary not changed.");
        }
    }

    public void displayInfo() {
        System.out.println("Employee ID: " + empId);
        System.out.println("Name: " + name);
        System.out.println("Salary: Rs." + String.format("%.2f", salary));
    }

    public static void main(String[] args) {
        Employee emp = new Employee(1, "John Doe", 50000.0);
        Scanner sc = new Scanner(System.in);

        // Display employee information before raise
        System.out.println("Employee information before raise:");
        emp.displayInfo();

        // Input percentage to raise salary
        System.out.print("Enter the percentage to raise salary: ");
        double percentage = sc.nextDouble();

        // Raise salary
        emp.raiseSalary(percentage);

        // Display employee information after raise
        System.out.println("\nEmployee information after raise:");
        emp.displayInfo();

        sc.close();
    }
}
