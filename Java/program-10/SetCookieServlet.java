// File: SetCookieServlet.java
/*Create Dynamic Web Project Program10 in Eclipse.

Add SetCookieServlet.java and ReadCookieServlet.java under javaprogram.

Place the provided web.xml in WEB-INF/.

Run the project on Apache Tomcat.

🌐 URLs to Access
Set cookie: http://localhost:8080/Program10/SetCookieServlet

Read cookie: http://localhost:8080/Program10/ReadCookieServlet*/

package javaprogram;

import jakarta.servlet.http.*;
import java.io.IOException;

public class SetCookieServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        Cookie cookie = new Cookie("EMPID", "AN2356");
        cookie.setMaxAge(3600);
        cookie.setPath("/");

        response.addCookie(cookie);

        response.setContentType("text/html");
        response.getWriter().println("Cookie 'EMPID' with value 'AN2356' is set.");
    }
}
