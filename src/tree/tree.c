#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

typedef char TreeNodeElemType;











// 1.固定大小的树节点
typedef struct TreeNodeType1 {
    TreeNodeElemType data;
    // 节点实际的孩子数量
    int degree;
    // 这是一棵10度树的节点结构
    struct TreeNodeType1 *children[10];
} TreeNodeType1;










// 2.不固定大小的树节点
typedef struct TreeNodeType2 {
    TreeNodeElemType data;
    // 节点的度，初始默认为零，后序根据实际情况进行调整
    int degree;
    // 以该节点为根的子树的根指针数组，在实际使用过程中使用堆栈空间进行动态调整
    struct TreeNodeType2 *children;
} TreeNodeType2;










// 3.这其实是一颗典型二叉树的节点
typedef struct TreeNodeType3 {
    TreeNodeElemType data;
    struct TreeNodeType3 *first_child;
    struct TreeNodeType3 *next_brother;
} TreeNodeType3;










// 4.这是一个单节点树的节点，每个孩子都只有一个子节点
// 整个树是用数组来实现的
struct TreeNodeType4 {
    TreeNodeElemType data;
    int parent, child;
} tree_instance_of_node_type_4[10 + 1];










// 5.这是一个用数组实现的二叉树的节点
struct TreeNodeType5 {
    TreeNodeElemType data;
    int l_child, r_child;
} tree_instance_of_node_type_5[10 + 1];
// 在定义结构体的同时定义了一个这样结构结构体数组、数组的每一个元素用于存储一个二叉树的节点的"指针"，
// 为了方便按照完全二叉树的规则从一个节点寻找他的左右孩子节点，二叉树结构体数组的大小要比二叉树实际的
// 节点的个数大一，0号元素不使用，二叉树的每一个节点可以通过数组的下标来访问




//struct ChildNode{
//    int listnum;//在ListNode中寻找该节点表示的节点
//    struct ChildNode *nextchild;//同一根节点的另一个子节点
//}
//struct ListNode{
//    ElemType data;//该节点的数据域
//    struct ListNode *parent;//该节点的父节点
//    struct ChildNode *firstchild;//该节点的第一个子节点
//}
//struct ListNode tree[MAXSIZE+1];//树




//struct ChildNode{
//    int listnum;//作为主节点的第几个子节点
//    struct ChildNode *nextchild;//该节点的兄弟节点
//}
//struct ListNode{
//    ElemType data;//节点数据
//    struct ChildNode *firstchild;//该节点第一个孩子
//}
//struct ListNode tree[MAXSIZE+1];
////每个元素作为一个节点，
////每个节点有一连串子节点






// 数组"指针"实现的二叉树，给出两个节点的指针i, j,
// 找出两个节点的最近公共节点
// 输入合法，肯定能找到祖先(至少还有一个根节点)
int common_ancestor_v1(int i, int j)
{
    while (i != j)
    {
        if (i > j)
        {
            i /= 2;
        }
        else
        {
            j /= 2;
        }
    }
    return i;
}









//
//typedef char ElemType;
//typedef struct BiTNode
//{
//    ElemType data;
//    struct BiTNode *lchild,*rchild;
//} BiTNode,*BiTree;
//typedef struct stack
//{
//    BiTree t;
//    int tag;
//} stack;
//
//BiTree Ancestor(BiTree ROOT,BiTNode *p,BiTNode *q)
//{
//    int top=0, i,j,top1;
//    BiTNode *bt=ROOT;
//    stack s[100],s1[100];
//    while(top||bt)
//    {
//        while(bt&&bt!=p&&bt!=q)//bt是当前节点
//        {
//            while(bt)
//            {
//                s[++top].t=bt;
//                bt=bt->lchild;
//            }
//        }
//
//
//        while(top&&s[top].tag==1)//左子树为空，左右子树全部访问完毕
//        {
//            if(s[top].t==p)
//            {
//                for(i=1; i<=top; i++)
//                    s1[i]=s[i];
//                top1=top;
//            }
//            if(s[top].t==q)
//            {
//                for(i=top; i>0; i++)
//                    for(j=top1; j>0; j--)
//                        if(s1[j].t=s[i].t);
//                return s[i].t;
//            }
//            top--;
//        }
//
//
//        //左右子树全部访问完毕
//        //如果栈仍不为空
//        if(top)
//        {
//            s[top].tag=1;
//            bt=s[top].t->rchild;
//        }
//    }
//    return NULL;
//}








// 先序创建二叉树第版本1
typedef char pre_order_bi_tree_create_v1_ElemType;
typedef struct pre_order_bi_tree_create_v1_BiTNode
{
    pre_order_bi_tree_create_v1_ElemType data;
    struct pre_order_bi_tree_create_v1_BiTNode *l_child;
    struct pre_order_bi_tree_create_v1_BiTNode *r_child;
} pre_order_bi_tree_create_v1_BiTNode, *pre_order_bi_tree_create_v1_root, *pre_order_bi_tree_create_v1_p, *pre_order_bi_tree_create_v1_BiTree;

void pre_order_bi_tree_create_v1(pre_order_bi_tree_create_v1_BiTree *root)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '@')
    {
        (*root) = NULL;
    }
    else
    {
        // 分配节点内存空间
        (*root) = (pre_order_bi_tree_create_v1_BiTree)malloc(sizeof(pre_order_bi_tree_create_v1_BiTNode));
        (*root)->data = ch;
        // 递归创建左子树
        pre_order_bi_tree_create_v1(&(*root)->l_child);
        // 递归创建右子树
        pre_order_bi_tree_create_v1(&(*root)->r_child);
    }
}

void perform_pre_order_bi_tree_create_v1() {
    pre_order_bi_tree_create_v1_BiTree tree;
    perform_pre_order_bi_tree_create_v1(&tree);
    return;
}

















// 先序创建二叉树版本2
typedef char pre_order_bi_tree_create_v2_ElemType;
typedef struct pre_order_bi_tree_create_v2_BiTNode
{
    pre_order_bi_tree_create_v2_ElemType data;
    struct pre_order_bi_tree_create_v2_BiTNode *l_child;
    struct pre_order_bi_tree_create_v2_BiTNode *r_child;
} pre_order_bi_tree_create_v2_BiTNode, *pre_order_bi_tree_create_v2_root, *pre_order_bi_tree_create_v2_p, *pre_order_bi_tree_create_v2_BiTree;

pre_order_bi_tree_create_v2_BiTree pre_order_bi_tree_create_v2() {
    pre_order_bi_tree_create_v2_BiTree root;
    char ch;
    scanf("%c", ch);
    if (ch=='@')
    {
        root = NULL;
    }
    else
    {
        root = (pre_order_bi_tree_create_v2_BiTree)malloc(sizeof(pre_order_bi_tree_create_v2_BiTNode));
        root->data = ch;
        root->l_child = pre_order_bi_tree_create_v2();
        root->r_child = pre_order_bi_tree_create_v2();
    }
    return root;
}

void perform_pre_order_bi_tree_create_v2() {
    pre_order_bi_tree_create_v2_BiTree root;
    root = pre_order_bi_tree_create_v2();
}












// 先序创建二叉树版本3(C++)
//typedef char pre_order_bi_tree_create_v3_ElemType;
//typedef struct pre_order_bi_tree_create_v3_BiTNode
//{
//    pre_order_bi_tree_create_v3_ElemType data;
//    struct pre_order_bi_tree_create_v3_BiTNode *l_child;
//    struct pre_order_bi_tree_create_v3_BiTNode *r_child;
//} pre_order_bi_tree_create_v3_BiTNode, *pre_order_bi_tree_create_v3_root, *pre_order_bi_tree_create_v3_p, *pre_order_bi_tree_create_v3_BiTree;
//
//void pre_order_bi_tree_create_v3(pre_order_bi_tree_create_v3_BiTree &root)
//{
//    char ch;
//    scanf("%c", &ch);
//    if (ch == '@')
//    {
//        root = NULL;
//    }
//    else
//    {
//    root = (pre_order_bi_tree_create_v3_BiTree)malloc(sizeof(pre_order_bi_tree_create_v3_BiTNode));
//    root->data = ch;
//    pre_order_bi_tree_create_v3(root->l_child);
//    pre_order_bi_tree_create_v3(root->r_child);
//    }
//}










// 先序创建二叉树版本4
// 已知二叉树的一个按先序遍历输入的字符序列，
// 如abc,,de,g,,f,,, (其中,表示空结点)。
// 请建立二叉树并求二叉树的叶子结点个数。
typedef char pre_order_bi_tree_create_v4_ElemType;
typedef struct pre_order_bi_tree_create_v4_BiTNode
{
    pre_order_bi_tree_create_v4_ElemType data;
    struct pre_order_bi_tree_create_v4_BiTNode *l_child;
    struct pre_order_bi_tree_create_v4_BiTNode *r_child;
} pre_order_bi_tree_create_v4_BiTNode, *pre_order_bi_tree_create_v4_root, *pre_order_bi_tree_create_v4_p, *pre_order_bi_tree_create_v4_BiTree;


char pre_order_bi_tree_create_v4_char_arr[50];
int pre_order_bi_tree_create_v4_leaves_num = 0;
int pre_order_bi_tree_create_v4_leaves_i = 0;
// 在二叉树中，叶子结点数是度为2的节点数加1

pre_order_bi_tree_create_v4_BiTree pre_order_bi_tree_create_v4()
{
    pre_order_bi_tree_create_v4_BiTree tree;
    if (pre_order_bi_tree_create_v4_char_arr[pre_order_bi_tree_create_v4_leaves_i++] == ',')
    {
        tree = NULL;
    }
    else
    {
        tree=(pre_order_bi_tree_create_v4_BiTree)malloc(sizeof(pre_order_bi_tree_create_v4_BiTNode));
        tree->data = pre_order_bi_tree_create_v4_char_arr[pre_order_bi_tree_create_v4_leaves_i - 1];
        tree->l_child = pre_order_bi_tree_create_v4();
        tree->r_child = pre_order_bi_tree_create_v4();
    }
    return tree;
}

void pre_order_bi_tree_create_v4_cal_leaves(pre_order_bi_tree_create_v4_BiTree tree)
{
    if (tree)
    {
        if (tree->l_child == NULL && tree->r_child == NULL)
        {
            pre_order_bi_tree_create_v4_leaves_num++;
        }
        pre_order_bi_tree_create_v4_cal_leaves(tree->l_child);
        pre_order_bi_tree_create_v4_cal_leaves(tree->r_child);
    }
    return;
}


void preform_pre_order_bi_tree_create_v4()
{
    while(~scanf("%s", pre_order_bi_tree_create_v4_char_arr))
    {
        pre_order_bi_tree_create_v4_BiTree tree = NULL;
        tree = pre_order_bi_tree_create_v4();
        pre_order_bi_tree_create_v4_cal_leaves(tree);
        printf("%d", pre_order_bi_tree_create_v4_leaves_num);
    }
}
