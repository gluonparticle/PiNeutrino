public class MyPoint {
    private int x;
    private int y;

    // Default constructor
    public MyPoint() {
        this.x = 0;
        this.y = 0;
    }

    // Overloaded constructor
    public MyPoint(int x, int y) {
        this.x = x;
        this.y = y;
    }

    // Set both x and y
    public void setXY(int x, int y) {
        this.x = x;
        this.y = y;
    }

    // Get x and y as an array
    public int[] getXY() {
        return new int[]{x, y};
    }

    // toString method
    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    // Distance to another point (x, y)
    public double distance(int x, int y) {
        int xDiff = this.x - x;
        int yDiff = this.y - y;
        return Math.sqrt(xDiff * xDiff + yDiff * yDiff);
    }

    // Distance to another MyPoint
    public double distance(MyPoint another) {
        return distance(another.x, another.y);
    }

    // Distance to origin (0,0)
    public double distance() {
        return distance(0, 0);
    }

    public static void main(String[] args) {
        MyPoint point1 = new MyPoint(); // Default constructor (0,0)
        System.out.println("Point 1: " + point1);

        MyPoint point2 = new MyPoint(3, 4); // Overloaded constructor (3,4)
        System.out.println("Point 2: " + point2);

        point1.setXY(1, 2); // Set coordinates using setXY()
        System.out.println("Point 1 after setXY(): " + point1);

        int[] coordinates = point2.getXY(); // Get coordinates using getXY()
        System.out.println("Point 2 coordinates: (" + coordinates[0] + ", " + coordinates[1] + ")");

        System.out.println("Distance between Point 1 and (1,2): " + point1.distance(1, 2));
        System.out.println("Distance between Point 1 and Point 2: " + point1.distance(point2));
        System.out.println("Distance from Point 1 to origin: " + point1.distance());
    }
}
