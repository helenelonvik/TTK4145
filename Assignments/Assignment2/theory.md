Exercise 2 - Theory questions
-----------------------------

### What is an atomic operation?
> An operation during which a processor can simultaneously read a location and write it in the same bus operation. This prevents any other processor or I/O device from writing or reading memory until the operation is complete. Atomic implies indivisibility and irreducibility, so an atomic operation must be performed entirely or not performed at all.

### What is a critical section?
> The critical section is a code segment where the shared variables can be accessed. An atomic action is required in a critical section i.e. only one process can execute in its critical section at a time. All the other processes have to wait to execute in their critical sections.

### What is the difference between race conditions and data races?
> A race condition is a situation, in which the result of an operation depends on the interleaving of certain individual operations. A data race is a situation, in which at least two threads access a shared variable at the same time. At least on thread tries to modify the variable

### What are the differences between semaphores, binary semaphores, and mutexes?
> A semaphore is an atomic non-negative integrer with two operations. Wait() - which decrements its value by 1 and Signal() - which increments by 1. So that if a wait() signal is ran on a zero semaphore we have to wait until we get a free thread. A binary semaphore has two states, 0 or 1, which can be described as unavailiable and availiable. While the two mentioned above works as resource locking where everyone has the key, the mutex, mutual exclusion, takes ownership or its "lock". Therefore keeping thier thread locked until they says it is done.

### What are the differences between channels (in Communicating Sequential Processes, or as used by Go, Rust), mailboxes (in the Actor model, or as used by Erlang, D, Akka), and queues (as used by Python)? 
> Channels, mailboxes and queues are all used for message passing, the difference is in how it is done. Channels are synchronous and symmetric, like a phone call, where you have to set up a closed communication in order to send or recieve data. A mailbox is asynchronous and asymmetric in a way that the recieve messages from all over, and then other processes can pick it up whenever. The last element is a queue, which is FIFO. This ensures that all the tasks get a thread, but not in an optimal manner.

### List some advantages of using message passing over lock-based synchronization primitives.
1. Message passing systems are nice for big systems which involves multiple data handelers, because it can store the data in multiple places, and send around copies of variables needed. This way we can recover fast if there should be a computer breakdown.
2. The messages can contain almost anything.
3. The thread is responsible for its own data.

### List some advantages of using lock-based synchronization primitives over message passing.
> Threadlocking gives us concurrency on systems with say one processor.
    Messageing isn't really viable for single systems.