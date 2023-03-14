public class Distribution implements Comparable <Distribution>{
    //запись внутренней таблицы
    //поля
    //формат строки, представляющей запись о распределении:
    private final static String DIS_FORMAT_STRING = "| %12d | %8s | %14s | %20s |";
    //ключевые поля:
    private int teacher; //номер паспорта преподавателя
    private String department; //аббревиатура кафедры
    //неключевые поля:
    private String status; //статус
    private String position; //должность
    //конструктор без параметров
    public Distribution(){
        teacher = 0;
        department = "";
        status = "";
        position = "";
    }
    //конструктор с параметрами
    public Distribution(int teacher, String department, String status, String position){
        this.teacher = teacher;
        this.department = department;
        this.status = status;
        this.position = position;
    }
    //геттеры
    public int getTeacher(){ return teacher; }
    public String getDepartment(){ return department; }
    public String getStatus(){ return status; }
    public String getPosition(){ return position; }
    //сеттеры
    public void setTeacher(int teacher){ this.teacher = teacher; }
    public void setDepartment(String department){ this.department = department; }
    public void setStatus(String status){ this.status = status; }
    public void setPosition(String position){ this.position = position; }
    //переопределяется метод toString класса Object
    @Override
    public String toString(){
        return String.format(DIS_FORMAT_STRING, teacher, department, status, position);
    }
    //переопределяется метод equals класса Object
    @Override
    public boolean equals(Object ob){
        if(ob == this) return true; //один и тот же объект
        if(ob == null) return false; //передана null-ссылка
        if(getClass() != ob.getClass()) return false; //объекты разных классов
        Distribution dis = (Distribution)ob; // преобразуем Object в Distribtion
        //проверяется равенство ключей
        return ((teacher == dis.teacher) && (department.equals(dis.department)));
    }
    //переопределяется метод hashCode класса Object
    public int hashCode(){
        return 7*(new Integer(teacher)).hashCode()+
               13*department.hashCode()+
               18*status.hashCode()+
               23*position.hashCode();
    }
    //определяется метод CompareTo интерфейса Comparable
    public int compareTo(Distribution dis){
        //сравниваются только ключевые поля
        //по возрастанию кафедры,
        //в рамках одной кафедры - 
        //по возрастанию номера паспорта преподавателя
        int c = department.compareTo(dis.department);
        if(c < 0) return -1;
        if(c > 0) return 1;
        if(teacher < dis.teacher) return -1;
        if(teacher > dis.teacher) return 1;
        return 0;
    }
}