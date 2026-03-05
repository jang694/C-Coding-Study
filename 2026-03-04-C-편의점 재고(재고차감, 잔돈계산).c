#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
typedef struct item {
	char name[20];
	int price;
	int stock;
}ITEM;
void array_item(ITEM* a, int size, char* target) {
	int found = 0;
	ITEM temp;
	for (int i = 0; i < size - 1; i++) {
		int least = i;
		for (int j = i + 1; j < size; j++) {
			if (a[j].stock < a[least].stock) {
				least = j;//재고의 수가 같을때는 먼저 입력한 물품 먼저 나오게 되어있음.
			}
		}
		temp = a[i];
		a[i] = a[least];
		a[least] = temp;

	}
	printf("작은 순 정렬\n");
	for (int i = 0; i < size; i++) {
		
		printf("재고 확인-%s (재고:%d)\n", a[i].name, a[i].stock);
	}
	for (int i = 0; i < size; i++) {
		if (strcmp(a[i].name, target) == 0) {
			printf("--조회결과--\n");
			printf("%s (가격:%d, 재고:%d)\n", a[i].name, a[i].price, a[i].stock);
			found = 1;
			break;
		}
		

	}
	if (found == 0) {
		printf("조회된 물건이 없습니다.\n");
	}


}
void buy_item(ITEM* a,int size, int money, char* target) {
	int found = 0;
	for (int i = 0; i < size; i++) {
		if (strcmp(a[i].name, target) == 0) {
			if (a[i].price <= money) {
				if (a[i].stock == 0) {
					printf("품절입니다");
				}
				else {
					printf("재고가 있으므로 현재 재고는 %d입니다\n", --a[i].stock);
					printf("거스름돈: %d\n", (money - a[i].price));
					found = 0;
					break;
				}
			}
			else {
				printf("잔액이 부족합니다\n");
			}
		}
		
			
	}
	if (found == 0) {
		printf("그러한 물품은 없습니다.\n");
	}
}

int main() {
	ITEM item[3] = { 0 };
	char array_target[20];
	char buy_target[20];
	int money_target;
	printf("물건의 이름,가격,재고를 적으시오\n");
	for (int i = 0; i < 3; i++) {
		scanf("%s %d %d", item[i].name, &item[i].price, &item[i].stock);
	}
	
	printf("재고를 조회하고 싶은 물건 이름을 적으시오>>");
	scanf("%s", array_target);
	array_item(&item[0], 3, &array_target[0]);
	printf("구매하고 싶은 제품과 가격을 적으시오\n");
	scanf("%s %d", buy_target, &money_target);
	buy_item(&item[0], 3, money_target, buy_target);
	
	
	
	return 0;
}
