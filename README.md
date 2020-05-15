# CPU Scheduling Algorithms

This projects simulates First Come First Served (FCFS) and Round Robin scheduling algorithms

## Usage

First, of course, you'd have to clone the project.
Then run the following commands to compile

### Compiling

Make sure you have _make_ and _g++_ installed on your device. If not, you should first run the following commands.

_These commands are specific to Debian Linux._
_Use the appropriate installation method for your respective operating system._

```sh
-$ sudo apt update
-$ sudo apt install make g++ -y
```

Then you may navigate to the project folder and run the following commands.

```sh
-$ make
-$ ./main
```

### What to expect

After running the project, you'll be prompted to enter the algorithm you'd like to simulate.

```
0: First Come First Served (FCFS)
1: Round Robin
```

If your choice was to run Round Robin, you'll be prompted again to enter the number of cycles you'd like to assign to each process.

Depending on your choice, the output will be at outputFCFS.txt or outputRR.txt respectively.

### Input

Input is to be written inside a file named _input.txt_ in the source directory.
Please create it if for some reason it's not already in the project files.

The template for _input.txt_ should be as follows.

```
ProcessID CPUTime IOTime ArrivalTime
```

#### Sample Input

```
0 1 2 0
1 1 1 5
2 1 1 3
```

Process with ID 0 arrives at time 0, has CPU time 1, and IO time 2.

Process with ID 1 arrives at time 5, has CPU time 1, and IO time 1.

**Disclaimer**

Each process must have all these properties and a unique ID.
