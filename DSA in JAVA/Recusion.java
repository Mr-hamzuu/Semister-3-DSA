public class Recusion {
    public static void print1to5(int n) {
        if (n == 6) {
            return;
        }
        System.out.println(n);
        print1to5(n + 1);
    }

    public static void printnaturalno(int n, int sum) {
        sum += n;
        if (n == 0) {
            sum += n;
            System.out.println("The sum is : " + sum);
            return;
        }
        printnaturalno(n - 1, sum);

    }

    public static int factorial(int n) {
        if (n == 1) {
            return 1;
        }
        return n * factorial(n - 1);

    }

    public static int fibonacchi(int n) {
        if (n <= 1) {
            return n;
        }
        return fibonacchi(n - 1) + fibonacchi(n - 2);

    }

    public static int xpowern(int x, int n, int m) {
        if (n == 0) {
            return 1;
        }
        if (x == 0) {
            return 0;
        }
        m++;
        System.out.println(m);
        return x * xpowern(x, n - 1, m);
    }

    public static void towerofhanoi(int n, String src, String helper, String destination) {
        if (n == 1) {
            System.out.println("Transfer disk " + n + " from " + src + " to " + destination);
            return;
        }
        towerofhanoi(n - 1, src, destination, helper);
        System.out.println("Transfer disk " + n + " from " + src + " to " + destination);
        towerofhanoi(n - 1, helper, src, destination);
        // 3,src,hel,des
        // 2,src,des,hel
        // 1 transfer from src to des
        // 2 transfer from src to hel
        // 1 transfer from des to hel

        // 3 transfer from src to des

        // 1 transfer from hel to src
        // 2 transfer from hel to des
        // 1 transfer from src to des

    }

    public static String stringreverse(String s, String newstr, int idx) {
        if (idx < 0) {
            return newstr;
        }
        newstr += s.charAt(idx);
        idx--;
        return stringreverse(s, newstr, idx);
    }

    public static void permutation(String str, String perm, int idx) {
        if (str.length() == 0) {
            System.out.println(perm);
            return;
        }
        for (int i = 0; i < str.length(); i++) {
            char curstr = str.charAt(i);
            String newstr = str.substring(0, i) + str.substring(i + 1);
            permutation(newstr, perm + curstr, idx + 1);
        }
    }

    public static void main(String[] args) {
        // print no from 1 to 5
        print1to5(1);
        // sum of natural no
        printnaturalno(5, 0);
        // factorial
        System.out.println("Factorial : " + factorial(5));
        // fibonacchi sequence
        System.out.println("Fibonacchi : " + fibonacchi(10));
        // x power n
        System.out.println("The 2 Power 5 is :" + xpowern(2, 5, 0));
        // tower of hanoi
        System.out.println("\nTower of Hanoi:");
        towerofhanoi(3, "source", "helper", "destination");
        // String reverse
        String s = "hamza";
        System.out.println(stringreverse(s, "", s.length() - 1));
        // permutation
        permutation("ABC", "", 0);
        String str = "HAmxa";
        System.out.println(str.substring(0, 0));
    }
}
