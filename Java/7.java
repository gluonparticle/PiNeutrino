package Java;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class EventDemo {
    JLabel messageLabel;

    EventDemo() {
        JFrame frame = new JFrame("An Event Example");
        frame.setLayout(new FlowLayout());
        frame.setSize(220, 90);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JButton alphaButton = new JButton("Alpha");
        JButton betaButton = new JButton("Beta");

        alphaButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                messageLabel.setText("Alpha was pressed.");
            }
        });

        betaButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                messageLabel.setText("Beta was pressed.");
            }
        });

        frame.add(alphaButton);
        frame.add(betaButton);
        messageLabel = new JLabel("Press a button.");
        frame.add(messageLabel);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new EventDemo());
    }
}
