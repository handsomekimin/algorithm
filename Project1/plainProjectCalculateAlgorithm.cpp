#include <cstdio>
#include <iostream>
#include <math.h>
#include <algorithm>

#define MAXN 100


int N,M, amount, payer, pn;
// + : will receive,  - : will give
struct st {
	int amount;
	int id;
}moneyMap[MAXN+1];
int participants[MAXN + 1];

void makeMoneyMap() {
	int devidedMoney = ceil(amount / (double) pn);
	printf("total amount : %d devided Money : %d, Exact amount : %lf\n", amount ,devidedMoney, (double) amount/pn);
	
	//N 빵한 돈을 payer 와 participant 사이에 매핑
	moneyMap[payer].amount += amount;
	for (int i = 0; i < pn; ++i) {
		moneyMap[participants[i]].amount -= devidedMoney;
		moneyMap[participants[i]].id = participants[i];
	}
}

bool cmp(const st& a,const st& b) {
	return a.amount < b.amount;
}

void makeAnsMap() {
	std::sort(moneyMap, moneyMap + N, cmp);
	for (int i = 0; i < N; ++i) {
		std::cout << moneyMap[i].amount << " " << moneyMap[i].id << " " << std::endl;
	}

	int minusIndex = 0, plusIndex = -1;
	while (moneyMap[++plusIndex].amount < 0);

	while (minusIndex < plusIndex) {
		
	}


	std::cout << std::endl;
}


int main() {
	freopen("calculateTestData.txt", "r", stdin);
	while (1) {
		//init
		memset(moneyMap, 0, sizeof(moneyMap));
		//input
		//input data : N , M, for 1~M : Amount, Payer, ParticipantsNumber PN , for 1~PN : Participants 
		std::cin >> N;
		if (N == 0) break;
		std::cin >> M;
		for (int i = 0; i < M; ++i) {
			std::cin >> amount >> payer >> pn;
			std::cout << "payer : " << payer << " participants : ";
			for (int j = 0; j < pn; ++j) {
				//TODO : map 을 사용하여 id 무작위로 받았을 시 (1, 10, 11) 에도 (0,1,2) 으로 매핑 할 수 있도록 한다. java : hashmap 사용
				std::cin >> participants[j];
				std::cout << participants[j];
			}
			std::cout << std::endl;
			makeMoneyMap();
		}
		makeAnsMap();	


	}
	return 0;
}