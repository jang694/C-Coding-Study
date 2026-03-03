#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
typedef struct student {
	char name[20];
	int score[3]; //score 0:국어, 1:영어, 2:수학
	float avg;
}STUDENT;

void calculate_avg(STUDENT* s, int size) {
	s[size].avg = (s[size].score[0] + s[size].score[1] + s[size].score[2]) / 3.0;
}
void sort_students(STUDENT* s, int size) {
	STUDENT temp;
	for (int i = 0; i < size-1; i++) {
		int least = i;
		for (int j = i + 1; j < size; j++) {
			if (s[j].avg > s[least].avg) {
				least = j;
			}
		}
		temp = s[i];
		s[i]= s[least];
		s[least]= temp; 
		
	}
}
int main() {
	STUDENT s[3] = { 0 };
	printf("3명의 학생의 이름과 성적을 입력하시오>>\n");
	for (int i = 0; i < 3; i++) {
		scanf("%s %3d %3d %3d", s[i].name, &s[i].score[0], &s[i].score[1], &s[i].score[2]);
	}
	for (int i = 0; i < 3; i++) {
		printf("%s %3d %3d %3d\n", s[i].name, s[i].score[0], s[i].score[1], s[i].score[2]);
	}
	for (int i = 0; i < 3; i++) {
		calculate_avg(&s[0], i);
	}

	printf("평균 점수>>\n");
	for (int i = 0; i < 3; i++) {
		printf("%.2f\n", s[i].avg);
	}
		sort_students(&s[0], 3);
	
	for (int i = 0; i < 3; i++) {
		printf("정렬 : 이름:%s 평균:%.2f (국:%d,영:%d,수:%d\n)", s[i].name, s[i].avg, s[i].score[0], s[i].score[1], s[i].score[2]);
	}

	
	return 0;
}