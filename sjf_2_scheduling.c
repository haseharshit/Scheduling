 #include<stdio.h>
 #include<conio.h>
 struct Process {
	int pid; // Process ID
	int art; // Arrival Time
	int bt; // Burst Time
	int completion; //Completion time
	int wait; //waiting time
};

// Function to find the waiting time for all processes

void findWaitingTime(struct Process proc[], int n)
{
    // array for storing remaining time
	int rt[n];

	// Copy the burst time into rt[]
	for (int i = 0; i < n; i++)
		rt[i] = proc[i].bt;

	int complete = 0, t = 0, min =10000000;
	int shortest = 0, finish_time;
	int check = 0;

	// Process until all processes gets
	// completed
	while (complete != n) {

		// Find process with minimum
		// remaining time among the
		// processes that arrives till the
		// current time`
		for (int j = 0; j < n; j++)
        {
			if ((proc[j].art <= t) &&(rt[j] < min) && (rt[j] > 0)) {
				min = rt[j];
				shortest = j;
				check = 1;
			}
		}

		if (check == 0)
        {
			t++;
			continue;
		}

		// Reduce remaining time by one
		rt[shortest]--;

		// Update minimum
		min = rt[shortest];
		if (min == 0)
        {
          	min = 10000000;
		}


		// If a process gets completely
		// executed
		if (rt[shortest] == 0)
        {

			// Increment complete
			complete++;
			check = 0;

			// Find finish time of current
			// process
			finish_time = t + 1;

            proc[shortest].completion=finish_time;

			// Calculate waiting time
			proc[shortest].wait= proc[shortest].completion - proc[shortest].bt - proc[shortest].art;

			if (proc[shortest].wait < 0)
				proc[shortest].wait = 0;
		}
		// Increment time
		t++;
	}
}

// Function to calculate turn around time
void findTurnAroundTime(struct Process proc[], int n, int tat[])
{
	for (int i = 0; i < n; i++)
    {
      tat[i] = proc[i].bt +proc[i].wait;
    }

}

// Function to calculate average time
void findavgTime(struct Process proc[], int n)
{
	int tat[n], total_wt = 0,
					total_tat = 0;

	// Function to find waiting time of all
	// processes
	findWaitingTime(proc, n);

	// Function to find turn around time for
	// all processes
	findTurnAroundTime(proc, n, tat);

	// Display processes along with all
	// details

	printf("Processes  Arrival Time    Burst time   Completion Time    Waiting time    Turn around time \n ");

	// Calculate total waiting time and
	// total turnaround time
	for (int i = 0; i < n; i++)
    {
		total_wt = total_wt + proc[i].wait;
		total_tat = total_tat + tat[i];

		printf(" %d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d\n",proc[i].pid ,proc[i].art, proc[i].bt ,proc[i].completion,proc[i].wait,tat[i]);
	}

	printf("\nAverage waiting time = %f", (float)total_wt/n );

	printf("\nAverage turn around time = %f", (float)total_tat/n)	;
}

// Driver code
int main()
{
    int n;
    printf("Enter the number of process to schedule: ");
    scanf("%d",&n);

	struct Process proc[n];
	for(int i=0;i<n;i++)
    {
        printf("\nEnter process id: ");
     scanf("%d",&proc[i].pid);
     printf("\nEnter Arrival time: ");
     scanf("%d",&proc[i].art);
     printf("\nEnter Burst time: ");
        scanf("%d",&proc[i].bt);
    }

	findavgTime(proc, n);
	return 0;
}
