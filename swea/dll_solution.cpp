#define MAX_NODE 10000

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	head = getNode(0);
}

void addNode2Head(int data)
{
	Node* new_node = getNode(data);
	new_node->next = head->next;
	if (head->next != nullptr)
		head->next->prev = new_node;
	head->next = new_node;
	new_node->prev = head;	
}

void addNode2Tail(int data)
{
	Node* end_node = head;
	while (end_node->next != nullptr)
		end_node = end_node->next;
	Node* new_node = getNode(data);
	end_node->next = new_node;
	new_node->prev = end_node;
}

void addNode2Num(int data, int num)
{
	Node* new_node = getNode(data);
	Node* node_ptr = head;
	for (int i = 0; i < num - 1; i++) {
		if (node_ptr->next == nullptr) {			
			break;
		}
		node_ptr = node_ptr->next;
	}
	if (node_ptr->next != nullptr) {		
		new_node->next = node_ptr->next;
		node_ptr->next->prev = new_node;
	}
	new_node->prev = node_ptr;
	node_ptr->next = new_node;
}

int findNode(int data)
{
	Node* node_ptr = head;
	int rtn = 1;
	while (node_ptr->next != nullptr && node_ptr->next->data != data) {
		node_ptr = node_ptr->next;
		rtn++;
	}
	
	return rtn;
}

void removeNode(int data)
{
	Node* node_ptr = head;
	while (node_ptr->next != nullptr && node_ptr->next->data != data)
		node_ptr = node_ptr->next;

	if (node_ptr->next != nullptr) {
		node_ptr->next = node_ptr->next->next;	
		if (node_ptr->next != nullptr)
			node_ptr->next->prev = node_ptr;
	}	
}

int getList(int output[MAX_NODE])
{
	int idx = 0;
	Node* node_ptr = head;
	while (node_ptr->next != nullptr) {
		output[idx++] = node_ptr->next->data;
		node_ptr = node_ptr->next;
		//printf("idx:%d\n",idx-1);
	}
	return idx;
}

int getReversedList(int output[MAX_NODE])
{
	int idx = 0;
	Node* node_ptr = head;
	while (node_ptr->next != nullptr)
		node_ptr = node_ptr->next;	
	while (node_ptr->prev != nullptr) {
		output[idx++] = node_ptr->data;
		node_ptr = node_ptr->prev;		
		//printf("idx:%d\n", idx - 1);
	}
	return idx;
}