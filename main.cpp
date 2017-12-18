#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//#include <bits/stdc++.h>
#include "BTree.h"
#include "BPlusTree.h"
#include "Context.h"

using namespace std;
int main()
{

	/*************************************直接调用 B 的调度使用****************************************/
	/************************************* Direct call B method ****************************************/
	BTree bt;
	//BPlusTree bpt;
    int choice, digit;
    FILE *fp;
    fp = fopen("temp3.txt", "r");
    //  if(fp)printf("hello");
    int a[200];
    for (int i = 0;i<200;i++)
    {
        fscanf(fp,"%d",&a[i]);
    }
   // insertsort(a,0,39999);
    fclose(fp);
//    for(int i =1;i<100;i++)
//       printf("%d\n",a[i]);

    cout<<"3-key 4-point per node\n输入:\n数字1进行插入\n数字零进行删除\n数字2进行查询\n数字3从文件插入\n";
	while(1)
    {
        cin>>choice>>digit;
        if(choice==1)
        {
            bt.insert(digit);
            cout<<"从最顶层到最底层的节点（广度优先）: ";
            bt.level_display();
            cout<<"B树得到的排序结果: ";
            bt.inorder_print();
            cout<<endl<<"总节点数目: ";
            bt.NodeNum_print();
        }
        else if(choice==0)
        {
            bt.del(digit);
            cout<<"从最顶层到最底层的节点（广度优先）: ";
            bt.level_display();
            cout<<"B树得到的排序结果: ";
            bt.inorder_print();
            cout<<endl<<"总节点数目: ";
            bt.NodeNum_print();
        }
        else if(choice==2)
        {
            int query_times = 0;
            bt.query(digit, query_times);
        }
        else if(choice = 3){
            int j = 0;
            for(;j<200;j++){
            bt.insert(a[j]);
            cout<<"从最顶层到最底层的节点（广度优先）: ";
            bt.level_display();
            cout<<"B树得到的排序结果: ";
            bt.inorder_print();
            cout<<endl<<"总节点数目: ";
            bt.NodeNum_print();
            }
        }
        else break;
    }

    return 0;
}

