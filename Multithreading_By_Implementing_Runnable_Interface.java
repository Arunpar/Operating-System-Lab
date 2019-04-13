class MyThread implements Runnable
{
    public void run()
    {
        for(int i=0;i<10;i++)
        System.out.println("Parent Thread");
    }
}
public class Multithreading_By_Implementing_Runnable_Interface 
{
    public static void main(String[] args) 
    {
        MyThread t=new MyThread ();
        Thread t1=new Thread(t);
        t1.start();

        for(int i=0;i<10;i++)
        System.out.println("Main Thread");
    }
}