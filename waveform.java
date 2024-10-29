import java.awt.*;
import javax.swing.*;

public class waveform extends JPanel {
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        int amplitude = 75;
        int frequency = 10;
        int width = getWidth();
        int height = getHeight();
        int midY = height / 2;

        // // Draw the horizontal axis (middle line)
        // g.drawLine(0, midY, width, midY);

        // // Draw the vertical axis (left edge line)
        // g.drawLine(0, 0, 0, height);

        // Draw the waveform
        for (int x = 0; x < width; x++) {
            int y = (int) (amplitude * Math.sin(2 * Math.PI * frequency * x / width));
            g.drawLine(x, midY - y, x, midY - y);
        }
    }

    public static void main(String[] args) {
        JFrame f = new JFrame("Waveform Drawer");
        waveform drawer = new waveform();

        f.add(drawer);
        f.setSize(600, 400);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }
}

