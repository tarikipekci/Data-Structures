#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10
#define QUEUE_SIZE 50

struct tree {
    struct tree *left;
    struct tree *right;
    int data;
};

typedef struct priorityQueue {
    int A[QUEUE_SIZE + 1];
    int cnt;
} pqueue;

typedef struct tree *btree;

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

typedef struct {
    int cnt;
    Node *top;
} stack;

typedef struct {
    int top;
    int data[STACK_SIZE];
} arrayStack;

typedef struct {
    int cnt;
    struct node *front;
    struct node *rear;
} queue;

void Initialize(queue *q) {
    q->cnt = 0;
    q->front = q->rear = NULL;
}

int isFull(queue *q) {
    if (q->cnt == QUEUE_SIZE)
        return 1;
    else
        return 0;
}

int isEmpty(queue *q) {
    if (q->cnt == 0)
        return 1;
    else
        return 0;
}

void Enqueue(queue *q, int x) {
    if (isFull(q))
        printf("Queue is full!!");
    else {
        Node *temp = (Node *) malloc(sizeof(Node));
        temp->data = x;
        temp->next = NULL;
        if (isEmpty(q))
            q->front = q->rear = temp;
        else {
            q->rear->next = temp;
            q->rear = temp;
        }
        q->cnt++;
    }
}

int Dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!!");
        return -1;
    } else {
        int x = q->front->data;
        struct node *temp = q->front;
        q->front = q->front->next;
        free(temp);
        q->cnt--;
        return x;
    }
}

void EnqueueArray(queue *q, int x) {
    if (isFull(q)) {
        printf("Queue is full!!");
    } else {
        q->rear++;
        q->cnt++;

        if (q->rear == QUEUE_SIZE)
            q->rear = 0;

    }
}

Node *AddFront(Node *head, int x) {
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = x;
    temp->next = head;
    head = temp;

    return head;
}

struct node *AddLast(Node *head, int x) {

    struct node *temp = (struct node *) malloc(sizeof(struct node));

    temp->data = x;
    temp->next = NULL;

    if (head == NULL)
        head = temp;

    else {
        struct node *last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = temp;
    }

    return head;
}

Node *DeleteNode(Node *head, int x) {
    Node *temp;

    if (head == NULL) {
        printf("There is no any node of list!!\n");
    }

    if (head->data == x) {
        temp = head;
        head = temp->next;
        free(temp);
    }

    if (head != NULL) {
        temp = head;

        while (temp->next != NULL && temp->next->data != x) {
            temp = temp->next;
            if (temp->next == NULL) {
                return head;
            }
            if (x == temp->next->data) {
                Node *deleted = temp->next;
                temp->next = deleted->next;
                free(deleted);
            }
        }
    }
    return head;
}

void PrintList(Node *head) {

    if (head == NULL)
        printf("List is empty...\n");

    else {
        while (head != NULL) {
            printf("%d\t", head->data);
            head = head->next;
        }
    }
    printf("\n");
}

void CountNodesOfList(Node *head) {
    if (head == NULL) {
        printf("Number of nodes is = 0\n");
    } else {
        int counter = 0;

        while (head != NULL) {
            head = head->next;
            counter++;
        }
        printf("Number of nodes is = %d (Computed by Iterative function!)\n", counter);
    }
}

int CountRecursive(Node *head) {
    if (head == NULL)
        return 0;
    else {
        return 1 + CountRecursive(head->next);
    }
}

Node *DestroySingleLinkedList(Node *head) {
    Node *temp = head;

    while (head != NULL) {
        head = head->next;
        free(temp);
        temp = head;
    }
    return head;
}

Node *DestroySingleLinkedListRecursive(Node *head) {
    Node *temp = head;

    if (head == NULL)
        return NULL;

    else {
        DestroySingleLinkedListRecursive(head->next);
        free(head);
    }
    return head;
}

Node *AddFrontForDLL(Node *head, int x) {
    struct node *temp = (Node *) malloc(sizeof(Node));

    temp->data = x;
    temp->next = head;
    temp->prev = NULL;

    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;

    return head;
}

Node *AddLastOfDLL(Node *head, int x) {
    struct node *temp = (Node *) malloc(sizeof(Node));

    temp->data = x;
    temp->next = NULL;

    if (head == NULL) {
        temp->prev = NULL;
        head = temp;
    } else {
        Node *last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        temp->prev = last;
        last->next = temp;
    }
    return head;
}

Node *DeleteNodeOfDLL(Node *head, int x) {
    Node *temp;

    if (head == NULL) {
        printf("There is no any node of list!!\n");
    }

    if (head->data == x) {
        temp = head;
        head = temp->next;
        head->prev = NULL;
        free(temp);
    }

    if (head != NULL) {
        temp = head;

        while (temp->next != NULL && temp->next->data != x) {
            temp = temp->next;
            if (temp->next == NULL) {
                return head;
            }
            temp->prev->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
                free(temp);
            }
        }
        return head;
    }
}

int CheckExistingOfValue(Node *head, int value) {

    Node *temp = head;

    if (head->data == value)
        return 1;

    while (temp != NULL && temp->data != value) {
        head = head->next;

        if (head->data == value)
            return 1;
    }
    return 0;
}

Node *AddFrontForCLL(Node *head, int x) {
    Node *temp = (Node *) malloc(sizeof(Node));

    temp->data = x;
    if (head == NULL) {
        temp->next = temp;
        head = temp;
    } else {
        temp->next = head;
        Node *last = head;

        while (last->next != head) {
            last = last->next;
        }
        last->next = temp;
        head = temp;
    }
    return head;
}

Node *AddLastForCLL(Node *head, int x) {
    Node *temp = (Node *) malloc(sizeof(Node));

    temp->data = x;

    if (head == NULL) {
        temp->next = temp;
        head = temp;
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        Node *newNode = (Node *) malloc(sizeof(Node));
        temp->next = newNode;
        newNode->next = head;
        newNode->data = x;
    }
    return head;
}

void PrintCLL(Node *head) {
    Node *temp = head;


    while (temp->next != head) {
        printf("%d\n", temp->data);
        temp = temp->next;

        if (temp->next == head) {
            printf("%d\n", temp->data);
        }
    }
}

void InitializeStack(stack *stk) {
    stk->cnt = 0;
    stk->top = NULL;
}

void Push(stack *stk, int c) {
    if (stk->cnt == STACK_SIZE)
        printf("Stack is full!\n");
    else {
        Node *temp = (Node *) malloc(sizeof(Node));

        temp->data = c;
        temp->next = stk->top;
        stk->top = temp;
        stk->cnt++;
    }
}

int Pop(stack *stk) {
    if (stk->cnt == 0) {
        printf("Stack is empty!\n");
        return -100;
    } else {
        int x = stk->top->data;
        Node *temp = stk->top;
        stk->top = stk->top->next;
        free(temp);
        stk->cnt--;
        return x;
    }
}

void Reset(arrayStack *stk) {
    stk->top = -1;
}

void PushArray(arrayStack *stk, int c) {
    if (stk->top == STACK_SIZE) {
        printf("Stack is full!");
    } else {
        stk->top++;
        stk->data[stk->top] = c;
    }
    stk->data[++stk->top] = c;
}

int PopArray(arrayStack *stk) {
    if (stk->top == -1) {
        printf("Stack is empty!");
        return -100;
    } else {
        int x = stk->data[stk->top];
        stk->top--;
        return x;
    }
}

btree NewNode(btree root, int data) {

    if (root == NULL) {
        btree p = (btree) malloc(sizeof(btree));
        p->data = data;
        p->left = p->right = NULL;
        return p;
    }
    if (root->data < data) {
        root->right = NewNode(root->right, data);
    } else if (root->data > data) {
        root->left = NewNode(root->left, data);
    }
    return root;
}

btree Insert(btree root, int x) {
    if (root == NULL) {
        root = NewNode(root, x);
    } else {
        if (x < root->data) {
            root->left = Insert(root->left, x);
        } else if (x > root->data)
            root->right = Insert(root->right, x);
        else
            return root;
    }
    return root;
}

void InOrder(btree root) {
    if (root != NULL) {
        InOrder(root->left);
        printf("%d\t", root->data);
        InOrder(root->right);
    }
}

void PreOrder(btree root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(btree root) {
    if (root != NULL) {
        PreOrder(root->left);
        PreOrder(root->right);
        printf("%d\t", root->data);
    }
}

int FindLeafs(btree root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return FindLeafs(root->left) + FindLeafs(root->right);
}

int FindParentNodes(btree root) {

    if (root == NULL)
        return 0;
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL) ||
        (root->left != NULL && root->right != NULL)) {
        return 1;
    }

}

int FindBiggestNumber(btree root) {
    if (root == NULL)
        return 0;

    while (root->right != NULL)
        root = root->right;

    return root->data;
}

int FindBiggestNumberRecursive(btree root) {
    if (root == NULL)
        return 0;

    if (root->right != NULL) {
        FindBiggestNumberRecursive(root->right);
        root = root->right;
    }
    return root->data;
}

int FindH(btree root) {

    if (root == NULL)
        return -1;

    int leftValue = FindH(root->left);
    int rightValue = FindH(root->right);


    if (leftValue >= rightValue)
        return leftValue + 1;
    else
        return rightValue + 1;
}

Node *ExamQuestion(Node *head, Node *head2) {
    head2->next = NULL;
    head2->prev = NULL;

    while (head->next != NULL) {
        head2->data = head->data;
        head2 = head2->prev;
        head = head->next;
        printf("%d", head2->data);
    }
    return head2;
}

int SubtractMin(struct node *head) {
    int minValue = head->data;
    Node *temp = head;

    while (temp != NULL) {
        if (minValue > temp->data)
            minValue = temp->data;
        temp = temp->next;
    }
    temp = head;

    while (temp != NULL) {
        temp->data -= minValue;
        temp = temp->next;
    }
    return minValue;
}

void AddSumOfFirstAndLastElementToEnd(Node *head) {
    Node *temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    Node *addedNode = (Node *) malloc(sizeof(Node));
    temp->next = addedNode;
    addedNode->next = head;
    addedNode->data = temp->data + head->data;
}

void MirrorOfTree(btree root) {
    if (root == NULL || root->left == root->right)
        return;
    struct node *temp;
    temp = (struct node *) root->left;
    root->left = root->right;
    root->right = (struct tree *) temp;
    MirrorOfTree(root->left);
    MirrorOfTree(root->right);
}

void SwapEvensOdds(queue q1, queue q2, queue q3) {

    while (!isEmpty(&q1)) {
        int x = Dequeue(&q1);
        if (x % 2 == 0)
            Enqueue(&q2, x);

        else
            Enqueue(&q3, x);
    }
}

void PrintQueueElements(queue q) {
    if (q.front == NULL) {
        printf("Queue is empty!");
        return;
    } else {
        while (!isEmpty(&q)) {
            int x = Dequeue(&q);
            printf("%d\t", x);
        }
    }
}

void PrintReversed(Node *head) {
    if (head == NULL)
        return;
    PrintReversed(head->next);
    printf("%d\t", head->data);
}

int FindNodesWithOnlyLeftChild(btree root) {
    if (root == NULL)
        return 0;
    if (root->left != NULL && root->right == NULL)
        return 1;
    FindNodesWithOnlyLeftChild(root->left);
    FindNodesWithOnlyLeftChild(root->right);
    return FindNodesWithOnlyLeftChild(root->left) + FindNodesWithOnlyLeftChild(root->right);
}

int FindValueOfCertainLevel(btree root, int level) {
    if (root == NULL)
        return 0;
    if (level == 0)
        return root->data;

    return FindValueOfCertainLevel(root->left, level - 1) + FindValueOfCertainLevel(root->right, level - 1);
}

int FindTheMinimumDataOfTree(btree root) {
    if (root == NULL)
        return 0;
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int FindTheMaximumDataOfTree(btree root) {
    if (root == NULL)
        return 0;
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

void copyOdd(btree root1, btree root2) {
    if (root1 == NULL)
        return;

    if (root1->data % 2 == 1)

        root2 = Insert(root2, root1->data);

    copyOdd(root1->left, root2);
    copyOdd(root1->right, root2);
}

int FindHeightOfTree(btree root) {
    if (root == NULL)
        return -1;
    else {
        int leftHeight;
        int rightHeight;
        leftHeight = FindHeightOfTree(root->left);
        rightHeight = FindHeightOfTree(root->right);
        if (leftHeight > rightHeight) {
            return leftHeight + 1;

        } else
            return rightHeight + 1;
    }
}

int IsBalanced(btree root) {
    int leftH;
    int rightH;

    if (root == NULL)
        return 1;

    leftH = FindHeightOfTree(root->left);
    rightH = FindHeightOfTree(root->right);

    if (abs(leftH - rightH) <= 1 && IsBalanced(root->left) && IsBalanced(root->right))
        return 1;

    return 0;
}

int FindNumberOfParentsWithAtLeastOneChild(btree root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;

    return 1 + FindNumberOfParentsWithAtLeastOneChild(root->left) + FindNumberOfParentsWithAtLeastOneChild(root->right);
}

int FindNumberOfLeaves(btree root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return FindNumberOfLeaves(root->left) + FindNumberOfLeaves(root->right);
}

int NumberOfNodes(btree root) {
    if (root == NULL)
        return 0;

    return 1 + NumberOfNodes(root->left) + NumberOfNodes(root->right);
}

void PrintOddNumbers(btree root) {
    if (root == NULL)
        return;
    else {
        if (root->data % 2 == 1)
            printf("%d\t", root->data);
        PrintOddNumbers(root->left);
        PrintOddNumbers(root->right);
    }
}

int SumOfEvenNumbers(btree root) {
    if (root == NULL)
        return 0;

    btree temp = root->right;
    int sum = 0;

    while (root != NULL) {
        if (root->data % 2 == 0)
            sum += root->data;
        root = root->left;
    }
    while (temp->right != NULL) {
        if (temp->data % 2 == 0)
            sum += temp->data;
        temp = temp->right;
    }

    return sum;
}

void HalfOfItsRightChild(btree root) {
    if (root == NULL)
        return;
    if (root->data * 2 == root->right->data)
        printf("%d", root->data);
    else
        printf("There is no node such that.");
    HalfOfItsRightChild(root->left);
    HalfOfItsRightChild(root->right);
}

int SumOfNodes(btree root) {
    if (root == NULL)
        return 0;
    else
        return root->data + SumOfNodes(root->left) + SumOfNodes(root->right);
}

void InitializePq(pqueue *p) {
    p->cnt = 0;
}

void InsertPq(pqueue *p, int key) {
    if (p->cnt == QUEUE_SIZE)
        printf("Queue is full!");
    else {
        p->cnt++;
        p->A[p->cnt] = key;
        int iter = p->cnt;

        while (iter != 1 && p->A[iter] < p->A[iter / 2]) {
            int temp = p->A[iter];
            p->A[iter] = p->A[iter / 2];
            p->A[iter / 2] = temp;
            iter = iter / 2;
        }
    }
}

void PrintHeapQueue(pqueue *p) {
    if (p->cnt == 0)
        printf("Queue is empty");
    else {
        int i;
        for (i = 1; i <= p->cnt; i++)
            printf("%5d", p->A[i]);
    }
}

void Swap(int *parent, int *child) {
    int temp = *child;;
    *child = *parent;
    *parent = temp;
}

int DeletePq(pqueue *p) {
    if (p->cnt == 0) {
        printf("Queue is empty");
        return -100;
    } else {
        p->A[1] = p->A[p->cnt];
        p->cnt--;
        int iter = 1;

        while (2 * iter <= p->cnt && (p->A[iter] > p->A[2 * iter] || p->A[iter] > p->A[2 * iter + 1])) {
            if (p->A[2 * iter] < p->A[2 * iter + 1]) {
                Swap(&p->A[iter], &p->A[2 * iter]);
                iter = 2 * iter;
            } else {
                Swap(&p->A[iter], &p->A[2 * iter + 1]);
                iter = 2 * iter + 1;
            }
        }
    }
    return 0;
}

btree PrintParentsOfSelectedNode(btree root, int target) {

    if (root == NULL) {
        printf("There is no any node of this tree!");
        return 0;
    }

    if (root->left->data == target || root->right->data == target)
        printf("%d\n", root->data);

    if (PrintParentsOfSelectedNode(root->right, target) && PrintParentsOfSelectedNode(root->left, target))
        printf("%d", root->data);
    return root;
}


int PrintAncestorsOfNode(btree root, int num) {

    if (root == NULL)
        return 0;

    if (root->data == num)
        return 1;

    if (PrintAncestorsOfNode(root->left, num) ||
        PrintAncestorsOfNode(root->right, num)) {

        printf("%d ", root->data);
        return 1;
    } else
        return 0;

}

int InDegree(int a[][3], int v) {
    int i, degree = 0;
    for (i = 0; i < 3; i++)
        degree += a[i][v];
    return degree;
}

int OutDegree(int a[0][3], int v) {
    int i, degree = 0;

    for (i = 0; i < 3; i++)
        degree += a[v][i];

    return degree;
}

int Degree(int v, int n, int a[v][n]) {
    int degree = 0;

    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < n; ++j) {
            degree += a[i][j];
        }
    }
    return degree;
}

int FindMax(btree root) {
    if (root == NULL)
        return 0;


    while (root->right != NULL)
        root = root->right;


    return root->data;
}

void AddMax(btree root, int max) {
    if (root == NULL)
        return;

    else
        root->data += max;

    AddMax(root->left, max);
    AddMax(root->right, max);

}

int main() {
    Node *head = NULL;
    stack n;
    btree root1 = NULL, root2 = NULL;
    pqueue pq1;
    InitializePq(&pq1);

    root1 = Insert(root1, 20);
    root1 = Insert(root1, 10);
    root1 = Insert(root1, 15);
    root1 = Insert(root1, 25);
    root1 = Insert(root1, 4);
    root1 = Insert(root1, 30);
    root1 = Insert(root1, 11);


    AddMax(root1, FindMax(root1));
    InOrder(root1);


    return 0;
}
