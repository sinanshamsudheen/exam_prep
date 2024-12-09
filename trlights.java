import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class trlights extends JPanel implements ActionListener{
    private Color red_c;
    private Color yellow_c;
    private Color green_c;

    private JRadioButton r1;
    private JRadioButton r2;
    private JRadioButton r3;
    public trlights(){
        setBounds(0,50,80,100);

        r1=new JRadioButton("red");
        r2=new JRadioButton("yellow");
        r3=new JRadioButton("green");

        ButtonGroup gp=new ButtonGroup();
        gp.add(r1);
        gp.add(r2);
        gp.add(r3);
        add(r1);
        add(r2);
        add(r3);
        red_c=getBackground();
        yellow_c=getBackground();
        green_c=getBackground();
        // r1.setSelected(true);
        r1.addActionListener(this);
        r2.addActionListener(this);
        r3.addActionListener(this);

    }
    public void actionPerformed(ActionEvent e){
        if(r1.isSelected()){
            red_c=Color.red;
            yellow_c=getBackground();
            green_c=getBackground();
        }
        else if(r2.isSelected()){
            red_c=getBackground();
            yellow_c=Color.yellow;
            green_c=getBackground();
        }else if(r3.isSelected()){
            red_c=getBackground();
            yellow_c=getBackground();
            green_c=Color.green;
        }
        repaint();
    }
    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        g.drawOval(0,30,50,50);
        g.drawOval(0,90,50,50);
        g.drawOval(0,150,50,50);
        g.setColor(red_c);
        g.fillOval(0,30,50,50);
        g.setColor(yellow_c);
        g.fillOval(0,90,50,50);
        g.setColor(green_c);
        g.fillOval(0,150,50,50);
    }
    public static void main(String[] args) {
        trlights t=new trlights();
        JFrame f=new JFrame();
        f.add(t);
        f.setSize(400,500);
        f.setVisible(true);
        f.setLayout(null);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
int y=(int)(amplitude*Math.sin(2*Math.PI))