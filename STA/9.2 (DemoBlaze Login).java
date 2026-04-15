

import org.openqa.selenium.*;
import org.openqa.selenium.chrome.*;
import org.testng.annotations.*;

public class LoginDemoBlaze {
    WebDriver driver;

    @BeforeTest
    void openBrowser() {
        driver = new ChromeDriver();
        driver.get("https://www.demoblaze.com/");
        driver.manage().window().maximize();
    }

    @Test(priority = 1)
    void login() throws InterruptedException {
        driver.findElement(By.id("login2")).click();
        Thread.sleep(2000);
        
        driver.findElement(By.id("loginusername")).sendKeys("demoblaze");
        driver.findElement(By.id("loginpassword")).sendKeys("demoblaze");
        driver.findElement(By.xpath("//button[text()='Log in']")).click();
        
        Thread.sleep(3000);
        
        WebElement logoutButton = driver.findElement(By.id("logout2"));
        if (logoutButton.isDisplayed()) {
            System.out.println("User is successfully logged in");
        } else {
            System.out.println("User login failed");
        }
    }

    @AfterTest
    void closeBrowser() {
        driver.quit();
    }
}
