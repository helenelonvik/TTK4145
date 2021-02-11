Exercise 2 - Theory questions
-----------------------------

### What is an atomic operation?
> An operation during which a processor can simultaneously read a location and write it in the same bus operation. This prevents any other processor or I/O device from writing or reading memory until the operation is complete. Atomic implies indivisibility and irreducibility, so an atomic operation must be performed entirely or not performed at all.

### What is a critical section?
>The critical section contains shared variables or resorces whih are needed to be syncronized to maintain consistency of data variable. The critical section is therefore a code segment which multiple processes can acess.

### What is the difference between race conditions and data races?
> A race condition is a situation, in which the result of an operation depends on the interleaving of certain individual operations. A data race is a situation, in which at least two threads access a shared variable at the same time. At least on thread tries to modify the variable

### What are the differences between semaphores, binary semaphores, and mutexes?
> A mutex is a mutual excusion technique ehich locks a resource before it uses it. If more than one thread wishes to use the resouce they have to wait for the first one to unlock it.
>A semaphore is a variable that is used for vontrolling access to a resource. It has no mutual exclusion and use a count that helps tasks to be acquired an released numerous times.
>A binary semaphore is like a counting semaphore but its value is restricted to 0 and 1. The binary semaphore has mutual exclusion.

### What are the differences between channels (in Communicating Sequential Processes, or as used by Go, Rust), mailboxes (in the Actor model, or as used by Erlang, D, Akka), and queues (as used by Python)? 
> 

Channels, mailboxes and queues are all used for message passing, the difference is in how it is done. Channels are synchronous and symmetric, like a phone call, where you have to set up a closed communication in order to send or recieve data. A mailbox is asynchronous and asymmetric in a way that the recieve messages from all over, and then other processes can pick it up whenever. The last element is a queue, which is FIFO. This ensures that all the tasks get a thread, but not in an optimal manner.

### List some advantages of using message passing over lock-based synchronization primitives.
> It allows you to pass message/date between threads or processes
> It is easier to get right and therfore easy to prevent concurrency bugs which is easy to get when using locking.
> Message passing systems are nice for big systems which involves multiple data handelers, because it can store the data in multiple places, and send around copies of variables needed. This way we can recover fast if there should be a computer breakdown.
> The messages can contain almost anything.
> The thread is responsible for its own data.
> Is better for safety 


### List some advantages of using lock-based synchronization primitives over message passing.
> Messageing isn't really viable for single systems.
> Some algorithms become much simpler
> If an algorithm is wait-free, there will be improved performance and reduced footprint as there is less object allocating in the form of a new message.