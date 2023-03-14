import javax.swing.table.AbstractTableModel;
import java.util.*;

public class TotalTableModel extends AbstractTableModel{
    //модель таблицы для итогового запроса
    List <TotalRecord> records;
    String strColName;
    String intColName1;
    String intColName2;
    public TotalTableModel(List <TotalRecord> records, String strColName, String intColName1, String intColName2){
        super();
        this.records = records;
        this.strColName = strColName;
        this.intColName1 = intColName1;
        this.intColName2 = intColName2;
    }
    @Override
    public int getRowCount() {
        return records.size();
    }
    @Override
    public int getColumnCount() {
        return 3;
    }
    @Override
    public Object getValueAt(int r, int c) {
        switch (c) {
            case 0:
                return records.get(r).str;
            case 1:
                return records.get(r).num[0];
            case 2:
                return records.get(r).num[1];
            default:
                return "";
        }
    }
    @Override
    public String getColumnName(int c) {
        String name = "";
        switch (c) {
            case 0:
                name = strColName;
                break;
            case 1:
                name = intColName1;
                break;
            case 2:
                name = intColName2;
                break;
           }
        return name;
    }
}
