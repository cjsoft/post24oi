import java.util.*;
import java.math.*;

public class Main {
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        int x = in.nextInt();
        while (x-- > 0) {
            int y;
            y = in.nextInt();
            BigInteger a = new BigInteger("1");
            System.out.println(a.shiftLeft(y).toString());
        }
    }
}
