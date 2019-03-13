import java.util.concurrent.Semaphore;

public class ReaderWriter
{
	static int readcount=0;
	static Semaphore S=new Semaphore(1);
	static Semaphore wrt=new Semaphore(1);

static class Reader implements Runnable
{
	public void run()
{
try{
	S.acquire();
	readcount++;
	if(readcount==1){
	wrt.acquire();
	S.release();}
	System.out.println(Thread.currentThread().getName()+" Started Reading");
	Thread.sleep(500);
	System.out.println(Thread.currentThread().getName()+" Finish Reading");
	S.acquire();
	readcount--;
	if(readcount==0){
	wrt.release();
	S.release();}
}
catch(InterruptedException e)
{
	System.out.println(e);
}

}
}

static class Writer implements Runnable
{
public void run()
{
try
{
	wrt.acquire();
	System.out.println("Started Writing");
	Thread.sleep(500);
	System.out.println("Finish Writing");
	wrt.release();
}
catch(InterruptedException e)
{
	System.out.println(e);
}
}


}
public static void main(String args[])
{
	Reader r=new Reader();
	Writer w=new Writer();
	Thread t1=new Thread(r);
	Thread t2=new Thread(r);
	Thread t3=new Thread(w);
	Thread t4=new Thread(w);
	Thread t5=new Thread(w);
	t3.start();
	t3.setName("Writer1");
	t5.start();
	t5.setName("Writer3");
	t1.start();
	t1.setName("Reader1");
	t4.start();
	t4.setName("Writer2");
	t2.start();
	t1.setName("Reader2");
}
}