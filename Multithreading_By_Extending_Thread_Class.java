class MyThread extends Thread
{
    public void run()
    {
        for(int i=0;i<10;i++)
        System.out.println("Child Thread");
    }
}
class Multithreading_By_Extending_Thread_Class 
{
    public static void main(String[] args) 
    {
        MyThread t=new MyThread();
        t.start();

        for(int i=0;i<10;i++)
        System.out.println("Main Thread");
    }
}