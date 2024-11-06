// Shape class (Superclass)
class Shape {
    public void draw() {
        System.out.println("Drawing a shape.");
    }

    public void erase() {
        System.out.println("Erasing a shape.");
    }
}

// Circle class (Subclass)
class Circle extends Shape {
    @Override
    public void draw() {
        System.out.println("Drawing a circle.");
    }

    @Override
    public void erase() {
        System.out.println("Erasing a circle.");
    }
}

// Triangle class (Subclass)
class Triangle extends Shape {
    @Override
    public void draw() {
        System.out.println("Drawing a triangle.");
    }

    @Override
    public void erase() {
        System.out.println("Erasing a triangle.");
    }
}

// Square class (Subclass)
class Square extends Shape {
    @Override
    public void draw() {
        System.out.println("Drawing a square.");
    }

    @Override
    public void erase() {
        System.out.println("Erasing a square.");
    }
}

// Main class to demonstrate polymorphism
public class ShapeDemo {
    public static void main(String[] args) {
        // Creating objects of different subclasses
        Shape shape1 = new Circle();
        Shape shape2 = new Triangle();
        Shape shape3 = new Square();

        // Demonstrating polymorphic behavior
        shape1.draw();
        shape1.erase();

        shape2.draw();
        shape2.erase();

        shape3.draw();
        shape3.erase();
    }
}
