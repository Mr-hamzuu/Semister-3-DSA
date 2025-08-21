
// sorting array
// public class first {

//     public static void main(String[] args) {
//         int array[]={2,34,6,67};
//         for (int i = 0; i < array.length; i++) {
//             for (int j = i+1; j < array.length; j++) {
//                 if (array[i]>array[j]) {
//                     int temp=array[i];
//                     array[i]=array[j];
//                     array[j]=temp;
//                 }
//             }
//         }
//         for (int i = 0; i < array.length; i++) {

//             System.out.println(array[i]);
//         }
//     }
// }

// import java.util.Scanner;

// public class first {
//     public static int add(int[] no) {
//         for (int i = 0; i < no.length; i++) {
//             System.out.println(no[i]);
//         }
//         return 5;
//     }

//     public static void main(String[] args) {
//         int[] no = { 34, 65, 34, 232 };
//         System.out.println("The no is " + add(no));
//         Scanner scanner = new Scanner(System.in);
//         System.out.print("Enter the no : ");
//         int number = scanner.nextInt();
//         System.out.println(number);

//         scanner.nextLine();
//         System.out.print("Enter the name : ");
//         // nextline is like getline in cpp
//         String name = scanner.nextLine();
//         System.out.println(name);

//         // next is like get in cpp
//         name = scanner.next();
//         System.out.println(name);
//         scanner.close();

//     }
// }

// 2d array passing in func

// public class first {

//     public static void print(int[][] x, int col, int row) {
//         for (int i = 0; i < col; i++) {
//             for (int j = 0; j < row; j++) {
//                 System.out.print(x[i][j] + " ");
//             }
//             System.err.println();
//         }
//     }

//     public static void main(String[] args) {

//         int col = 2;
//         int row = 3;
//         int[][] matrix = { { 34, 45 }, { 56, 23 }, { 67, 98 } };
//         print(matrix, row, col);
//     }
// }

// public class first {

//     public static void main(String[] args) {

//         String name = "hamza";
//         String sec = "hamza";
//         System.out.println(name == sec);

//         if (new String("hamza") .equals(new String("hamza"))) { //== is not correct in this
//             System.out.println("Hello world");
//         } else
//             System.out.println("not hello");
//     }
// }

// OOP in java

class parent {

    protected int x;

    parent(int x) {
        this.x = x;
    }

    int getdata() {
        return x;
    }
}

class child extends parent {
    int y;

    child(int x, int y) {
        super(x);
        this.y = y;
    }

    int getdata() {
        return x + y;
    }
}

public class first {
    public static void main(String[] args) {
        parent p = new parent(34);
        System.out.println(p.getdata());
        child c=new child(3, 5);
        System.out.println(c.getdata());

    }

}