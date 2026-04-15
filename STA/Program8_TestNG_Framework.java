import org.testng.annotations.Test;
import org.testng.Assert;

public class Program8_TestNG_Framework {

    @Test(priority = 1)
    void openBrowser() {
        System.out.println("Open browser");
    }

    @Test(priority = 2)
    void login() {
        System.out.println("Login");
    }

    @Test(priority = 3)
    void addItem() {
        System.out.println("Add item to cart");
        // This is meant to fail per the lab manual to show TestNG error reporting
        Assert.assertEquals(5, 10, "Item count mismatch"); 
    }

    @Test(priority = 4)
    void close() {
        System.out.println("Close browser");
    }
}