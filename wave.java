
import java.awt.*;
import javax.swing.*;


public class wave extends JPanel{
    private int amplitude,freq,height,width,midY;
    @Override
    public void paintComponent(Graphics g){
        amplitude=75;
        freq=10;
        height=getHeight();
        width=getWidth();
        midY=height/2;
        super.paintComponent(g);
        for(int x=0;x<width;x++){
            int y=(int)(amplitude*Math.cos(2*Math.PI*freq*x/width));
            g.drawLine(x,midY-y,x,midY-y);
        }
    }
    public static void main(String[] args) {
        wave w=new wave();
        JFrame f=new JFrame();
        f.add(w);
        f.setSize(800,900);
        f.setVisible(true);
        f.setLayout(null);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}

