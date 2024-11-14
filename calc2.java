
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Mycalculator extends JFrame implements ActionListener{
    JTextField display=new JTextField();
    JPanel p=new JPanel();
    
    String[] buttons={ "1","2","3","+",
                       "4","5","6","-",
                       "7","8","9","*",
                       "C","0","=","/" };
    private String operand1="";
    private String operand2="";
    private String operator="";

    public Mycalculator(){

        display.setEditable(false);
        display.setPreferredSize(new Dimension(20,80));
        p.setLayout(new GridLayout(4,5));
        for(String text: buttons){
            JButton b=new JButton(text);
            b.addActionListener(this);
            p.add(b);
        }
        setVisible(true);
        setSize(500,400);
        add(p);
        add(display,BorderLayout.NORTH);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public void actionPerformed(ActionEvent e){
        String command=e.getActionCommand();
        if(command.charAt(0)>='0' && command.charAt(0)<='9' || command.charAt(0)=='.'){
            if(!operand1.isEmpty()){
                operand2+=command;
            }
            else{
                operand1+=command;
            }
            display.setText(operand1 + operator + operand2);
        }
        else if(command.equals("=")){
            try {
                double result=calculateRes(Double.parseDouble(operand1),Double.parseDouble(operand2),operator);
                operand1=String.valueOf(result);
                operand2="";
                operator="";
                display.setText(operand1+operator+operand2);

            } catch (ArithmeticException k) {
                display.setText(k.getMessage());
                operand1="";
                operand2="";
                operator="";
            }
        }
        else if(command.equals("C")){
            operand1="";
            operand2="";
            operator="";
             display.setText(operand1+operator+operand2);

        }
        else{
            if(operator.isEmpty() || operand2.isEmpty()){
                operator=command;
            display.setText(operand1+operator+operand2);
            
            }
            else{
                double res=calculateRes(Double.parseDouble(operand1),Double.parseDouble(operand2),operator);
                operand1=String.valueOf(res);
                operand2="";
                operator=command;
             display.setText(operand1+operator+operand2);

            }
        }
    }
    public double calculateRes(double op1,double op2,String operator){
        switch(operator){
            case "+" : return op1+op2;
            case "-" : return op1-op2;
            case "*": return op1*op2;
            case "/" :{
                if(op2==0){
                    throw new ArithmeticException("cannot divide by zero");
                } return op1/op2;
                }
            default: return 0;
        }
    }
}
public class calc2 {
    public static void main(String[] args) {
        new Mycalculator();
    }
}
