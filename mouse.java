
import java.awt.event.*;
import javax.swing.*;

class mouseE extends JLabel{
    public mouseE(){
        addMouseListener(new MouseAdapter(){
            public void mouseClicked(MouseEvent e){
                setText("mouse pressed "+ e.getX()+","+e.getY());
            }
            public void mouseReleased(MouseEvent e){
                setText("mouse released "+ e.getX()+","+e.getY());
            }
        });
        addMouseMotionListener(new MouseMotionAdapter() {
            public void mouseDragged(MouseEvent e){
                setText("mouse dragged "+ e.getX()+","+e.getY());
            }
            public void mouseMoved(MouseEvent e){
                setText("mouse dragged "+ e.getX()+","+e.getY());
            }
        });
        setBounds(0,200,400,400);
    }
}
public class mouse {
    public static void main(String[] args) {
        mouseE m=new mouseE();
        JFrame f=new JFrame();
        f.add(m);
        f.setSize(600,600);
        f.setVisible(true);
        f.setLayout(null);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
