public class TotalRecord{
    //запись таблицы итогового расчета
    String str;
    int[] num = new int[2];
    public TotalRecord(String str, int[] num){
        this.str = str;
        this.num[0] = num[0];
        this.num[1] = num[1];
    }
    public String toString(){
        return String.format("%s : %5d - штатных; %5d - совместителей ", str, num[0], num[1]);
    }
}
