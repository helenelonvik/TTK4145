Exercise 1 - Theory questions
-----------------------------
 
 ### What is the difference between concurrency and parallelism?
 > Concurrency is when two tasks can start, run and complete in overlapping time periods, while parallelism is when task run at the same time on for example a multi-core processor.
 
 ### Why have machines become increasingly multicore in the past decade?
 > Because it will speed up the prosess on the computer. We can do simultaneous processing of programs.
 
 ### Why do we divide software (programs) into concurrently executing parts (like threads or processes)?
 (Or phrased differently: What problems do concurrency help in solving?)
 > Because then we can computate multiple processes at the same time. Any problems where multiple processes are happeing at the same time will happen quicker.
 
 ### Does creating concurrent programs make the programmer's life easier? Harder? Maybe both?
 (Come back to this after you have worked on part 4 of this exercise)
 > Situations that require concurrency are easier to solve, but it also make complexity to the system, therefore make its own problems. Therefore both.
 
 ### What is the conceptual difference between threads and processes?
 > A thread is the unit of execution wothin a process, while a process may have ont to multiple threads. So thread is a segment of a process.
 
 ### Some languages support "fibers" (sometimes called "green threads") or "coroutines"? What are they?
 > Fibers are a particularly lightweight tread of execution, and use cooperative multitasking instead of preemptive multitasking as threading. Coroutines are essentially the same as Fibers, but coroutines are a language-level construct, a form of control flow, while fibers are a systems-level construct, viewed as threads that happen to not run in parallel.
 
 ### What is the Go-language's "goroutine"? A C/POSIX "pthread"?
 > goroutine is a lightweight tread of execution
 
 ### In Go, what does `func GOMAXPROCS(n int) int` change? 
 > It sets the maximum number of CPUs that can execute simultaneously



 
 
 
 
