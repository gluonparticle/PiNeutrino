// Abstract Shape class
abstract class Shape {
    // Abstract methods
    public abstract double calculateArea();
    public abstract double calculatePerimeter();
}

// Circle class extending Shape
class Circle extends Shape {
    private double radius;

    // Constructor
    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double calculateArea() {
        return Math.PI * radius * radius;
    }

    @Override
    public double calculatePerimeter() {
        return 2 * Math.PI * radius;
    }
}

// Triangle class extending Shape
class Triangle extends Shape {
    private double side1;
    private double side2;
    private double side3;

    // Constructor
    public Triangle(double side1, double side2, double side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    @Override
    public double calculateArea() {
        // Using Heron's formula
        double s = (side1 + side2 + side3) / 2;
        return Math.sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    @Override
    public double calculatePerimeter() {
        return side1 + side2 + side3;
    }
}

// Main class
public class AbstractShapeDemo {
    public static void main(String[] args) {
        // Creating instances
        Shape circle = new Circle(5);
        Shape triangle = new Triangle(3, 4, 5);

        // Calculating and displaying area and perimeter for Circle
        System.out.println("Circle - Area: " + circle.calculateArea()
                + ", Perimeter: " + circle.calculatePerimeter());

        // Calculating and displaying area and perimeter for Triangle
        System.out.println("Triangle - Area: " + triangle.calculateArea()
                + ", Perimeter: " + triangle.calculatePerimeter());
    }
}
