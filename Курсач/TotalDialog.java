import java.awt.*; 
import javax.swing.*;
import java.awt.event.*;

public class TotalDialog extends JDialog implements ActionListener{
    //Диалог для первого итогового запроса
    //конструктор
    public TotalDialog (JFrame parent, String name, java.util.List <TotalRecord> list){
        // вызов конструктора базового класса
        super (parent, "Подведение итогов", true);
        //true - модальный диалог
        Container cp=getContentPane();
        cp.setLayout(new BorderLayout());
        cp.add (new JLabel(name, JLabel.CENTER),BorderLayout.NORTH);
        JButton ok= new JButton ("OK");
        ok.addActionListener(this); 
        cp.add(ok, BorderLayout.SOUTH); 
        //-----------------------таблица--------------------------------------
        //1. Визуальный компонент для таблицы
        TotalTableModel tableModel = new TotalTableModel(list,"Кафедра", "Штатных", "Совместителей");
        JTable jtable = new JTable(tableModel);
        //Создаем панель прокрутки и включаем в ее состав  таблицу
        JScrollPane scrtable = new JScrollPane(jtable);
        //Устаналиваем размеры прокручиваемой области
        jtable.setPreferredScrollableViewportSize(new Dimension(150, 150));
        add(scrtable,BorderLayout.CENTER);
        MainFrame.MSG.setText("   Итоговый запрос на выборку");
        setSize(320,250);
        setLocation(50,100);
    } 
    public void actionPerformed (ActionEvent e){ 
        //обработчик событий
        dispose();
    }
}
