#include <stdio.h>

void inputLetterCode(char jobs[], int n);
int letterControl(char jobs[], int i);
void inputJobTime(char jobs[], int jobTime[][2], int n);
void GanttDraw(char jobs[], int jobTime[][2], int n);
int main(){
	int i, j, jobTime[28][2], n;
	char jobs[28];
	do{
		system("cls");
		printf("Please Enter How Man Jobs There Will Be: ");
		scanf("%d", &n);
	}
	while(n>7 && n<0);
	inputLetterCode(jobs, n);
	inputJobTime(jobs, jobTime, n);
	GanttDraw(jobs, jobTime, n);
	return 0;
}

void inputLetterCode(char jobs[], int n){
	int i=0;
	while(i<n){
		printf("Letter Code of %d. Job: ", i+1);
		jobs[i] = getch();
		printf("%c\n", jobs[i]);
		if(letterControl(jobs, i) == 1){
			printf("You Can Enter Same Letter Only One Time. Please Try Again\n");
			i--;
		}
		i++;
	}
}
int letterControl(char jobs[], int i){
	int j=0, flag=0;
	while(flag == 0 && j!=i){
		if(jobs[i] == jobs[j]){
			flag = 1;
		}
		j++;
	}
	return flag;
}
void inputJobTime(char jobs[], int jobTime[][2], int n){
	int i;
	for(i=0;i<n;i++){
		printf("Starting Time of '%c' Job: ", jobs[i]);
		scanf("%d", &jobTime[i][0]);
		printf("Ending Time of '%c' Job: ", jobs[i]);
		scanf("%d", &jobTime[i][1]);
		while(jobTime[i][1] <= jobTime[i][0]){
			printf("You Must Enter At Least 1 Difference\nRestarting For Job %c:\n", jobs[i]);
			printf("Starting Time of '%c' Job: ", jobs[i]);
			scanf("%d", &jobTime[i][0]);
			printf("Ending Time of '%c' Job: ", jobs[i]);
			scanf("%d", &jobTime[i][1]);
		}
		printf("\n");
	}
}
void GanttDraw(char jobs[], int jobTime[][2], int n){
	int i, j;
	printf("Creating Gantt Diagram..");
	for(i=0;i<n;i++){
		for(j=1;j<=jobTime[i][1];j++){
			if(j<jobTime[i][0]){
				printf("_");
			}
			else{
				printf("%c", jobs[i]);
			}
		}
		printf("\n");
	}
}

