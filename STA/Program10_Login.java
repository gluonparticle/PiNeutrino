import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

public class Program7_10_Login {
    public static void main(String[] args) {
        WebDriver driver = new ChromeDriver();
        driver.get("https://www.saucedemo.com/");
        driver.manage().window().maximize();

        driver.findElement(By.id("user-name")).sendKeys("standard_user");
        driver.findElement(By.id("password")).sendKeys("secret_sauce");
        driver.findElement(By.className("submit-button")).click();

        boolean flag = driver.findElement(By.xpath("//button[text()='Open Menu']")).isDisplayed();

        if (flag) {
            System.out.println("Successfully logged in! hurRAY ");
        }

        driver.quit();
    }
}
