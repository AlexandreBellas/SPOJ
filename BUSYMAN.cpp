#include <bits/stdc++.h>
using namespace std;

typedef struct {
	int start;
	int finish;
} tarefa;

int T, N;
tarefa t[100007];

bool comparador(tarefa a, tarefa b){
	return a.finish < b.finish;
}

int guloso(){
	int anterior = t[1].finish;
	int resp = 1;
	for(int i = 2; i <= N; i++){
		if(t[i].start >= anterior){
			resp++;
			anterior = t[i].finish;
		}
	}
	return resp;
}

int main(){
	cin >> T;
	while(T--){
		t[0].start = t[0].finish = 0;
		cin >> N;
		for(int i = 1; i <= N; i++){
			cin >> t[i].start >> t[i].finish;
			//cout << t[i].start << " " << t[i].finish << endl;
		}

		sort(t+1, t+N+1, comparador);

		cout << guloso() << endl;
		getchar();
	}

	return 0;
}