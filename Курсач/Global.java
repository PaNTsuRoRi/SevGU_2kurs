import java.util.*;

public class Global{
    //Содержит глобальные (статические) переменные и методы программы, 
    //посредством которых осуществляется взаимодействие между
    //внутренними представлениями базовой таблицы и результатов
    // запросов и визуальной таблицей
    public static DistributionGroup table; //ссылка на основную таблицу
    public static List <Distribution> distributions; //ссылка на список, выводимый в главное окно
    static DistributionTableModel tableModel; //модель данных для JTable
    public static void updateJTable(List <Distribution> dis){
        //Обновить данные в визуальном компоненте JTable
        distributions.clear();
        distributions.addAll(dis);    
        tableModel.fireTableDataChanged();
    }
}
