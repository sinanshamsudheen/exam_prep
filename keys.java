
import java.awt.event.*;
import javax.swing.*;
class keyE extends JLabel{
    public keyE(){
        setFocusable(true);
        addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e){
                setText("key pressed: "+e.getKeyChar());
            }
            @Override
            public void keyReleased(KeyEvent e){
                setText("key Released : "+e.getKeyChar());
            }
        });
        setBounds(200,200,400,400);
    }
}
public class keys {
    public static void main(String[] args) {
        keyE k=new keyE();
        JFrame f=new JFrame("key events");
        f.setSize(800,800);
        f.setLayout(null);
        f.setVisible(true);     
        f.add(k);
    }
}
