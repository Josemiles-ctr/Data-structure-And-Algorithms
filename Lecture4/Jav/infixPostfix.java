package Lecture4.Jav;

import java.util.Stack;

public class infixPostfix {
    
    // Method to return precedence of operators
    private static int precedence(char operator) {
        switch (operator) {
            case '+', '-' -> {
                return 1;
            }
            case '*', '/' -> {
                return 2;
            }
            case '^' -> {
                return 3;
            }
        }
        return -1;
    }
    
    // Method to check if character is an operator
    private static boolean isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
    }
    
    // Method to convert infix expression to postfix
    public static String infixToPostfix(String infix) {
        StringBuilder postfix = new StringBuilder();
        Stack<Character> stack = new Stack<>();
        
        for (int i = 0; i < infix.length(); i++) {
            char ch = infix.charAt(i);
            
            // If character is a whitespace, skip it
            if (ch == ' ') {
                continue;
            }
            
            // If character is an operand (letter or digit), add it to output
            if (Character.isLetterOrDigit(ch)) {
                postfix.append(ch);
            }
            // If character is '(', push it to stack
            else if (ch == '(') {
                stack.push(ch);
            }
            // If character is ')', pop until '(' is found
            else if (ch == ')') {
                while (!stack.isEmpty() && stack.peek() != '(') {
                    postfix.append(stack.pop());
                }
                if (!stack.isEmpty() && stack.peek() == '(') {
                    stack.pop(); // Remove '(' from stack
                }
            }
            // If character is an operator
            else if (isOperator(ch)) {
                // Pop operators with higher or equal precedence
                while (!stack.isEmpty() && precedence(ch) <= precedence(stack.peek())) {
                    postfix.append(stack.pop());
                }
                stack.push(ch);
            }
        }
        
        // Pop all remaining operators from stack
        while (!stack.isEmpty()) {
            postfix.append(stack.pop());
        }
        
        return postfix.toString();
    }
    
    public static void main(String[] args) {
        // Test cases
        String[] expressions = {
            "A+B*C",
            "A*(B+C)",
            "A+B*C-D",
            "(A+B)*(C-D)",
            "A^B^C",
            "A+B*C+D/E-F",
            "((A+B)*C-(D-E))^(F+G)"
        };
        
        System.out.println("Infix to Postfix Conversion:");
        System.out.println("=" .repeat(50));
        
        for (String infix : expressions) {
            String postfix = infixToPostfix(infix);
            System.out.printf("Infix:    %s\n", infix);
            System.out.printf("Postfix:  %s\n\n", postfix);
        }
    }
}
