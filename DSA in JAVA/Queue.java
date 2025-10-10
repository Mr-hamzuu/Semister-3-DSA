

class que{
    int[] arr;
    int front;
    int rear;
    int size;
    
    que(int size){
        this.size=size;
        arr=new int[size];
        front =-1;
        rear=-1;
    }
    boolean isfull(){
        return (rear==size-1);
    }
    boolean isempty(){
        return front==-1;
    }
    void insert(int n){
        if(isfull()){
            System.out.println("Queue is Full");
            return;
        }
        if(isempty()){
            front=0;
            
        }
        arr[++rear]=n;
    }
    int remove(){
        if(isempty()){
            System.out.println("Queue is empty");
            return -1;
        }
       return arr[++front];
    }
    void display(){
        if(isempty()){
            return;
        }
        System.out.print("Queue : ");
        for(int i=front;i<=rear;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
}
public class Queue {

   
    public static void main(String args[]) {
        que q=new que(3);
        q.insert(3);
        q.insert(5);
        q.insert(7);
        q.display();
        q.remove();
        q.display();
    }
}
