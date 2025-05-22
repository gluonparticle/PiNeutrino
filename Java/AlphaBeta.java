package Java;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class AlphaBeta extends JFrame implements ActionListener {
    private JLabel messageLabel;
    private JButton alphaButton, betaButton;

    public AlphaBeta() {
        super();
        setLayout(new FlowLayout());
        setSize(220, 90);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        alphaButton = new JButton("Alpha");
        betaButton = new JButton("Beta");

        alphaButton.addActionListener(this);
        betaButton.addActionListener(this);

        add(alphaButton);
        add(betaButton);

        messageLabel = new JLabel("Press a button.");
        add(messageLabel);

        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == alphaButton) {
            messageLabel.setText("Alpha was pressed.");
        } else if (e.getSource() == betaButton) {
            messageLabel.setText("Beta was pressed.");
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new AlphaBeta());
    }
}
