import java.util.*;

public class DistributionGroup{
    //внутренняя таблица распределения преподавателей
    //поля
    //формат строки распределения
    private final static String GROUP_FORMAT_STRING = "Результат распределения: %-s, %-d строк";
    private String name; //название таблицы
    private List <Distribution> distributions; //список записей распределения
    //конструктор без параметров
    public DistributionGroup(){
        name = "";
        distributions = new ArrayList <Distribution>(); //создается пустой список
    }
    //конструкторы с параметрами
    public DistributionGroup(String name){
        this.name = name;
        distributions = new ArrayList <Distribution>(); //создается пустой список
    }
    public DistributionGroup(String name, List list){
        this.name = name;
        distributions = new ArrayList <Distribution>(list); //создается на основе существующего списка
    }
    //геттеры
    public String getName(){ return name; }
    public List <Distribution> getDistributions(){ return distributions; }
    //сеттеры
    public void setName(String name){ this.name = name; }
    public void setDistribution(List <Distribution> distributions){ this.distributions = distributions; }
    //переопределяется метод toString класса Object
    public String toSrting(){
        return String.format(GROUP_FORMAT_STRING, name, getDistributionsNum());
    }
    //запрос на втавку данных
    public boolean addDistribution(Distribution dis){
        if(getDistribution(dis) != null) return false;
        if(distributions.add(dis)) return true;
        else return false;
    }
    //запрос на одиночное удаление
    public boolean delDistribution(Distribution dis){
        if(distributions.remove(dis)) return true;
        else return false;
    }
    //запрос на групповое удаление
    //удалить результаты, в которых статус равен заданному
    public boolean deleteStatus(String status){
        return distributions.removeAll(returnsByStatus(status).distributions);
    }
    //обновление неключевых полей по ключу
    //обновление поля статус
    public boolean updateDistributionStatus(Distribution dis){
        Distribution d = getDistribution(dis);
        if(d != null) { d.setStatus(dis.getStatus()); return true; }
        return false;
    }
    //обновление поля должность
    public boolean updateDistributionPosition(Distribution dis){
        Distribution d = getDistribution(dis);
        if(d != null) { d.setPosition(dis.getPosition()); return true; }
        return false;
    }
    //возвращает число результатов в группе 
    public int getDistributionsNum(){
        return distributions.size();
    }
    //возвращает результат с заданным ключом
    public Distribution getDistribution (Distribution dis){
        for (Distribution d : distributions)
           if (d.equals(dis)) return d; // если ключ найден
        return null; // если ключ не найден
    }
    //возвращает результат с заданным статусом
    public DistributionGroup returnsByStatus(String status){
        DistributionGroup group = new DistributionGroup();
        for(Distribution d: distributions)
            if(d.getStatus().equals(status))
                group.addDistribution(d);
        return group;
    }
    //фильтрация данных
    //возвращает записи о результатах, в которых
    //кафедра равна заданной
    public DistributionGroup filterDepartment(String filter){
        DistributionGroup group = new DistributionGroup(name + ": результаты для кафедры /" + filter + "/");
        for(Distribution dis: distributions)
            if(dis.getDepartment().equals(filter)) group.addDistribution(dis);
        return group;    
    }
    //итоговые расчеты
    //возвращает кол-во штатных сотрудников 
    //и совместителей на каждой кафедре
    public List <TotalRecord> quantityByStatus(){
        int n = distributions.size();
        if(n == 0) return null;
        Set <String> departmentS = new TreeSet();
        for(Distribution dis: distributions)
            departmentS.add(dis.getDepartment());
        List <String> departmentL = new ArrayList(departmentS);
        int m = departmentL.size();
        String dep;
        int[] q = {0, 0};
        List <TotalRecord> totRecList = new ArrayList <TotalRecord>();
        for(int i = 0; i < m; i++){
            dep = departmentL.get(i);
            q[0] = 0; q[1] = 0;
            for(Distribution dis: distributions){
                if(dep.equals(dis.getDepartment()))
                    if(dis.getStatus().equals("штатный")) q[0] += 1;
                    else q[1] += 1;
            }
            totRecList.add(new TotalRecord(dep, q));
        }
        return totRecList;   
    }
    //возвращает кол-ва ставок для заданной
    //должности в вузе
    public int quantityPosition(String pos){
        int q = 0;
        for(Distribution dis: distributions){
            if(dis.getPosition().equals(pos)) q += 1;
        }
        return q;
    }
    //сортировка
    //по правилу компаратора comp
    public DistributionGroup sort(Comparator comp){
        DistributionGroup group = new DistributionGroup(name, distributions);
        Collections.sort(group.distributions, comp);
        return group;
    }
}
