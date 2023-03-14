import java.util.*;

//Компаратор:
//обеспечивает сортировку
//по возрастанию в поле кафедра, внутри одной кафедры
//по возрастанию в поле должность, внутри одной должности
//по возрастанию в поле статус
public class CompDepAscPosAscStatAsc implements Comparator{
    public int compare(Object ob1, Object ob2){
        Distribution dis1 = (Distribution) ob1;
        Distribution dis2 = (Distribution) ob2;
        if(dis1.getDepartment().compareTo(dis2.getDepartment()) < 0) return -1;
        else if(dis1.getDepartment().compareTo(dis2.getDepartment()) > 0) return 1;
        if(dis1.getPosition().compareTo(dis2.getPosition()) < 0) return -1;
        else if(dis1.getPosition().compareTo(dis2.getPosition()) > 0) return 1;
        if(dis1.getStatus().compareTo(dis2.getStatus()) < 0) return -1;
        else if(dis1.getStatus().compareTo(dis2.getStatus()) == 0) return 0;
        else return 1;
    }
}
