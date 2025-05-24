// File: GreetingServlet.java
package javaprogram;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import java.io.IOException;

public class GreetingServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws  IOException {

        String username = request.getParameter("username");
        String greetingMessage = "Hello " + (username != null ? username : "User") + ", How Are You?";

        response.getWriter().println("<html><body>");
        response.getWriter().println("<h1>" + greetingMessage + "</h1>");
        response.getWriter().println("</body></html>");
    }
}
