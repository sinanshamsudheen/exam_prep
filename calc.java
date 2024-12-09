
import java.awt.event.*;
import javax.swing.*;

public class calc extends JFrame implements ActionListener {

    JLabel l1;
    JTextField t1;
    JButton b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15,bClear;
    int flag = 0;
    int a = 0, b = 0, c = 0;

    calc() {
        setSize(800, 800);
        setLayout(null);
        setVisible(true);
        l1 = new JLabel("CALCULATOR");
        t1 = new JTextField(20);
        b1 = new JButton("7");
        b2 = new JButton("8");
        b3 = new JButton("9");
        b4 = new JButton("4");
        b5 = new JButton("5");
        b6 = new JButton("6");
        b7 = new JButton("1");
        b8 = new JButton("2");
        b9 = new JButton("3");
        b10 = new JButton("+");
        b11 = new JButton("-");
        b12 = new JButton("*");
        b13 = new JButton("/");
        b15 = new JButton("=");
        b14 = new JButton("0");
        bClear=new JButton("C");

        l1.setBounds(175, 50, 150, 150);
        t1.setBounds(100, 150, 250, 50);
        b1.setBounds(100, 200, 50, 50);
        b2.setBounds(150, 200, 50, 50);
        b3.setBounds(200, 200, 50, 50);
        b4.setBounds(100, 250, 50, 50);
        b5.setBounds(150, 250, 50, 50);
        b6.setBounds(200, 250, 50, 50);
        b7.setBounds(100, 300, 50, 50);
        b8.setBounds(150, 300, 50, 50);
        b9.setBounds(200, 300, 50, 50);
        b10.setBounds(250, 200, 50, 50);
        b11.setBounds(250, 250, 50, 50);
        b12.setBounds(250, 300, 50, 50);
        b13.setBounds(300, 200, 50, 50);
        b14.setBounds(300, 250, 50, 50);
        b15.setBounds(300, 300, 50, 50);
        bClear.setBounds(350,250,50,50);
        add(l1);
        add(t1);
        add(b1);
        add(b2);
        add(b3);
        add(b4);
        add(b5);
        add(b6);
        add(b7);
        add(b8);
        add(b9);
        add(b10);
        add(b11);
        add(b12);
        add(b13);
        add(b14);
        add(b15);
        add(bClear);
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        b5.addActionListener(this);
        b6.addActionListener(this);
        b7.addActionListener(this);
        b8.addActionListener(this);
        b9.addActionListener(this);
        b10.addActionListener(this);
        b11.addActionListener(this);
        b12.addActionListener(this);
        b13.addActionListener(this);
        b14.addActionListener(this);
        b15.addActionListener(this);
        bClear.addActionListener(this);
    }

    public void actionPerformed(ActionEvent ae) {
        try {
            if (ae.getSource() == b1) {
                t1.setText(t1.getText() + "7");
            }
            if (ae.getSource() == b2) {
                t1.setText(t1.getText() + "8");
            }
            if (ae.getSource() == b3) {
                t1.setText(t1.getText() + "9");
            }
            if (ae.getSource() == b4) {
                t1.setText(t1.getText() + "4");
            }
            if (ae.getSource() == b5) {
                t1.setText(t1.getText() + "5");
            }
            if (ae.getSource() == b6) {
                t1.setText(t1.getText() + "6");
            }
            if (ae.getSource() == b7) {
                t1.setText(t1.getText() + "1");
            }
            if (ae.getSource() == b8) {
                t1.setText(t1.getText() + "2");
            }
            if (ae.getSource() == b9) {
                t1.setText(t1.getText() + "3");
            }
            if (ae.getSource() == b14) {
                t1.setText(t1.getText() + "0");
            }
            if (ae.getSource() == b10) {
                a = Integer.parseInt(t1.getText());
                t1.setText("");
                flag = 1;
            }
            if (ae.getSource() == b11) {
                a = Integer.parseInt(t1.getText());
                t1.setText("");
                flag = 2;
            }
            if (ae.getSource() == b12) {
                a = Integer.parseInt(t1.getText());
                t1.setText("");
                flag = 3;
            }
            if (ae.getSource() == b13) {
                a = Integer.parseInt(t1.getText());
                t1.setText("");
                flag = 4;
            }
            if(ae.getSource()==bClear){
            t1.setText("");
            }
            if (ae.getSource() == b15) {
                b = Integer.parseInt(t1.getText());
                switch (flag) {
                    case 1:
                        c = a + b;
                        t1.setText(String.valueOf(c));
                        break;
                    case 2:
                        c = a - b;
                        t1.setText(String.valueOf(c));
                        break;
                    case 3:
                        c = a * b;
                        t1.setText(String.valueOf(c));
                        break;
                    case 4:
                        if (b == 0) {
                            t1.setText("Error: Division by zero not possible");
                            return;
                        } else {
                            c = a / b;
                            t1.setText(String.valueOf(c));
                        }
                        break;
                }
            }
        } catch (NumberFormatException e) {
            t1.setText("Error: Invalid Input");
        } catch (Exception e) {
            t1.setText("Error: " + e.getMessage());
        }
    }

    public static void main(String args[]) {
        calc c1 = new calc();
    }
}
