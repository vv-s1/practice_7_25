#include"list.h"

//主函数
int main()
{
	DoublyLinkedList list1;
	DoublyLinkedList list2;
	initList(&list1);//初始化链表list1
	initList(&list2);//初始化链表list2

	insertAtHead(&list1, 1);//在头部插入1
	insertAtHead(&list1, 2);//在头部插入2
	insertAtTail(&list1, 3);//在尾部插入3
	insertAtTail(&list1, 4);//在尾部插入4
	insertAtPosition(&list1, 5, 2);//在位置2插入5

	printf("List 1 正向遍历：");
	printList(&list1);//正向遍历并打印

	printf("List 1 反向遍历：");
	reversePrintList(&list1);//反向遍历并打印

	Node* node = searchNode(&list1, 3);//查找数据为3的节点并打印结果
	if (node != NULL)
	{
		printf("找到节点：%d\n", node->data);
	}
	else
	{
		printf("节点未找到\n");
	}

	deleteNode(&list1, list1.head->next);//删除list1的第二个节点
	printf("删除第二个节点后的 List 1：");
	printList(&list1);//打印

	insertAtHead(&list2, 10);//在list2中插入节点头部插入10
	insertAtTail(&list2, 20);//尾部插入20
	printf("List 2 正向遍历：");
	printList(&list2);//正向遍历并打印

	mergeLists(&list1, &list2);//合并list1和list2
	printf("合并后 List 1:");
	printList(&list1);//打印

	sortList(&list1);//对list1进行排序
	printf("排序后 List 1 :");
	printList(&list1);//打印

	reverseList(&list1);//逆序list1
	printf("逆序后 List 1：");
	printList(&list1);//打印

	splitList(&list1, 3, &list2);//分割list1，将其分割为list1和list2
	printf("分割后 List 1：");
	printList(&list1);//打印
	printf("新 List 2:");
	printList(&list2);//打印

	Node* nodeAtIndex = getNodeAt(&list1, 1);
	if (nodeAtIndex != NULL)
	{
		printf("索引1处的节点： %d\n", nodeAtIndex->data);
	}
	else
	{
		printf("索引无效\n");
	}

	int* array = toArray(&list1);
	printf("List 1 转数组:");
	for (int i = 0; i < list1.count; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	free(array);

	int arr[] = { 7,8,9 };
	fromArray(&list1, arr, 3);
	printf("从数组构建的 List 1: ");
	printList(&list1);

	saveListToFile(&list1, "List.txt");
	freeList(&list1);

	loadListFromFile(&list1, "List.txt");
	printf("从文件加载的 List 1: ");
	printList(&list1);

	DoublyLinkedList* clonedList = coloneList(&list1);
	printf("克隆的 LIstanbul：");
	printList(clonedList);
	freeList(clonedList);
	free(clonedList);

	if (hasDouplicates(&list1))
	{
		printf("List 1 有重复节点\n");
		removeDouplicates(&list1);
		printf("去重后的 List 1：");
		printList(&list1);
	}
	else
	{
		printf("List 1 无重复节点");
	}

	freeList(&list1);//释放list1的所有节点内存
	freeList(&list2);//释放list2的所有节点内存
	return 0;
}