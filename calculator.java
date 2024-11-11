// Import necessary packages for GUI components and event handling
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener; // Import ActionListener for handling button clicks
import javax.swing.*; // Import Swing components

public class calculator extends JFrame implements ActionListener { // Extend JFrame and implement ActionListener
    private JTextField display; // Text field to display the input and result
    private JPanel panel; // Panel to hold the buttons
    private String[] buttons = { // Array of button labels
        "7", "8", "9", "/", 
        "4", "5", "6", "*", 
        "1", "2", "3", "-", 
        "0", ".", "=", "+", 
        "C" // Clear button
    };
    private String operand1 = ""; // First operand
    private String operand2 = ""; // Second operand
    private String operator = ""; // Operator

    public calculator() { // Constructor
        display = new JTextField(); // Initialize the display text field
        display.setEditable(false); // Make the display non-editable
        display.setPreferredSize(new Dimension(200, 50)); // Set preferred size for the display
        add(display, BorderLayout.NORTH); // Add the display to the top of the frame

        panel = new JPanel(); // Initialize the panel
        panel.setLayout(new GridLayout(5, 4)); // Set layout of the panel to a 5x4 grid
        for (String text : buttons) { // Loop through the button labels
            JButton button = new JButton(text); // Create a new button with the label
            button.addActionListener(this); // Add action listener to the button
            panel.add(button); // Add the button to the panel
        }
        add(panel); // Add the panel to the frame

        setTitle("Calculator"); // Set the title of the frame
        setSize(300, 400); // Set the size of the frame
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Set the default close operation
        setVisible(true); // Make the frame visible
    }

    @Override
    public void actionPerformed(ActionEvent e) { // Handle button clicks
        String command = e.getActionCommand(); // Get the command from the button click

        if (command.charAt(0) >= '0' && command.charAt(0) <= '9' || command.equals(".")) { // If the command is a number or a decimal point
           
            if (!operator.isEmpty()) { // If an operator has been entered
                operand2 += command; // Append the command to the second operand
            } else {
                operand1 += command; // Append the command to the first operand
            }
            display.setText(operand1 + operator + operand2); // Update the display
        }
         else if (command.equals("=")) { // If the command is the equals sign
            double result = calculate(Double.parseDouble(operand1), Double.parseDouble(operand2), operator); // Calculate the result
            display.setText(String.valueOf(result)); // Display the result
            operand1 = String.valueOf(result); // Set the result as the first operand for further calculations
            operand2 = ""; // Clear the second operand
            operator = ""; // Clear the operator
        } else if (command.equals("C")) { // If the command is the clear button
            operand1 = ""; // Clear the first operand
            operand2 = ""; // Clear the second operand
            operator = ""; // Clear the operator
            display.setText(""); // Clear the display
        } else { // If the command is an operator
            if (operator.isEmpty() || operand2.isEmpty()) { // If no operator has been entered or the second operand is empty
                operator = command; // Set the operator
            } else {
                double result = calculate(Double.parseDouble(operand1), Double.parseDouble(operand2), operator); // Calculate the result
                operand1 = String.valueOf(result); // Set the result as the first operand for further calculations
                operator = command; // Set the new operator
                operand2 = ""; // Clear the second operand
            }
            display.setText(operand1 + operator + operand2); // Update the display
        }
    }

    private double calculate(double op1, double op2, String operator) { // Perform the calculation
        switch(operator) { // Switch based on the operator
            case "+": return op1 + op2; // Addition
            case "-": return op1 - op2; // Subtraction
            case "*": return op1 * op2; // Multiplication
            case "/": return op1 / op2; // Division
            default: return 0; // Default case
        }
    }

    public static void main(String[] args) { // Main method
        new calculator(); // Create a new instance of the calculator
    }
}