import java.util.Scanner;

public class bit {

    public static void main(String[] args) {
        // bit wise opetrator
        System.out.println(5 & 3); // And
        System.out.println(5 | 3); // OR
        System.out.println(5 ^ 3); // XOR : if both input is same then output is 0 and both input is different then
                                   // output is 1

        // Get bit
        System.out.println("Get bit : ");
        int n = 4; // 0100
        int pos = 2;
        int bitmask = 2 << pos; // get the 2 bit position =2 of a no n=0010
        // 0010 after left operation 1000
        System.out.println(bitmask);
        if ((bitmask & n) == 0) { // so the value of 4 in binary digit on index is 2 is 0 and the value 2 in
                                  // binary digit after left operation is 1000 so the value on 2nd index is 0 in
                                  // both values so it is true | 0100 == 1000
            System.out.println("bit was zero");
        } else
            System.out.println("bit was not zero");

        // Set bit operation
        System.out.println("Set bit : ");

        if ((bitmask & n) == 0) {
            System.out.println("bit was zero");
        } else {
            System.out.println("bit is not zero");
        }

        // Clear bit :For clearing bit first we do NOT(~) and then And(&)
        int Clearbitwise = ~(bitmask); // 1000 -> 0111
        int newno = Clearbitwise & n; // 0111 & 0100 = 0100 which is equal to 4
        System.out.println(newno);

        // Update bit : Now the update bit have two parts : (1).update to 1 [for
        // converting to 1 we use set bit operation (OR)] (2).update to 0 [for
        // converting to 0 we use clear bit operation (& and then ~(Not))]

        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the Operation (1 or 0) : ");
        int op =sc.nextInt();
        int bitmsk=1<<pos;
        if (op==1) {
            int number=bitmsk | 5;
            System.out.println("The Result of 1 is "+ number);
        }
        else{
            int Notop=~(bitmsk);
            int andop=Notop&5;
            System.out.println("The Result of 0 is "+andop);
        }
        sc.close();
    }
}
