package Lecture4.Jav;

import java.util.Stack;

public class infixPrefix {
    
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
    
    // Method to reverse a string
    private static String reverse(String str) {
        return new StringBuilder(str).reverse().toString();
    }
    
    // Method to swap parentheses in expression
    private static String swapParentheses(String str) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            switch (ch) {
                case '(' -> result.append(')');
                case ')' -> result.append('(');
                default -> result.append(ch);
            }
        }
        return result.toString();
    }
    
    // Method to convert infix to postfix (helper for prefix conversion)
    private static String infixToPostfix(String infix) {
        StringBuilder postfix = new StringBuilder();
        Stack<Character> stack = new Stack<>();
        
        for (int i = 0; i < infix.length(); i++) {
            char ch = infix.charAt(i);
            
            // If character is a whitespace, skip it
            if (ch == ' ') {
                continue;
            }
            
            // If character is an operand, add it to output
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
                    stack.pop();
                }
            }
            // If character is an operator
            else if (isOperator(ch)) {
                // For prefix, we use < instead of <= for right associativity
                while (!stack.isEmpty() && precedence(ch) < precedence(stack.peek())) {
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
    
    // Method to convert infix expression to prefix
    public static String infixToPrefix(String infix) {
        // Step 1: Reverse the infix expression
        String reversedInfix = reverse(infix);
        
        // Step 2: Swap '(' with ')' and vice versa
        String swappedInfix = swapParentheses(reversedInfix);
        
        // Step 3: Convert to postfix
        String postfix = infixToPostfix(swappedInfix);
        
        // Step 4: Reverse the postfix to get prefix
        String prefix = reverse(postfix);
        
        return prefix;
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
        
        System.out.println("Infix to Prefix Conversion:");
        System.out.println("=".repeat(50));
        
        for (String infix : expressions) {
            String prefix = infixToPrefix(infix);
            System.out.printf("Infix:   %s\n", infix);
            System.out.printf("Prefix:  %s\n\n", prefix);
        }
    }
}
