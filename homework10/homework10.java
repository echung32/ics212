import java.util.Scanner;

public class homework10 {
    static
    {
       System.loadLibrary("homework10");
    }
  
    private native void print_table();
  
    public static void main(String[] args)
    {
       Scanner scan = new Scanner(System.in);
       int number;
       boolean success = 0;

       while (success = 0)
       {
            if (scan.hasNextInt())
            {
                number = scan.nextInt();
                if (number >= 0)
                {
                    // idk
                }
            }
       }
    }

 }