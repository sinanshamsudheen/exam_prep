import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import javax.swing.*;

class mouse extends JFrame{
    JLabel l;
    public mouse(){
        l=new JLabel();
        l.setBounds(0,0,400,600);
        add(l);

        addMouseListener(new MouseAdapter(){
            public void mousePressed(MouseEvent e){
                l.setText("mouse clicked "+e.getX()+" "+e.getY());
            }
            public void mouseReleased(MouseEvent e){
                l.setText("mouse released "+e.getX()+" "+e.getY());
            }
        });
        addMouseMotionListener(new MouseMotionAdapter() {
            public void mouseDragged(MouseEvent e){
                l.setText("mouse dragged"+e.getX()+" "+e.getY());
            }
            public void mouseMoved(MouseEvent e){
                l.setText("mouse moved "+e.getX()+" "+e.getY());
            }
        });
        setSize(800,800);
        setVisible(true);
        setLayout(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    
}
public class mouseEvents{
    public static void main(String[] args) {
        mouse m1=new mouse();
    }
}