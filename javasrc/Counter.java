package javasrc;

import java.lang.Runnable;
import java.lang.Thread;
import java.io.IOException;

class Counter implements Runnable {
    public void run() {
        for(int i = 1; i <= 5; i++) {
            System.out.println("count: " + i + " from " + Thread.currentThread().getName());
            try {
                Thread.sleep(500);
            } catch(InterruptedException e) {
                System.out.println("Thread interrupted");
            }
        }
    }

    public static void main(String[] args) throws IOException {
        Thread thread1 = new Thread(new Counter(), "Thread-1");
        Thread thread2 = new Thread(new Counter(), "Thread-2");

        thread1.start();
        thread2.start();

        try {
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted");
        }

        System.out.println("Both threads have finished execution.");
    }
}