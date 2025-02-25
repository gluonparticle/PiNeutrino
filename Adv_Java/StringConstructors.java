package program;


public class StringConstructor {
    public static void main(String[] args) {
        
        // 1. Using no-argument constructor
        // Type: No-argument constructor
        // This constructor creates an empty string.
        String str1 = new String();
        System.out.println("String created using no-argument constructor: \"" + str1 + "\"");

        // 2. Using default constructor (String default value)
        // Type: Default constructor
        // This constructor creates a string with a default value 
        String str2 = new String("Hello WOrld default!");  // Default value is an empty string.
        System.out.println("String created using default constructor: \"" + str2 + "\"");

        // 3. Using char array constructor
        // Type: Constructor with char array
        // This constructor creates a string from the given character array.
        char[] charArray = {'H', 'e', 'l', 'l', 'o'};
        String str3 = new String(charArray);
        System.out.println("String created using char array constructor: \"" + str3 + "\"");

        // 4. Using byte array constructor with default encoding
        // Type: Constructor with byte array (default encoding)
        // This constructor creates a string from the given byte array using the default character encoding (UTF-8).
        byte[] byteArray = {72, 101, 108, 108, 111}; // ASCII values of 'Hello'
        String str4 = new String(byteArray);
        System.out.println("String created using byte array constructor with default encoding: \"" + str4 + "\"");

        // 5. Using byte array constructor with specified character encoding
        // Type: Constructor with byte array and length
        // This constructor creates a string using a specified subset of the byte array and length.
        String str5 = new String(byteArray, 0, 2); // Using only first 2 bytes
        System.out.println("String created using byte array constructor with specified encoding and length: \"" + str5 + "\"");

        // 6. Using StringBuilder constructor
        // Type: Constructor with StringBuilder
        // This constructor creates a string from the contents of a StringBuilder object.
        StringBuilder stringBuilder = new StringBuilder("Hello");
        String str6 = new String(stringBuilder);
        System.out.println("String created using StringBuilder constructor: \"" + str6 + "\"");

        // 7. Using StringBuffer constructor
        // Type: Constructor with StringBuffer
        // This constructor creates a string from the contents of a StringBuffer object.
        StringBuffer stringBuffer = new StringBuffer("Hello");
        String str7 = new String(stringBuffer);
        System.out.println("String created using StringBuffer constructor: \"" + str7 + "\"");

        // 8. Using String constructor with a substring
        // Type: Constructor with substring
        // This constructor creates a string from a specific part (substring) of another string.
        String str8 = new String("Hello, World!".substring(0, 5)); // Substring "Hello"
        System.out.println("String created using substring: \"" + str8 + "\"");

        // 9. Using String constructor with a specific String (copy constructor)
        // Type: Copy constructor
        // This constructor creates a string by copying the value of another string.
        String str9 = new String(str3); // Copying content from str3
        System.out.println("String created using copy constructor: \"" + str9 + "\"");

        // 10. Using String constructor with string literal
        // Type: Constructor with string literal
        // This constructor creates a string from a string literal.
        String str10 = new String("Hello, Java!");
        System.out.println("String created using string literal: \"" + str10 + "\"");
    }
}
