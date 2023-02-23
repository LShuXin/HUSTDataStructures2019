//#include "set.h"
//
//#define MAXN 1000
//typedef int ElemType;//默认元素可以用非负整数表示
//typedef int SetName;//默认用根节点的下标作为集合名称
//typedef ElemType SetType[MAXN];
////查找元素所在的集合
//SetName Find(/*一个数组类型*/SetType s,/*一个非负整数，标识一个元素个体*/ElemType x)
//{
////s[x]的值代表了x的父元素（如果非负）、
//    for(; s[x]>=0; x=s[x])
////当s[x]不为零时，说明“下标值”标识了一个集合(即集合名)
//        return x;
//}
//
////集合的并运算
//void Union(SetType s,SetName root1,SetName root2){
////root1,与root2 均为非负整数，各自代表了一个集合
////其实质是数组的下标，不过改下标出存放-1，下标的唯一性区分了集合
//    s[root2]=root1;//这样就不存在root2这个集合，仅剩下root1这一集合
////合并时只需要将一个集合的集合标识中的-1 替换为另一个集合的根标识下表即可
//}