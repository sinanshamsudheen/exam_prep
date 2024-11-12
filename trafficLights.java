import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
class lights extends JPanel implements ActionListener{
    private JRadioButton r1;
    private JRadioButton r2;
    private JRadioButton r3;

    private Color red_c;
    private Color green_c;
    private Color yellow_c;
    public lights(){

        setBounds(0,0,640,480);
        r1=new JRadioButton("Red");
        r2=new JRadioButton("Yellow");
        r3=new JRadioButton("Green");

        // r1.setSelected(true);
        red_c=getBackground();
        green_c=getBackground();
        yellow_c=getBackground(); 
        ButtonGroup gp= new ButtonGroup();
        gp.add(r1);
        gp.add(r2);
        gp.add(r3);

        add(r1);
        add(r2); 
        add(r3);
        r1.addActionListener(this);
        r2.addActionListener(this);
        r3.addActionListener(this);
    }
    public void actionPerformed(ActionEvent e){
        if(r1.isSelected()){
            red_c=Color.red;
            green_c=getBackground();
            yellow_c=getBackground(); 
        }else if(r2.isSelected()){
            yellow_c=Color.yellow;
            green_c=getBackground();
            red_c=getBackground();
        }else if(r3.isSelected()){
            yellow_c=getBackground();
            green_c=Color.green;
            red_c=getBackground();
        }
        repaint();
    }
    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        g.drawOval(30,50,50,50);
        g.drawOval(30,120,50,50);
        g.drawOval(30,190,50,50);
        g.setColor(red_c);
        g.fillOval(30,50,50,50);
        g.setColor(yellow_c);
        g.fillOval(30,120,50,50);
        g.setColor(green_c);
        g.fillOval(30,190,50,50);
    }
}

public class trafficLights{
    public static void main(String[] args){
        JFrame f=new JFrame("Traffic lights");
        f.setSize(640,480);
        f.setVisible(true);
        f.setLayout(null);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        lights t=new lights();
        f.add(t);
    }
}