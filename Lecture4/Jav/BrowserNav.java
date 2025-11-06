package Lecture4.Jav;
import java.util.Scanner;
import java.util.Stack;

public class BrowserNav {

    public static void main(String[] args) {
        String google = "https://www.google.com";
        String mak = "https://www.mak.ac.ug";
        String facebook = "https://www.facebook.com";
        String twitter = "https://www.twitter.com";
        String instagram = "https://www.instagram.com";
        String linkedin = "https://www.linkedin.com";
        String urls[] = {google, mak, facebook, twitter, instagram, linkedin};
        
        Stack<String> history = new Stack<>();
        Stack<String> forwardStack = new Stack<>();
        Scanner scanner = new Scanner(System.in);
        int urlIndex = 0;
        
        // Start with the first URL
        history.push(urls[urlIndex]);
        System.out.println("Current page: " + history.peek());

        OUTER:
        while (true) {
            System.out.println("\nEnter your choice:");
            System.out.println("1 - Visit next URL");
            System.out.println("2 - Go back");
            System.out.println("3 - Go forward");
            System.out.println("4 - View current page");
            System.out.println("0 - Exit");
            System.out.print("Choice: ");
            int response = scanner.nextInt();
            switch (response) {
                case 1 -> {
                    // Visit next URL
                    urlIndex++;
                    if (urlIndex >= urls.length) {
                        urlIndex = 0;
                    }
                    history.push(urls[urlIndex]);
                    forwardStack.clear(); // Clear forward history when visiting new page
                    System.out.println("Visiting: " + urls[urlIndex]);
                }
                case 2 -> {
                    // Go back
                    if (history.size() > 1) {
                        forwardStack.push(history.pop());
                        System.out.println("Going back to: " + history.peek());
                    } else {
                        System.out.println("No previous page in history!");
                    }
                }
                case 3 -> {
                    // Go forward
                    if (!forwardStack.isEmpty()) {
                        history.push(forwardStack.pop());
                        System.out.println("Going forward to: " + history.peek());
                    } else {
                        System.out.println("No forward page available!");
                    }
                }
                case 4 -> {
                    // View current page
                    if (!history.isEmpty()) {
                        System.out.println("Current page: " + history.peek());
                    } else {
                        System.out.println("No page loaded!");
                    }
                }
                case 0 -> {
                    System.out.println("Exiting...");
                    scanner.close();
                    break OUTER;
                }
                default -> System.out.println("Invalid choice!");
            }
        }
    }
}
