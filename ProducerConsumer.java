import java.util.Scanner;
import java.util.ArrayList;

public class ProducerConsumer
{
	public static void main(String a[]) 
 	{
    	 ArrayList<Integer> buffer=new ArrayList</*Integer*/>();
    	 Thread t1=new Thread((Runnable) new Producer(buffer));
     	 Thread t2=new Thread(new Consumer(buffer));
     	 t1.start();
     	 t2.start();
 	}
}

class Producer implements Runnable
{
     ArrayList<Integer>b=null;
     final int limit=10; 
     int i=0;
    
     Producer(ArrayList<Integer> buffer)
     {
         b=buffer;
     }
    
     public void run()
     {
        while(true)
        {
            try{
                i++;
                produce(i);
               }
            catch(InterruptedException e)
            {
                System.out.println(e);
            }
        }
    }
    
     public void produce(int i) throws InterruptedException
     {
        synchronized(b)
        {
            while(b.size()==limit)
            {
                System.out.println("Producer is waiting for consumer to consume");
                b.wait();
            }
        }
        
        synchronized(b)
        {
            b.add(i);
            System.out.println("Added item are "+i);
            Thread.sleep(100);
            b.notify();
        }
    }
}


class Consumer implements Runnable 
{
    ArrayList<Integer>b;
    
    Consumer(ArrayList<Integer> buffer)
    {
        b=buffer;
    }
    
    public void run()
    {
        while(true)
        {
            try{
                consume();
            }
            catch(InterruptedException e)
            {
                System.out.println(e);
            }
        }
    }
    
    public void consume() throws InterruptedException
    {
        synchronized(b)
        {
            while(b.isEmpty())
            {
                System.out.println("Consumer is waiting for producer to produce items");
                b.wait();
            }
        }
        
        synchronized(b)
        {   
            System.out.println("Consumer is consuming item"+b);
            b.remove(0);
            Thread.sleep(100);
            b.notify();
        }
    }
}