// import java.util.Scanner;

// public class bitmanipulation {
//     public static void  main(String[] args){
//         Scanner sc=new Scanner(System.in);
        
        
//         while (true) {
//             System.out.println("1.Get bit");
//             System.out.println("2.Set bit");
//             System.out.println("3.Clear bit");
//             System.out.println("4.Update bit");
//             System.out.println("5.Exit");
//             System.out.println("Choose operation (1-5) :");;
//             int choice=sc.nextInt();
//             System.out.print("Enter No :");;
//             int number=sc.nextInt();
//             System.out.print("Enter the bit Position : ");
//             int pos=sc.nextInt();
//             int bitwise=1<<pos;
//             if (choice==5) {
//                 System.out.println("Goodbye ");
//                 break;
//             }
//             switch (choice) {
//                 case 1:
//                     if ((bitwise&number)==0) {
//                         System.out.println("The value at "+pos+ " is : 0");
//                     }
//                     else{
//                         System.out.println("The value at "+pos+ " is : 1");
//                     }
//                     break;
                    
//                     case 2:
//                    int set=bitwise|number;
//                    System.out.println("Result after setting bit is : "+set);
                   
//                     break;
            
//                 case 3:
//                    int clear=number & (~bitwise);
//                    System.out.println("Result after clearing bit is : "+clear);
//                     break;
            
//                 case 4:
//                 System.out.println("Enter value (0 - 1) : ");
//                 int c=sc.nextInt();
//                 if (c==1) {
//                     int upWithOne=number & (~bitwise);
//                     System.out.println("Result after clearing bit is : "+upWithOne);
                    
//                 }
//                 else{
//                     int upWithZero=number | bitwise;
//                     System.out.println("Result after clearing bit is : "+upWithZero);

//                 }
//                     break;
        
//                 default:
//                     break;
//             }
//         }
//         sc.close();
//     }
// }

import java.util.Scanner;

public class bitmanipulation {

    public static void main(String[] args) {
        // finding binary no of each digit
        System.out.print("Enter a no : ");
        int n;
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        int ans=0;
        double i=0;
        while (n!=0) {
            int bit=n&1;
            // thats formula 
            
            ans=(bit*(int)Math.pow(10, i))+ans;
            n=n>>1;
            i++;
        }
        System.out.println("The binary form is : "+ans);
        sc.close();
    }
}