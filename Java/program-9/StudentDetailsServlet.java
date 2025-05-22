// File: StudentDetailsServlet.java
package javaprogram;

import jakarta.servlet.http.*;
import java.io.IOException;

public class StudentDetailsServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html");

        String name = request.getParameter("name");
        String usn = request.getParameter("usn");
        int totalMarks = Integer.parseInt(request.getParameter("totalMarks"));

        String details = "Student Name: " + name + "<br>" +
                         "USN: " + usn + "<br>" +
                         "Total Marks: " + totalMarks;

        response.getWriter().println("<html><body>");
        response.getWriter().println("<h1>Student Details</h1>");
        response.getWriter().println("<p>" + details + "</p>");
        response.getWriter().println("</body></html>");
    }
}
