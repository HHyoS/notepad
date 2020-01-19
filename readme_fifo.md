The uploaded schedule_fifo file is a code for the fifo algorithm that processes a given data.
The code was coded in the Ubuntu environment.
C code that processes the entered data according to the fifo algorithm
The code works in four situations, and the actions are as follows.
1) If there is no currently functioning process or waiting process
2) If there is no currently functioning process and there is a waiting process
3) If there is a process that is currently working and there is no process waiting,
4) If there is a process that is currently working or waiting,

To explain all movements, arrival time at, operating time bt, arrival time to completion time tt.
Time taken from arrival to execution wt.

In 1) case, wt of the incoming process is zero because the incoming process is executed immediately.
tt becomes bt.
2) The sum of bt of all processes already queued is wt of the newly introduced process
tt becomes your wt + bt. And the next process that we're waiting for...
Runs.
3) The remaining run time of the operational process is wt of the process, and tt is wt + bt.
It is possible.
4) For all remaining processes bt + the running time of the process wt.
tt becomes bt + wt of the process.

It's a code that's not good enough, but I hope it helps someone else. Have a nice day.
If you have any questions on this code, please leave a comment and I'll answer you.
