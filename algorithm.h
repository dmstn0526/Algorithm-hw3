#include <stdio.h>

//�����Լ��� ����
int number; //����� ��
int a[100][100]; //�迭
bool visited[] = { 0 }; //�̹� �湮�� ���(����) �ִ� ����
int dist[100]; // �Ÿ�

//�ּҰŸ��� ������ ������ ��ȯ
int getmin(int dist[], bool visited[]) {
	int min = 1000000; //����� ū 1000000���� ��� (INF�� 1000000���� ����Ͽ���.)
	int k = 0;
	for (int i = 0; i < number; i++) {
		if (dist[i] < min && !visited[i]) { //�湮���� ���� ��� �� ���� min������ �� �������� �ִٸ�
			min = dist[i]; //min�� �� ���� ����
			k = i; //�׶��� ����
		}
	}
	return k; //���� ��ȯ
}

//���ͽ�Ʈ�� ���� �Լ� 
void dijkstra(int start){ //���� ����(�Է¹��� start�� ����) �ٸ� �������� ���� �ּ� ����� ����
	
	for (int i = 0; i < number; i++) {
		dist[i] = a[start][i];
		/*dist�迭�� ��������� ������ �ּ� ����� ���
		���������� ���� ����� ��� ����� ����� ����*/
	} 
	visited[start] = true; //������ �湮 ó��

	for (int i = 0; i < number - 2; i++) { 
		int c = getmin(dist, visited); //���� �湮���� ���� ��� �߿��� �ּ� ����� ������ ����� ���� ������
		visited[c] = true; //�� ��� �湮ó��
		for (int j = 0; j < number; j++) {
			if (!visited[j]) {//���� ��带 �湮���� �ʾ�����
				if (dist[c] + a[c][j] < dist[j]) {
					/*���� ���� �� �������� �ּ� ��뿡�� �� ��带 ���� ������ ���� ���� ����� ���� ����
					���� �� ���� ���� �ּ� ��뺸�� �۴ٸ� ����*/
					dist[j] = dist[c] + a[c][j];
				}
			}
		}
	}
}

int main(void) {
	//����� ���� �Է� �ް�
	printf("����� ���� : ");
	scanf_s("%d", &number);

	//matrix�� �Է� �޴´�
	printf("matrix �Է�\n");
	for (int i = 0; i < number; i++) { //�Է��� ����� ����ŭ
		for (int j = 0; j < number; j++)
		{
			scanf_s("%d", &a[i][j]); //a[][]�迭�� matrix �Է�
		}
	}
	printf("\n");

	int start;
	printf("���� ��� : "); //���۳�带 �Է��ϸ� �ش� ��忡�� �ٸ� ������ �ִ� �Ÿ��� ���� �� ����
	scanf_s("%d", &start);
	dijkstra(start);
	for (int i = 0; i < number; i++) {
		printf("%d ", dist[i]);
	}
}
