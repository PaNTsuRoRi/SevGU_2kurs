import java.util.*;
//Компаратор:
//обеспечивает сортировку по возрастанию команды, 
// в рамках одной команды по убыванию числа голов 
public class CompCommandAscBallDesc implements Comparator{
    public int compare (Object ob1, Object ob2){
        Result res1 = (Result) ob1;
        Result res2 = (Result) ob2;
        if (res1.getСоmmand().compareTo(res2.getСоmmand())<0) return -1;
        else if (res1.getСоmmand().compareTo(res2.getСоmmand())> 0) return 1;
        //команда одна и та же
        else if (res1.getGoals() < res2.getGoals()) return 1; 
        else if (res1.getGoals() == res2.getGoals()) return 0;
        else return -1;       
    }   
    //нет необходимости переопределять метод equals
}