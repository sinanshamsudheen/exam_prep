import java.awt.event.*;
import javax.swing.*;


class keyboard extends JFrame{
    JLabel l;
    public keyboard(){
        l=new JLabel();
        l.setBounds(0,0,400,400);
        add(l);

        addKeyListener(new KeyAdapter(){
            public void keyPressed(KeyEvent e){
                l.setText("key pressed"+e.getKeyChar());
            }
            public void keyReleased(KeyEvent e){
                l.setText("key released"+e.getKeyChar());
            }
        });
        setSize(400,400);
        setLayout(null);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
public class keyevents {
    public static void main(String[] args) {
        
        keyboard k=new keyboard();
    }
}
