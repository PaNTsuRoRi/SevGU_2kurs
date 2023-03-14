import javax.swing.table.AbstractTableModel;
import java.util.*;

public class DistributionTableModel extends AbstractTableModel{
    //Модель для основной таблицы
     List <Distribution> distributions;
     public DistributionTableModel(List <Distribution> distributions) {
        super();
        this.distributions = distributions;
    }
    @Override
    public int getRowCount() {
        return distributions.size();
    }
    @Override
    public int getColumnCount() {
        return 4;
    }
    @Override
    public Object getValueAt(int d, int c) {
        switch (c) {
            case 0:
                return distributions.get(d).getTeacher();
            case 1:
                return distributions.get(d).getDepartment();
            case 2:
                return distributions.get(d).getStatus();
            case 3:
                return distributions.get(d).getPosition();
            default:
                return "";
        }
    }
    @Override
    public String getColumnName(int c) {
        String name = "";
        switch (c) {
            case 0:
                name = "Номер паспорта преподавателя";
                break;
            case 1:
                name = "Кафедра";
                break;
            case 2:
                name = "Статус";
                break;
            case 3:
                name = "Должность";
        }
        return name;
    }
}
