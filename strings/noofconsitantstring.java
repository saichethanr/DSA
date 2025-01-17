import java.util.stream.Collector;
import java.util.stream.Collectors;

public class noofconsitantstring {
    public static void main(String[] args) {
        String a = "programming";
        String result = a.chars().distinct().mapToObj(c->String.valueOf((char)c)).collect(Collectors.joining());
        System.out.println(result);
    }
}
