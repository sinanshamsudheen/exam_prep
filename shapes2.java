import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class shapes2 extends JPanel{
    String shape="rect";
    int x1,x2,y1,y2;
    public shapes2(){
        addMouseListener(new MouseAdapter() {
            public void mousePressed(MouseEvent e){
                x1=e.getX();
                y1=e.getY();
            }
            public void mouseReleased(MouseEvent e){
                x2=e.getX();
                y2=e.getY();
                repaint();
            }
        });
        addMouseMotionListener(new MouseMotionAdapter() {
            public void mouseDragged(MouseEvent e){
                x2=e.getX();
                y2=e.getY();
                repaint();
            }
        });
    }
    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        if(shape.equals("rect")){
            g.drawRect(Math.min(x1,x2),Math.min(y1,y2),Math.abs(x2-x1),Math.abs(y2-y1));
        }
        else if(shape.equals("oval")){
            g.drawOval(Math.min(x1,x2),Math.min(y1,y2),Math.abs(x2-x1),Math.abs(y2-y1));
        }
        else{
            g.drawLine(x1,y1,x2,y2);
        }
    }
    public static void main(String[] args) {
        shapes2 shp=new shapes2();
        JFrame f=new JFrame();
        JPanel p=new JPanel();

        String[] b={"rect","oval","line"};
        for(String text: b){
            JButton button=new JButton(text);
            button.addActionListener(e->shp.shape=text);
            p.add(button);
        }
        f.add(p,BorderLayout.NORTH);
        f.add(shp);
        f.setSize(400,600);
        f.setVisible(true);
        f.setLayout(null);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}