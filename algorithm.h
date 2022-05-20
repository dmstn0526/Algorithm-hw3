#include <stdio.h>

int number; //노드의 수
int a[100][100]; //배열
bool visited[] = { 0 }; //이미 방문한 노드(정점) 넣는 변수
int dist[100]; // 거리

//최소거리를 가지는 정점을 반환
int getmin(int dist[], bool visited[]) {
	int min = 1000000; //충분히 큰 1000000으로 계산 (INF를 1000000으로 계산하였다.)
	int k = 0;
	for (int i = 0; i < number; i++) {
		if (dist[i] < min && !visited[i]) { //방문하지 않은 노드 중 현재 min값보다 더 작은값이 있다면
			min = dist[i]; //min에 그 값을 갱신
			k = i; //그때의 정점
		}
	}
	return k; //정점 반환
}

//다익스트라 수행 함수 
void dijkstra(int start){ //시작 정점(입력받은 start로 부터) 다른 정점으로 가는 최소 비용을 구함
	
	for (int i = 0; i < number; i++) {
		dist[i] = a[start][i];
		/*dist배열은 결과적으로 가지는 최소 비용이 담김
		시작점으로 부터 출발해 모든 경로의 비용을 담음*/
	} 
	visited[start] = true; //시작점 방문 처리

	for (int i = 0; i < number - 2; i++) { 
		int c = getmin(dist, visited); //현재 방문하지 않은 노드 중에서 최소 비용을 가지는 노드의 값을 가져옴
		visited[c] = true; //그 노드 방문처리
		for (int j = 0; j < number; j++) {
			if (!visited[j]) {//현재 노드를 방문하지 않았으면
				if (dist[c] + a[c][j] < dist[j]) {
					/*현재 가진 그 노드까지의 최소 비용에서 그 노드를 거쳐 인접한 노드로 가는 비용을 더한 값이
					현재 그 노드로 가는 최소 비용보다 작다면 갱신*/
					dist[j] = dist[c] + a[c][j];
				}
			}
		}
	}
}

int main(void) {
	//노드의 수를 입력 받고
	printf("노드의 수는 : ");
	scanf_s("%d", &number);

	//matrix를 입력 받는다
	printf("matrix 입력\n");
	for (int i = 0; i < number; i++) { //입력한 노드의 수만큼
		for (int j = 0; j < number; j++)
		{
			scanf_s("%d", &a[i][j]); //a[][]배열에 matrix 입력
		}
	}
	printf("\n");

	int start;
	printf("시작 노드 : "); //시작노드를 입력하면 해당 노드에서 다른 노드로의 최단 거리를 구할 수 있음
	scanf_s("%d", &start);
	dijkstra(start);
	for (int i = 0; i < number; i++) {
		printf("%d ", dist[i]);
	}
}
