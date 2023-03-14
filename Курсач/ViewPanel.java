import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.event.*;

public class ViewPanel extends JPanel implements ActionListener{
    //Панель просмотра
    JTextField num1; //левая граница диапазона
    JTextField num2;  //правая граница диапазона
    JTextField tf1; //фильтр
    JTextField tf2; //должность для Итог2
    public ViewPanel(){
        setLayout(new GridLayout(3,3,2,2));
        JButton but1 = new JButton ("Итог 1:  кол-во штат/совмест на кафедре");
        JButton but2 = new JButton ("Итог 2:  кол-во ставок для должности");
        JButton but3 = new JButton ("Применить фильтр");
        JButton but4 = new JButton ("Сортировать");
        JButton but5 = new JButton ("Вывести все");
        tf1 = new JTextField("");
        tf2 = new JTextField("");
        JLabel l1 = new JLabel("Введите фильтр (кафедру):",JLabel.CENTER);
        JLabel l2 = new JLabel("Введите должность в вузе:",JLabel.CENTER);
        but1.setActionCommand("Total1");
        but2.setActionCommand("Total2");
        but3.setActionCommand("Filter");
        but4.setActionCommand("Sort");
        but5.setActionCommand("All");
        JPanel p1 = new JPanel();
        add(l1); add(tf1); add(but3);
        add(l2); add(tf2); add(but2);
        add(but1); add(but4); add(but5);
        but1.addActionListener(this);
        but2.addActionListener(this);
        but3.addActionListener(this);
        but4.addActionListener(this);
        but5.addActionListener(this);
    }
    private void showTotal1(){
        TotalDialog td = new TotalDialog (MainFrame.frame, "Кол-во штат/совмест на кафедре:", Global.table.quantityByStatus());
        td.setVisible(true); 
    }
    
    private void showTotal2(){   
        String pos = tf2.getText();
        if (pos.equals("")) {
            MainFrame.MSG.setText("   Введите должность");
            return;
        }
        JOptionPane.showMessageDialog(MainFrame.frame, 
            String.format("Кол-во ставок для должности %s: %5d", pos, Global.table.quantityPosition(pos)));
        tf2.setText("");
    }
    
    private void showFilter(){
        String filter = tf1.getText();
        if (filter.equals("")) {
            MainFrame.MSG.setText("   Введите фильтр");
            return;
        }  
        MainFrame.MSG.setText(String.format("   Запрос на выборку: выдать записи с кафедрой \"%s\"", filter));
        Global.updateJTable(Global.table.filterDepartment(filter).getDistributions());
        tf1.setText("");
    }
    private void showSort(){
        MainFrame.MSG.setText("   Выдать все записи таблицы с сортировкой по кафедре, должности и статусу");
        Global.updateJTable(Global.table.sort(new CompDepAscPosAscStatAsc()).getDistributions());
    }
    private void showAll(){
        MainFrame.MSG.setText("   Выдать все записи таблицы без сортировки");
        Global.updateJTable(Global.table.getDistributions());
    }
    public void actionPerformed (ActionEvent e){
        if("Total1".equals(e.getActionCommand())) showTotal1();
        else if("Total2".equals(e.getActionCommand())) showTotal2();
        else if("Filter".equals(e.getActionCommand())) showFilter();
        else if("Sort".equals(e.getActionCommand())) showSort();
        else showAll();
    } 
}
