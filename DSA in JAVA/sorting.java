public class sorting {

    public static void print(int[] array) {
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
          System.out.println();
    }
    
    public static void main(String[] args) {
        // Selection sorting
        int[] array = { 45, 6, 78, 8, 3, 4 };
        int small = 0;
        for (int i = 0; i < array.length - 1; i++) {
            small = i;
            for (int j = i + 1; j < array.length; j++) {
                if (array[small] > array[j]) {
                    small = j;
                }
            }
            int temp = array[small];
            array[small] = array[i];
            array[i] = temp;
            System.out.print("Selection sorting step "+i+" : ");
            print(array);
        }
        System.out.println();
        // Insertion Sorting
        int[] arr={9,4,6,8,2};
        for (int i = 1; i < arr.length; i++) {
            int cur =arr[i]; //curr=4
            int prev=i-1; // prev=0 index
            while (prev>=0 && cur<arr[prev]) {
                arr[prev+1]=arr[prev]; // 1 idx = 9 value
                prev--; // prev =0 so it will be prev=-1, so loop will exit
            }
            arr[prev+1]=cur; //prev=-1 so prev+1= 0 so on 0 idx =curr value which is 4
                            //in simple arr[0]=4
           System.out.print("Insertion Sorting step "+i+" : ");
           print(arr);
         
        }
    }
}
