import java.awt.event.*;
import javax.swing.*;

class calc extends JPanel implements ActionListener{
    private JButton b1,b2,b3,b4,b5,b6,b7,b8,b9,b0,bmul,badd,bdiv,bsub,beql,bclr;
    public calc(){
        setBounds(0,0,600,800);                                                                                                    
        
        JTextField new JTextField();
        b1=new JButton("1");
        b2=new JButton("2");
        b3=new JButton("3");
        b4=new JButton("4");
        b5=new JButton("5");
        b6=new JButton("6");
        b6=new JButton("6");
        b7=new JButton("7");
        b8=new JButton("8");
        b9=new JButton("9");
        b0=new JButton("0");
        badd=new JButton("+");
        bmul=new JButton("*");
        bdiv=new JButton("/");
        bsub=new JButton("-");
        beql=new JButton("=");
        bclr=new JButton("Clear");

        add(b1);

    }
    public void actionPerformed(ActionEvent e){
        
    }
}
public class calculator{
    public static void main(String[] args) {
        JFrame f=new JFrame("Calculator");
        f.setLayout(null);
        f.setSize(700,900);
        f.setVisible(true);
        calc c=new calc();
        f.add(c);
    }
}