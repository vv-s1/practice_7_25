#include"list.h"

//������
int main()
{
	DoublyLinkedList list1;
	DoublyLinkedList list2;
	initList(&list1);//��ʼ������list1
	initList(&list2);//��ʼ������list2

	insertAtHead(&list1, 1);//��ͷ������1
	insertAtHead(&list1, 2);//��ͷ������2
	insertAtTail(&list1, 3);//��β������3
	insertAtTail(&list1, 4);//��β������4
	insertAtPosition(&list1, 5, 2);//��λ��2����5

	printf("List 1 ���������");
	printList(&list1);//�����������ӡ

	printf("List 1 ���������");
	reversePrintList(&list1);//�����������ӡ

	Node* node = searchNode(&list1, 3);//��������Ϊ3�Ľڵ㲢��ӡ���
	if (node != NULL)
	{
		printf("�ҵ��ڵ㣺%d\n", node->data);
	}
	else
	{
		printf("�ڵ�δ�ҵ�\n");
	}

	deleteNode(&list1, list1.head->next);//ɾ��list1�ĵڶ����ڵ�
	printf("ɾ���ڶ����ڵ��� List 1��");
	printList(&list1);//��ӡ

	insertAtHead(&list2, 10);//��list2�в���ڵ�ͷ������10
	insertAtTail(&list2, 20);//β������20
	printf("List 2 ���������");
	printList(&list2);//�����������ӡ

	mergeLists(&list1, &list2);//�ϲ�list1��list2
	printf("�ϲ��� List 1:");
	printList(&list1);//��ӡ

	sortList(&list1);//��list1��������
	printf("����� List 1 :");
	printList(&list1);//��ӡ

	reverseList(&list1);//����list1
	printf("����� List 1��");
	printList(&list1);//��ӡ

	splitList(&list1, 3, &list2);//�ָ�list1������ָ�Ϊlist1��list2
	printf("�ָ�� List 1��");
	printList(&list1);//��ӡ
	printf("�� List 2:");
	printList(&list2);//��ӡ

	Node* nodeAtIndex = getNodeAt(&list1, 1);
	if (nodeAtIndex != NULL)
	{
		printf("����1���Ľڵ㣺 %d\n", nodeAtIndex->data);
	}
	else
	{
		printf("������Ч\n");
	}

	int* array = toArray(&list1);
	printf("List 1 ת����:");
	for (int i = 0; i < list1.count; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	free(array);

	int arr[] = { 7,8,9 };
	fromArray(&list1, arr, 3);
	printf("�����鹹���� List 1: ");
	printList(&list1);

	saveListToFile(&list1, "List.txt");
	freeList(&list1);

	loadListFromFile(&list1, "List.txt");
	printf("���ļ����ص� List 1: ");
	printList(&list1);

	DoublyLinkedList* clonedList = coloneList(&list1);
	printf("��¡�� LIstanbul��");
	printList(clonedList);
	freeList(clonedList);
	free(clonedList);

	if (hasDouplicates(&list1))
	{
		printf("List 1 ���ظ��ڵ�\n");
		removeDouplicates(&list1);
		printf("ȥ�غ�� List 1��");
		printList(&list1);
	}
	else
	{
		printf("List 1 ���ظ��ڵ�");
	}

	freeList(&list1);//�ͷ�list1�����нڵ��ڴ�
	freeList(&list2);//�ͷ�list2�����нڵ��ڴ�
	return 0;
}