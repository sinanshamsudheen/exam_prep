import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class mycalc extends JFrame implements ActionListener{
    JPanel panel;
    JTextField screen=new JTextField();
    private String[] buttons=
            {"1","2","3","+",
             "4","5","6","-",
             "7","8","9","*",
             "C","0","=","/"};
    private String operand1="";
    private String operator="";
    private String operand2="";

    public mycalc(){
        screen.setEditable(false);
        screen.setPreferredSize(new Dimension(20,50));
        add(screen,BorderLayout.NORTH);
        panel=new JPanel();
        panel.setLayout(new GridLayout(5,4));
        for(String text : buttons){
            JButton button=new JButton(text);
            button.addActionListener(this);
            panel.add(button);
        }
        add(panel);
        setVisible(true);
        setTitle("Calculator");
        setSize(400,400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    @Override
    public void actionPerformed(ActionEvent e){
        String command=e.getActionCommand();

        if(command.charAt(0)>='0' && command.charAt(0)<='9' || command.equals(".")){
            if(!operator.isEmpty()){
                operand2+=command;
            }else{
                operand1+=command;
            }
            screen.setText(operand1+operator+operand2);
        }else if(command.equals("=")){
            double result=calculator(Double.parseDouble(operand1),Double.parseDouble(operand2),operator);
            screen.setText(String.valueOf(result));
            operand1=String.valueOf(result);
            operand2="";
            operator="";
        }else if(command.equals("C")){
            operand1="";
            operand2="";
            operator="";
            screen.setText(operand1+operator+operand2);
        }
        else{
            if(operator.isEmpty() || operand2.isEmpty()){
                operator=command;
            }else{
                double result=calculator(Double.parseDouble(operand1),Double.parseDouble(operand2),operator);
                operand1=String.valueOf(result);
                operator=command;
                operand2="";
            }
            screen.setText(operand1+operator+operand2);
        }
    }
    public double calculator(double operand1,double operand2,String operator){
        switch(operator){
            case "+" : return operand1+operand2;
            case "-" : return operand1-operand2;
            case "*" : return operand1*operand2;
            case "/" : return operand1/operand2;
            default: return 0;
        }
    }
    public static void main(String[] args) {
        mycalc c=new mycalc();
    }

}
