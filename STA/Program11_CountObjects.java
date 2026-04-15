import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.testng.annotations.Test;
import java.util.List;

public class Program11_CountObjects {
    WebDriver driver;

    @Test(priority = 1)
    void openBrowser() {
        driver = new ChromeDriver();
        driver.get("https://www.demoblaze.com/");
        driver.manage().window().maximize();
    }

    @Test(priority = 2)
    void countObjects() {
        List<WebElement> elements = driver.findElements(By.xpath("//*"));
        System.out.println("Total number of elements on the page: " + elements.size());
    }

    @Test(priority = 3)
    void closeBrowser() {
        driver.quit();
    }
}