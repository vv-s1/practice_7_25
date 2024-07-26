#include"list.h"

//��ʼ������
void initList(DoublyLinkedList* list)
{
	list->head = NULL;//�������head��Ա��ʼ��ΪNULL
	list->count = 0;//�������count��Ա��ʼ��Ϊ0
}

//�����½ڵ�
Node* createNode(int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));//ʹ��malloc����Ϊ�½ڵ�����ڴ�
	newNode->data = data;//��������ֵ���½ڵ��data��Ա
	newNode->prev = NULL;//��prev��ʼ��ΪNULL
	newNode->next = NULL;//��next��ʼ��ΪNULL
	return newNode;//�����´����Ľڵ�
}

//������ͷ������ڵ�
void insertAtHead(DoublyLinkedList* list, int data)
{
	Node* newNode = createNode(data);//���ú�������һ���½ڵ�
	if (list->head != NULL)//�ж������Ƿ�Ϊ��
	{
		list->head->prev = newNode;//�������Ϊ�գ���ͷ�ڵ��prevָ��ָ���½ڵ�
		newNode->next = list->head;//���������½ڵ��nextָ��ָ��ǰ�ڵ�
	}
	list->head = newNode;//�������headָ��ָ���½ڵ㣬ʹ���Ϊ�µ�ͷ�ڵ�
	list->count++;//����ڵ����count��һ
}

//������β������ڵ�
void insertAtTail(DoublyLinkedList* list, int data)
{
	Node* newNode = createNode(data);//���ú�������һ���½ڵ�
	if (list->head == NULL)//�ж������Ƿ�Ϊ��
	{
		list->head = newNode;//�������Ϊ�գ��������headָ��ָ���½ڵ�
	}
	else//����
	{
		Node* temp = list->head;
		while (temp->next != NULL)//���������ҵ����һ���ڵ�
		{
			temp = temp->next;
		}
		temp->next = newNode;//��nextָ��ָ���½ڵ�
		newNode->prev = temp;//�����½ڵ��prevָ��ָ��ýڵ�
	}
	list->count++;//����ڵ����count��һ
}

//��ָ����λ�ò���ڵ�
void insertAtPosition(DoublyLinkedList* list, int data, int position)
{
	if (position<0 || position>list->count)//�������λ����Ч(С��0�����������)
	{
		printf("����λ����Ч\n");//��ӡ������Ϣ
		return;//����
	}
	if (position == 0)//�������λ��Ϊ0
	{
		insertAtHead(list, data);//���ú�����ͷ�������½ڵ�
		return;//����
	}
	if (position == list->count)//����������λ�õ���������
	{
		insertAtHead(list, data);//���ú����������β�������½ڵ�
		return;//����
	}
	Node* newNode = createNode(data);//������ú���������һ���½ڵ�
	Node* temp = list->head;

	for (int i = 0; i < position - 1; i++)//���������ҵ�����λ�õ�ǰһ���ڵ�
	{
		temp = temp->next;
	}
	newNode->next = temp->next;//���½ڵ���뵽ָ��λ�ã����������ڽڵ��ָ��
	newNode->prev = temp;
	temp->next->prev = newNode;
	temp->next = newNode;
	list->count++;//����ڵ����count��һ
}

//�����������
void printList(DoublyLinkedList* list)
{
	Node* temp = list->head;
	while (temp != NULL)//��������
	{
		printf("%d ", temp->data);//��ӡÿ���ڵ�����ݣ�ֱ���������
		temp = temp->next;
	}
	printf("\n");//��ӡ��Ϻ󣬻���
}

//�����������
void reversePrintList(DoublyLinkedList* list)
{
	Node* temp = list->head;//��ʼ��һ����ʱָ��temp��ָ�������ͷָ��
	if (temp == NULL)//�ж������Ƿ�Ϊ��
	{
		return;//���Ϊ�գ�ֱ�ӷ���
	}
	while (temp->next != NULL)//ͨ��ѭ�����������������β�ڵ�(temp->nextΪNULL�Ľڵ�)
	{
		temp = temp->next;
	}
	while (temp != NULL)//��β�ڵ㿪ʼ�������������ֱ������ͷ�ڵ�(tempΪNULL)
	{
		printf("%d ", temp->data);//����ӡÿ���ڵ������
		temp = temp->prev;
	}
	printf("\n");//������������ӡ���з�
}

//���ҽڵ�
Node* searchNode(DoublyLinkedList* list, int key)
{
	Node* temp = list->head;
	while (temp != NULL)//��������
	{
		if (temp->data == key)//����ҵ�����key���ݵĽڵ�
		{
			return temp;//���ظýڵ�
		}
		temp = temp->next;
	}
	return NULL;//���δ�ҵ�������NULL
}

//ɾ���ڵ�
void deleteNode(DoublyLinkedList* list, Node* delNode)
{
	if (list->head == NULL || delNode == NULL)//�������Ϊ�ջ�Ҫɾ���Ľڵ�Ϊ��
	{
		return;//ֱ�ӷ���
	}
	if (list->head == delNode)//���ɾ���Ľڵ���ͷ�ڵ�
	{
		list->head = delNode->next;//�������headָ��ָ����һ���ڵ�
	}
	if (delNode->next != NULL)//����Ҫɾ���ڵ����һ���ڵ㣬ʹ���ƹ�Ҫɾ���Ľڵ�
	{
		delNode->next->prev = delNode->prev;
	}
	if (delNode->prev != NULL)//����Ҫɾ����ǰһ���ڵ㣬ʹ���ƹ�Ҫɾ���Ľڵ�
	{
		delNode->prev->next = delNode->next;
	}
	free(delNode);//�ͷ�Ҫɾ���ڵ���ڴ�
	list->count--;//����ڵ����count��һ
}

//�ϲ���������
void mergeLists(DoublyLinkedList* list1, DoublyLinkedList* list2)
{
	if (list1->head == NULL)//���list1�Ƿ�Ϊ��
	{
		list1->head = list2->head;//���list1Ϊ�գ���list1��ͷָ��ָ��list2��ͷָ��
		list1->count = list2->count;//������list1�Ľڵ����Ϊlist2�Ľڵ����
		return;//����
	}
	if (list2->head == NULL)//���list2�Ƿ�Ϊ��
	{
		return;//���list2Ϊ�գ�ֱ�ӷ��أ�û�нڵ���Ҫ�ϲ�
	}
	Node* temp = list1->head;
	while (temp->next != NULL)//����list1�ҵ����һ���ڵ�
	{
		temp = temp->next;
	}
	temp->next = list2->head;//��list1�����һ���ڵ��nextָ��ָ��list2��ͷ�ڵ�
	list2->head->prev = temp;//����list2ͷ�ڵ��prevָ��ָ��list1�����һ���ڵ�
	list1->count += list2->count;//����list1�Ľڵ����
}

//��������
void sortList(DoublyLinkedList* list)
{
	if (list->head == NULL || list->head->next == NULL)//��������Ƿ���Ϊ�ջ�ֻ��һ���ڵ�
	{
		return;//ֱ�ӷ��أ���Ϊ�Ѿ��������
	}
	Node* sorted = NULL;//��ʼ��һ��ָ��sortedΪNULL������ָ���Ѿ�����Ĳ���
	Node* current = list->head;//��ʼ��һ��ָ��current��ָ�������ͷ�ڵ�
	while (current != NULL)//����������ÿ���ڵ���뵽�Ѿ����򲿷ֵĺ���λ��
	{
		Node* next = current->next;//���浱ǰ�ڵ����һ���ڵ�ָ��
		current->prev = current->next = NULL;//��յ�ǰ�ڵ��ǰ��ָ�룬׼�����뵽�����򲿷�
		if (sorted == NULL)//��������򲿷�Ϊ��
		{
			sorted = current;//����ǰ�ڵ���Ϊ�����򲿷ֵ�ͷ�ڵ�
		}
		else if (sorted->data >= current->data)//�����ǰ�ڵ������С�ڵ��������򲿷ֵ�ͷ�ڵ�����
		{
			current->next = sorted;//����ǰ�ڵ��nextָ��ָ�������򲿷ֵ�ͷ�ڵ�
			sorted->prev = current;//�������򲿷�ͷ�ڵ��prevָ��ָ��ǰ�ڵ�
			sorted = current;//���������򲿷ֵ�ͷ�ڵ�Ϊ��ǰ�ڵ�
		}
		else
		{
			Node* temp = sorted;//��ʼ��һ��ָ��temp��ָ�������򲿷ֵ�ͷ�ڵ�
			while (temp->next != NULL && temp->next->data < current->data)//ͨ��ѭ�����������򲿷֣��ҵ���һ�����ݴ��ڻ���ڵ�ǰ�ڵ����ݵ�λ��
			{	//ȷ��λ�ò���Խ��			//�����ƶ���ֱ���ҵ����ʵ�λ��
				temp = temp->next;
			}
			current->next = temp->next;//����ǰ�ڵ��nextָ��ָ��temp����һ���ڵ�
			if (temp->next != NULL)//���temp����һ���ڵ㲻Ϊ��
			{
				temp->next->prev = current;//jiangprevָ��ָ��ǰ�ڵ�
			}
			temp->next = current;//��temp��nextָ��ָ��ǰ�ڵ�
			current->prev = temp;//����ǰ�ڵ��prevָ��ָ��temp

		}
		current = next;//�Ƶ���һ���ڵ�
	}
	list->head = sorted;//��list->headָ��ָ�������򲿷ֵ�ͷ�ڵ�
}

//��������
void reverseList(DoublyLinkedList* list)
{
	Node* temp = NULL;//��ʼ��ָ��temp������ʱ�洢
	Node* current = list->head;//��ʼ��ָ��current���ڱ�������
	while (current != NULL)//������������ָ��
	{
		temp = current->prev;//���浱ǰ�ڵ��prevָ��
		current->prev = current->next;//����ǰ�ڵ��prevָ��ָ��nextָ�룬ʵ�ַ�ת
		current->next = temp;//����ǰ�ڵ��next��ָ��ָ��temp
		current = current->prev;//�Ƶ���һ���ڵ�
	}
	if (temp != NULL)//���temp��Ϊ�գ���ʾ����Ϊ��
	{
		list->head = temp->prev;//���������ͷָ��
	}
}

//�ָ�����
void splitList(DoublyLinkedList* list, int position, DoublyLinkedList* newList)
{
	if (position <= 0 || position >= list->count)//���ָ�λ���Ƿ���Ч������ָ�λ��С�ڵ���0����ڵ���������
	{
		printf("�ָ�λ����Ч\n");//��ӡ������Ϣ
		return;//����
	}
	Node* temp = list->head;
	for (int i = 0; i < position - 1; i++)//�������������ָ���ǰһ���ڵ�
	{
		temp = temp->next;
	}
	newList->head = temp->next;//�������ͷָ��ָ��ָ�����һ���ڵ�
	newList->head->prev = NULL;//��������ͷ�ڵ��prevָ����ΪNULL
	temp->next = NULL;//��ԭ����ķָ���nextָ����ΪNULL
	newList->count = list->count - position;//����������Ľڵ����
	list->count = position;//����ԭ����Ľڵ����
}

//ͨ���������ʽڵ�
Node* getNodeAt(DoublyLinkedList* list, int index)
{
	if (index < 0 || index >= list->count)//��������Ƿ���Ч���������С��0����ڵ���������
	{
		printf("������Ч\n");//��ӡ������Ϣ
		return NULL;//����NULL
	}
	Node* temp = list->head;
	for (int i = 0; i < index; i++)//���������ҵ������ڵ�--
	{
		temp = temp->next;
	}
	return temp;//�����ҵ��Ľڵ�
}

//����ת����
int* toArray(DoublyLinkedList* list)
{
	int* array = (int*)malloc(list->count * sizeof(int));//ʹ��malloc����Ϊ��������㹻���ڴ�ռ䣬��СΪ����ڵ���������int�Ĵ�С
	Node* temp = list->head;
	for (int i = 0; i < list->count; i++)//����������ÿ���ڵ��������䵽������
	{
		array[i] = temp->data;
		temp = temp->next;
	}
	return array;//�����ڵ�ָ��
}

//�����鹹������
void fromArray(DoublyLinkedList* list, int* array, int size)
{
	for (int i = 0; i < size; i++)//��������
	{
		insertAtTail(list, array[i]);//��ÿ��Ԫ�ز��뵽�����β��
	}
}

//���������ļ�����
void saveListToFile(DoublyLinkedList* list, const char* filename)
{
	FILE* file = fopen(filename, "w");//��һ���ļ�filename����д����
	if (file == NULL)//����ļ��޷���
	{
		printf("�޷����ļ� %s\n", filename);//��ӡ������Ϣ
		return;//������
	}
	Node* temp = list->head;
	while (temp != NULL)//ʹ��zhizhentemp���������ÿ���ڵ�
	{
		fprintf(file, "%d ", temp->data);//��ÿ���ڵ������д���ļ�
		temp = temp->next;
	}
	fclose(file);//�ر��ļ�
}

//���ļ��м�������
void loadListFromFile(DoublyLinkedList* list, const char* filename)
{
	FILE* file = fopen(filename, "r");//��һ���ļ�filename�����ж�����
	if (file == NULL)//����ļ��޷���
	{
		printf("�޷����ļ� %s\n", filename);//��ӡ������Ϣ
		return;//�˳�
	}
	initList(list);//��ʼ������
	int data;
	while (fscanf(file, "%d", &data) != EOF)//ʹ��fscanf�������ļ������ж�ȡ�������ݣ����洢�ڱ���data��
	{
		insertAtTail(list, data);//ÿ��ȡһ��������������뵽�����β��
	}
	fclose(file);//�ر��ļ�
}

//��¡����
DoublyLinkedList* coloneList(DoublyLinkedList* list)
{
	DoublyLinkedList* newList = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));//Ϊ����������ڴ�
	initList(newList);//��ʼ��
	Node* temp = list->head;//��ʼ��ָ��tempָ��ԭ�����ͷ�ڵ�
	while (temp != NULL)//���������ÿ���ڵ㣬���ڵ�����ݲ��뵽�������β��
	{
		insertAtTail(newList, temp->data);//���ú�����ȷ��������Ľڵ�˳����ԭ������ͬ
		temp = temp->next;
	}
	return newList;//����������
}

//��������Ƿ����ظ��ڵ�
int hasDouplicates(DoublyLinkedList* list)
{
	Node* temp1 = list->head;//temp1��ʼ��Ϊ����ͷ�ڵ�
	while (temp1 != NULL)//���ѭ������ÿ���ڵ㣬ʹ��ָ��temp1���������ÿ���ڵ�
	{
		Node* temp2 = temp1->next;//temp2��ʼ��Ϊtemp1����һ���ڵ�
		while (temp2 != NULL)//�ڲ�ѭ������ظ��ڵ㣬�ڲ�ѭ������temp2��ʼ������ĩβ��ÿ���ڵ�
		{
			if (temp1->data == temp2->data);//���temp1�����ݵ���temp2������
			{
				return 1;//����1�������ظ��ڵ�
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return 0;//�������������û�з����ظ�������0�����ظ��ڵ� 
}

//ɾ���������ظ��Ľڵ�
void removeDouplicates(DoublyLinkedList* list)
{
	Node* temp1 = list->head;//temp1��ʼ��Ϊ����ͷ�ڵ�
	while (temp1 != NULL && temp1->next != NULL)//ʹ��ָ��temp1���������ÿ���ڵ㣬ֻҪtemp1�������һ���ڵ�ͼ���ѭ��
	{
		Node* temp2 = temp1;
		while (temp2->next != NULL)//ʹ��temp2��temp1��ʼ����
		{
			if (temp1->data == temp2->next->data)//�ж�temp1�����ݺ�temp2����һ���ڵ��������ͬ�Ļ���ִ��ɾ��
			{
				Node* duplicate = temp2->next;//����һ����ʱ����duplicateָ��temp2->next���Ա���Ҫɾ���Ľڵ�
				temp2->next = temp2->next->next;//����temp2->nextָ�룬ʹ��ָ��temp2->next->next�������ظ��Ľڵ�
				if (temp2->next != NULL)//���temp2->next����NULL
				{
					temp2->next->prev = temp2;//����temp2->next->prevָ�룬ʹ��ָ��temp2���޸���ǰ����
				}
				free(duplicate);//�ͷ��ظ��ڵ���ڴ�
				list->count--;//��������Ľڵ����list->count--
			}
			else
			{
				temp2 = temp2->next;//�����ƶ�temp22ָ�뵽��һ���ڵ�
			}
		}
		temp1 = temp1->next;//�������ѭ��ָ�룬����temp1ָ�룬�Ƶ���һ���ڵ㣬�����������ѭ������һ�ε���
	}
}

//�ͷ�����
void freeList(DoublyLinkedList* list)
{
	Node* temp;
	while (list->head != NULL)//������������ͷ�ÿ���ڵ���ڴ�
	{
		temp = list->head;
		list->head = list->head->next;
		free(temp);
	}
	list->count = 0;//�������ͷָ�룬�����ڵ����count��Ϊ0
}