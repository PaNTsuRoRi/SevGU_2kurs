import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.event.*;

public class EditPanel extends JPanel{
    //Панель редактирования
    JTextField tf1;
    JTextField tf2;
    JTextField tf3;
    JTextField tf4;
    public EditPanel(){
        setLayout(new GridLayout(2,4,2,2));
        JButton but1=new JButton ("Добавить");
        JButton but2=new JButton ("Обновить");
        JButton but3=new JButton ("Удалить");
        JButton but4=new JButton ("Удалить группу записей по статусу:");
        tf1=new JTextField("");
        tf2=new JTextField("");
        tf3=new JTextField("");
        tf4=new JTextField("");
        add(tf1); add(tf2); add(tf3); add(tf4);
        add(but1); add(but2); add(but3); add(but4);
        but1.addActionListener(new ActionListener() { //анонимный слушатель
                public void actionPerformed (ActionEvent e) {
                    insert();
                }
            }
        );
        but2.addActionListener(new ActionListener() { //анонимный слушатель
	        public void actionPerformed (ActionEvent e) {
	            update();
	        }
            }    
        );
        but3.addActionListener(new ActionListener() { //анонимный слушатель
	        public void actionPerformed (ActionEvent e) {
	            delete();
	        }
            }    
        );
        but4.addActionListener(new ActionListener() { //анонимный слушатель
	        public void actionPerformed (ActionEvent e) {
	            deleteGroup(tf3.getText());
	        }
            }    
        );
    }
    private void insert(){
        int n;  
        String str1, str2, str3, str4;
        str1=tf1.getText(); str2=tf2.getText(); str3=tf3.getText(); str4=tf4.getText();
        if (str1.equals("")||str2.equals("")||str3.equals("")||str4.equals("")){
            MainFrame.MSG.setText("Задайте значения полей");
            return;}
        try{//Контролируем исключения при преобразовании из String в число 
            n=Integer.parseInt(str1);
        }//try  
        catch (NumberFormatException  e){// обработчик исключения для try 
            MainFrame.MSG.setText("   Задайте правильно номер паспорта");
            return;
        }
        MainFrame.MSG.setText("   Запрос на добавление записи в таблицу");
        if (!Global.table.addDistribution(new Distribution(n, str2, str3, str4)))
            MainFrame.MSG.setText("   Запись не добавлена, возможно нарушена уникальность ключа");  
        Global.updateJTable(Global.table.getDistributions());
        tf1.setText(""); tf2.setText(""); tf3.setText(""); tf4.setText("");
    }
    private void update(){
        int n;  
        String str1, str2, str3, str4;
        str1=tf1.getText(); str2=tf2.getText(); str3=tf3.getText(); str4=tf4.getText();
        if (str1.equals("")||str2.equals("")||str3.equals("")||str4.equals("")){
            MainFrame.MSG.setText("Задайте значения полей");
            return;}
        try{//Контролируем исключения при преобразовании из String в число 
            n=Integer.parseInt(str1);
        }//try  
        catch (NumberFormatException  e){// обработчик исключения для try 
            MainFrame.MSG.setText("   Задайте правильно номер паспорта");
            return;}
        MainFrame.MSG.setText("   Запрос на обновление записи в таблице");
        if (!Global.table.updateDistributionStatus(new Distribution(n, str2, str3, str4)) ||
            !Global.table.updateDistributionPosition(new Distribution(n, str2, str3, str4)))
            MainFrame.MSG.setText("   Запись не обновлена, возможно записи с таким ключом нет");  
        Global.updateJTable(Global.table.getDistributions());
        tf1.setText(""); tf2.setText(""); tf3.setText(""); tf4.setText("");
    }
    private void  delete(){
        int n;
        String str1, str2;
        str1=tf1.getText(); str2=tf2.getText();     
        if (str1.equals("")||str2.equals("")){
            MainFrame.MSG.setText("Задайте значения полей ключа");
            return;}
        try{//Контролируем исключения при преобразовании из String в число 
            n=Integer.parseInt(str1);
        }//try  
        catch (NumberFormatException  e){// обработчик исключения для try 
            MainFrame.MSG.setText("   Задайте правильно номер паспорта");
            return;}
        MainFrame.MSG.setText("   Запрос на удаление записи по ключу");
        if (!Global.table.delDistribution(new Distribution(n, str2, "", "")))
            MainFrame.MSG.setText("   Запись не удалена, возможно записи с таким ключом нет");  
        Global.updateJTable(Global.table.getDistributions());
        tf1.setText(""); tf2.setText(""); tf3.setText(""); tf4.setText("");
    }
    private void deleteGroup(String status){
        String str3;
        str3 = tf3.getText();
        if (str3.equals("")){
            MainFrame.MSG.setText("Задайте значение поля - статус");
            return;}
        if (!Global.table.deleteStatus(status))
            MainFrame.MSG.setText("   Записи не удалены, возможно таких записей нет");  
        Global.updateJTable(Global.table.getDistributions());
        tf1.setText(""); tf2.setText(""); tf3.setText(""); tf4.setText("");
    }
}
