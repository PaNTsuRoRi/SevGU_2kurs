import java.util.*;

public class Transfer{
    //Статические методы перевода "строка - объект" и обратно
    public static List <Distribution> StringsToDistributions(List <String> lines){
        if((lines == null) || (lines.isEmpty())) return null;
        List <Distribution> distributions = new ArrayList <Distribution>();
        for(int i = 0; i < lines.size(); i++){
            String[] words = lines.get(i).split(",");
            if(words.length != 4) return null;
            Distribution d = new Distribution();
            try{
                d.setTeacher(Integer.parseInt(words[0].trim()));
            } catch (NumberFormatException e){
                return null;
            }
            d.setDepartment(words[1].trim());
            d.setStatus(words[2].trim());
            d.setPosition(words[3].trim());
            distributions.add(d);
        }
        return distributions;
    }
    public static List <String> DistributionsToStrings(List <Distribution> distributions){
        if((distributions == null) || (distributions.isEmpty())) return null;
        List <String> lines = new ArrayList <String>();
        for(Distribution dis: distributions)
            lines.add(String.format("%12d, %8s, %14s, %20s", dis.getTeacher(), dis.getDepartment(), dis.getStatus(), dis.getPosition()));
        return lines;
    }
}
