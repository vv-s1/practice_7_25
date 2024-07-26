#include"list.h"

//初始化链表
void initList(DoublyLinkedList* list)
{
	list->head = NULL;//将链表的head成员初始化为NULL
	list->count = 0;//将链表的count成员初始化为0
}

//创建新节点
Node* createNode(int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));//使用malloc函数为新节点分配内存
	newNode->data = data;//将打他赋值给新节点的data成员
	newNode->prev = NULL;//将prev初始化为NULL
	newNode->next = NULL;//将next初始化为NULL
	return newNode;//返回新创建的节点
}

//在链表头部插入节点
void insertAtHead(DoublyLinkedList* list, int data)
{
	Node* newNode = createNode(data);//调用函数创建一个新节点
	if (list->head != NULL)//判断链表是否为空
	{
		list->head->prev = newNode;//如果链表不为空，将头节点的prev指针指向新节点
		newNode->next = list->head;//并将开年新节点的next指针指向当前节点
	}
	list->head = newNode;//将链表的head指针指向新节点，使其成为新的头节点
	list->count++;//链表节点计数count加一
}

//在链表尾部插入节点
void insertAtTail(DoublyLinkedList* list, int data)
{
	Node* newNode = createNode(data);//调用函数创建一个新节点
	if (list->head == NULL)//判断链表是否为空
	{
		list->head = newNode;//如果链表为空，将链表的head指针指向新节点
	}
	else//否则
	{
		Node* temp = list->head;
		while (temp->next != NULL)//遍历链表，找到最后一个节点
		{
			temp = temp->next;
		}
		temp->next = newNode;//将next指针指向新节点
		newNode->prev = temp;//并将新节点的prev指针指向该节点
	}
	list->count++;//链表节点计数count加一
}

//在指定的位置插入节点
void insertAtPosition(DoublyLinkedList* list, int data, int position)
{
	if (position<0 || position>list->count)//如果插入位置无效(小于0或大于链表长度)
	{
		printf("插入位置无效\n");//打印错误信息
		return;//返回
	}
	if (position == 0)//如果插入位置为0
	{
		insertAtHead(list, data);//调用函数在头部插入新节点
		return;//返回
	}
	if (position == list->count)//如果擦汗如的位置等于链表长度
	{
		insertAtHead(list, data);//条用函数在链表的尾部插入新节点
		return;//返回
	}
	Node* newNode = createNode(data);//否则调用函数，创建一个新节点
	Node* temp = list->head;

	for (int i = 0; i < position - 1; i++)//遍历链表，找到插入位置的前一个节点
	{
		temp = temp->next;
	}
	newNode->next = temp->next;//将新节点插入到指定位置，并调整相邻节点的指针
	newNode->prev = temp;
	temp->next->prev = newNode;
	temp->next = newNode;
	list->count++;//链表节点计数count加一
}

//正向遍历链表
void printList(DoublyLinkedList* list)
{
	Node* temp = list->head;
	while (temp != NULL)//遍历链表
	{
		printf("%d ", temp->data);//打印每个节点的数据，直到链表结束
		temp = temp->next;
	}
	printf("\n");//打印完毕后，换行
}

//反向遍历链表
void reversePrintList(DoublyLinkedList* list)
{
	Node* temp = list->head;//初始化一个临时指针temp，指向链表的头指针
	if (temp == NULL)//判断链表是否为空
	{
		return;//如果为空，直接返回
	}
	while (temp->next != NULL)//通过循环遍历，扎到链表的尾节点(temp->next为NULL的节点)
	{
		temp = temp->next;
	}
	while (temp != NULL)//从尾节点开始，反向遍历链表，直到到达头节点(temp为NULL)
	{
		printf("%d ", temp->data);//并打印每个节点的数据
		temp = temp->prev;
	}
	printf("\n");//遍历结束，打印换行符
}

//查找节点
Node* searchNode(DoublyLinkedList* list, int key)
{
	Node* temp = list->head;
	while (temp != NULL)//遍历链表
	{
		if (temp->data == key)//如果找到包含key数据的节点
		{
			return temp;//返回该节点
		}
		temp = temp->next;
	}
	return NULL;//如果未找到，返回NULL
}

//删除节点
void deleteNode(DoublyLinkedList* list, Node* delNode)
{
	if (list->head == NULL || delNode == NULL)//如果链表为空或要删除的节点为空
	{
		return;//直接返回
	}
	if (list->head == delNode)//如果删除的节点是头节点
	{
		list->head = delNode->next;//将链表的head指针指向下一个节点
	}
	if (delNode->next != NULL)//调整要删除节点的下一个节点，使其绕过要删除的节点
	{
		delNode->next->prev = delNode->prev;
	}
	if (delNode->prev != NULL)//调整要删除的前一个节点，使其绕过要删除的节点
	{
		delNode->prev->next = delNode->next;
	}
	free(delNode);//释放要删除节点的内存
	list->count--;//链表节点计数count减一
}

//合并两个链表
void mergeLists(DoublyLinkedList* list1, DoublyLinkedList* list2)
{
	if (list1->head == NULL)//检查list1是否为空
	{
		list1->head = list2->head;//如果list1为空，将list1的头指针指向list2的头指针
		list1->count = list2->count;//并更新list1的节点计数为list2的节点计数
		return;//返回
	}
	if (list2->head == NULL)//检查list2是否为空
	{
		return;//如果list2为空，直接返回，没有节点需要合并
	}
	Node* temp = list1->head;
	while (temp->next != NULL)//遍历list1找到最后一个节点
	{
		temp = temp->next;
	}
	temp->next = list2->head;//将list1的最后一个节点的next指针指向list2的头节点
	list2->head->prev = temp;//并将list2头节点的prev指针指向list1的最后一个节点
	list1->count += list2->count;//更新list1的节点计数
}

//链表排序
void sortList(DoublyLinkedList* list)
{
	if (list->head == NULL || list->head->next == NULL)//检查链表是否能为空或只有一个节点
	{
		return;//直接返回，因为已经是有序的
	}
	Node* sorted = NULL;//初始化一个指针sorted为NULL，用于指向已经排序的部分
	Node* current = list->head;//初始化一个指针current，指向链表的头节点
	while (current != NULL)//遍历链表，将每个节点插入到已经排序部分的合适位置
	{
		Node* next = current->next;//保存当前节点的下一个节点指针
		current->prev = current->next = NULL;//清空当前节点的前后指针，准备插入到已排序部分
		if (sorted == NULL)//如果已排序部分为空
		{
			sorted = current;//将当前节点设为已排序部分的头节点
		}
		else if (sorted->data >= current->data)//如果当前节点的数据小于等于已排序部分的头节点数据
		{
			current->next = sorted;//将当前节点的next指针指向已排序部分的头节点
			sorted->prev = current;//将已排序部分头节点的prev指针指向当前节点
			sorted = current;//更新已排序部分的头节点为当前节点
		}
		else
		{
			Node* temp = sorted;//初始化一个指针temp，指向已排序部分的头节点
			while (temp->next != NULL && temp->next->data < current->data)//通过循环遍历已排序部分，找到第一个数据大于或等于当前节点数据的位置
			{	//确保位置不会越界			//继续移动，直到找到合适的位置
				temp = temp->next;
			}
			current->next = temp->next;//将当前节点的next指针指向temp的下一个节点
			if (temp->next != NULL)//如果temp的下一个节点不为空
			{
				temp->next->prev = current;//jiangprev指针指向当前节点
			}
			temp->next = current;//将temp的next指针指向当前节点
			current->prev = temp;//将当前节点的prev指针指向temp

		}
		current = next;//移到下一个节点
	}
	list->head = sorted;//将list->head指针指向已排序部分的头节点
}

//逆序链表
void reverseList(DoublyLinkedList* list)
{
	Node* temp = NULL;//初始化指针temp用于临时存储
	Node* current = list->head;//初始化指针current用于遍历链表
	while (current != NULL)//遍历链表并交换指针
	{
		temp = current->prev;//保存当前节点的prev指针
		current->prev = current->next;//将当前节点的prev指针指向next指针，实现反转
		current->next = temp;//将当前节点的next的指针指向temp
		current = current->prev;//移到下一个节点
	}
	if (temp != NULL)//如果temp不为空，表示链表不为空
	{
		list->head = temp->prev;//更新链表的头指针
	}
}

//分割链表
void splitList(DoublyLinkedList* list, int position, DoublyLinkedList* newList)
{
	if (position <= 0 || position >= list->count)//检查分割位置是否有效，如果分割位置小于等于0或大于等于链表长度
	{
		printf("分割位置无效\n");//打印错误信息
		return;//返回
	}
	Node* temp = list->head;
	for (int i = 0; i < position - 1; i++)//遍历链表扎到分割点的前一个节点
	{
		temp = temp->next;
	}
	newList->head = temp->next;//将链表的头指针指向分割点的下一个节点
	newList->head->prev = NULL;//将新链表头节点的prev指针设为NULL
	temp->next = NULL;//将原链表的分割点的next指针设为NULL
	newList->count = list->count - position;//更新新链表的节点计数
	list->count = position;//更新原链表的节点计数
}

//通过索引访问节点
Node* getNodeAt(DoublyLinkedList* list, int index)
{
	if (index < 0 || index >= list->count)//检查索引是否有效，如果索引小于0或大于等于链表长度
	{
		printf("索引无效\n");//打印错误信息
		return NULL;//返回NULL
	}
	Node* temp = list->head;
	for (int i = 0; i < index; i++)//遍历链表找到索引节点--
	{
		temp = temp->next;
	}
	return temp;//返回找到的节点
}

//链表转数组
int* toArray(DoublyLinkedList* list)
{
	int* array = (int*)malloc(list->count * sizeof(int));//使用malloc函数为数组分配足够的内存空间，大小为链表节点数量乘以int的大小
	Node* temp = list->head;
	for (int i = 0; i < list->count; i++)//遍历链表，将每个节点的数据填充到数组中
	{
		array[i] = temp->data;
		temp = temp->next;
	}
	return array;//返沪节点指针
}

//从数组构建链表
void fromArray(DoublyLinkedList* list, int* array, int size)
{
	for (int i = 0; i < size; i++)//遍历数组
	{
		insertAtTail(list, array[i]);//将每个元素插入到链表的尾部
	}
}

//保存链表到文件功能
void saveListToFile(DoublyLinkedList* list, const char* filename)
{
	FILE* file = fopen(filename, "w");//打开一个文件filename进行写操作
	if (file == NULL)//如果文件无法打开
	{
		printf("无法打开文件 %s\n", filename);//打印错误信息
		return;//并返回
	}
	Node* temp = list->head;
	while (temp != NULL)//使用zhizhentemp遍历链表的每个节点
	{
		fprintf(file, "%d ", temp->data);//将每个节点的数据写入文件
		temp = temp->next;
	}
	fclose(file);//关闭文件
}

//从文件中加载链表
void loadListFromFile(DoublyLinkedList* list, const char* filename)
{
	FILE* file = fopen(filename, "r");//打开一个文件filename，进行读操作
	if (file == NULL)//如果文件无法打开
	{
		printf("无法打开文件 %s\n", filename);//打印错误信息
		return;//退出
	}
	initList(list);//初始化链表
	int data;
	while (fscanf(file, "%d", &data) != EOF)//使用fscanf函数从文件中逐行读取整数数据，并存储在变量data中
	{
		insertAtTail(list, data);//每读取一个整数，将其插入到链表的尾部
	}
	fclose(file);//关闭文件
}

//克隆链表
DoublyLinkedList* coloneList(DoublyLinkedList* list)
{
	DoublyLinkedList* newList = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));//为新链表分配内存
	initList(newList);//初始化
	Node* temp = list->head;//初始化指针temp指向原链表的头节点
	while (temp != NULL)//遍历链表的每个节点，将节点的数据插入到新链表的尾部
	{
		insertAtTail(newList, temp->data);//调用函数，确保新链表的节点顺序与原链表相同
		temp = temp->next;
	}
	return newList;//返回新链表
}

//检查链表是否有重复节点
int hasDouplicates(DoublyLinkedList* list)
{
	Node* temp1 = list->head;//temp1初始化为链表头节点
	while (temp1 != NULL)//外层循环遍历每个节点，使用指针temp1遍历链表的每个节点
	{
		Node* temp2 = temp1->next;//temp2初始化为temp1的下一个节点
		while (temp2 != NULL)//内层循环检查重复节点，内层循环检查从temp2开始到链表末尾的每个节点
		{
			if (temp1->data == temp2->data);//如果temp1的数据等于temp2的数据
			{
				return 1;//返回1，存在重复节点
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return 0;//如果遍历结束都没有发现重复，返回0，无重复节点 
}

//删除链表中重复的节点
void removeDouplicates(DoublyLinkedList* list)
{
	Node* temp1 = list->head;//temp1初始化为链表头节点
	while (temp1 != NULL && temp1->next != NULL)//使用指针temp1遍历链表的每个节点，只要temp1不是最后一个节点就继续循环
	{
		Node* temp2 = temp1;
		while (temp2->next != NULL)//使用temp2从temp1开始遍历
		{
			if (temp1->data == temp2->next->data)//判断temp1的数据和temp2的下一个节点的数据相同的话，执行删除
			{
				Node* duplicate = temp2->next;//创建一个临时变量duplicate指向temp2->next，以保存要删除的节点
				temp2->next = temp2->next->next;//更新temp2->next指针，使其指向temp2->next->next，跳过重复的节点
				if (temp2->next != NULL)//如果temp2->next不是NULL
				{
					temp2->next->prev = temp2;//更新temp2->next->prev指针，使其指向temp2，修复向前链接
				}
				free(duplicate);//释放重复节点的内存
				list->count--;//减少链表的节点计数list->count--
			}
			else
			{
				temp2 = temp2->next;//继续移动temp22指针到下一个节点
			}
		}
		temp1 = temp1->next;//更新外层循环指针，更新temp1指针，移到下一个节点，继续进行外层循环的下一次迭代
	}
}

//释放链表
void freeList(DoublyLinkedList* list)
{
	Node* temp;
	while (list->head != NULL)//遍历链表，逐个释放每个节点的内存
	{
		temp = list->head;
		list->head = list->head->next;
		free(temp);
	}
	list->count = 0;//清空链表头指针，并将节点计数count设为0
}