import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class shapes2 extends JFrame implements ActionListener{
    String shape="rect";
    String[] buttons={"rect","oval","line"};
    public shapes2(){
        JPanel panel=new JPanel();
        for(String text:buttons){
            JButton button=new JButton(text);
            button.addActionListener(this);
            panel.add(button);
        }
        add(panel);
        setSize(400,400);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(null);
    }
    @Override
    public void paint(Graphics g) {
        super.paint(g);
        if (shape.equals("rect")) {
            g.drawRect(150, 150, 100, 50);
        } else if (shape.equals("oval")) {
            g.drawOval(150, 150, 100, 50);
        } else if (shape.equals("line")) {
            g.drawLine(150, 150, 250, 200);
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        shape = e.getActionCommand();
        repaint();
    }
    @Override;
    public void actionPerformed(ActionEvent e){
        String command=e.getActionCommand();
        if(command.equals("rect")){
            shapes2.drawOval()
        }
    }
    public static void main(String[] args) {
        shapes2 s=new shapes2();
    }
}