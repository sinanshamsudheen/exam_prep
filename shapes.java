import java.awt.Graphics;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import javax.swing.*;

public class shapes extends JPanel{
    private int x1,x2,y1,y2;
    private String shape="Rect";
    public shapes(){
        addMouseListener(new MouseAdapter() {
            public void mousePressed(MouseEvent e) {
                x1=e.getX();
                y1=e.getY();
            }
            public void mouseReleased(MouseEvent e) {
                x2=e.getX();
                y2=e.getY();
                repaint();
            }
        });
        addMouseMotionListener(new MouseMotionAdapter() {
            public void mouseDragged(MouseEvent e) {
                x2=e.getX();
                y2=e.getY();
                repaint();
            }
        });
    }
        public void paintComponent(Graphics g){
            super.paintComponent(g);
            if(shape.equals("Rect")){
                g.drawRect(Math.min(x1,x2),Math.min(y1,y2),Math.abs(x2-x1),Math.abs(y2-y1));
            }
            else if(shape.equals("Oval")){
                g.drawOval(Math.min(x1,x2),Math.min(y1,y2),Math.abs(x2-x1),Math.abs(y2-y1));
            }else{
                g.drawLine(x1, y1, x2, y2);
            }
        }

    public static void main(String[] args){
        JFrame f=new JFrame();
        JPanel p=new JPanel();
        shapes d= new shapes();

        for(String s: new String[]{"Rect","Oval","line"}){
            JButton J=new JButton(s);
            J.addActionListener(e->d.shape=s);
            p.add(J);
        }
        p.setBounds(0,0,400,400);
        f.add(p);
        f.add(d);
        f.setSize(400,400);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }
}
