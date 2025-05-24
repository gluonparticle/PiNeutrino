// File: ReadCookieServlet.java
package javaprogram;

import jakarta.servlet.http.*;
import java.io.IOException;

public class ReadCookieServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        Cookie[] cookies = request.getCookies();
        String empId = null;

        if (cookies != null) {
            for (Cookie cookie : cookies) {
                if (cookie.getName().equals("EMPID")) {
                    empId = cookie.getValue();
                    break;
                }
            }
        }


        if (empId != null) {
            response.getWriter().println("EMPID: " + empId);
        } else {
            response.getWriter().println("No cookie found with name EMPID.");
        }
    }
}
