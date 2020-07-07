/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/

struct node *q[600];
int front = 0, rear = 0;

void enq(struct node *data)
{
    if(front == 0 && rear == 0)
    {
        front++ ; rear++ ;
        q[front] = data;
    }
    else {
        rear++;
        q[rear] = data;
    }
}

struct node* deq(void)
{
    struct node *res;
    if(front == rear && front != 0)
    {
        res = q[front];
        front = rear = 0;
    }
    else {
        res = q[front];
        front++;
    }
    return res;
}

int sym(int x)
{
    if(x < 0)
        return 1;
    else {
        return 0;
    }
}

void topView(struct node *root) {

    int hd[600][2], hash1[600], hash2[600];
    int x = 0, max = 0;

    for(int i=0;i<600;i++)
    {
        hash1[i] = 0;
        hash2[i] = 0;
    }   

    for(int i=0;i<600;i++)
        for(int j=0;j<2;j++)
            hd[i][j] = 0;

    enq(root);
    struct node *t;
    hd[1][0] = hd[1][1] = 0;

    hash1[0] = root->data;
    hash2[0] = root->data;

    while(front != 0 && rear != 0)
    {
        t = deq();
        if(t->data > max)
            max = t->data;
        x = hd[t->data][0] ? hd[t->data][0] : hd[t->data][1];

        if(t->left != NULL)
        {
            hd[t->left->data][sym(x-1)] = x-1;
            if(!sym(x-1) && hash1[x-1] == 0)
            {
                hash1[x-1] = t->left->data;
            }

            if(sym(x-1) && hash2[abs(x-1)] == 0)
            {
                hash2[abs(x-1)] = t->left->data;
            }
            enq(t->left);
        }

        if(t->right != NULL)
        {
            hd[t->right->data][sym(x+1)] = x+1;
            if(!sym(x+1) && hash1[x+1] == 0)
            {
                hash1[x+1] = t->right->data;
            }

            if(sym(x+1) && hash2[abs(x+1)] == 0)
            {
                printf("sss");
                hash2[abs(x+1)] = t->right->data;
            }
            enq(t->right);
        }
    }

    for(int i=max;i>=1;i--)
    {
        if(hash2[i] != 0)
            printf("%d ",hash2[i]);
    }
    for(int i=0;i<max;i++)
    {
        if(hash1[i] != 0)
            printf("%d ",hash1[i]);
    }
}
