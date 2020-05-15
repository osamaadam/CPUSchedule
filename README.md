# CPU Scheduling Algorithms

This projects simulates First Come First Served (FCFS) and Round Robin scheduling algorithms

## Usage

First, of course, you'd have to clone the project.
Then run the following commands to compile

### Compiling

Make sure you have make and g++ installed on your device. If not, you should first run the folliwing commands.

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

After running the project, you'll be prompt to enter the algorithm you'd like to simulate.

```
0: First Come First Served (FCFS)
1: Round Robin
```

If your choice was to run Round Robin, you'll be prompted again to enter the number of cycles you'd like to assign to each process.

Depending on your choice, the output will be at outputFCFS.txt or outputRR.txt respectively.
