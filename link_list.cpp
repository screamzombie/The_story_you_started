#include <iostream>
using namespace std;
struct link_list
{
    int data = 0;           //������
    link_list *next = NULL; //ָ����
};
using link_list_p = link_list *; //�����C++�����

int main()
{
    int number = 10;
    int test[10]{0};
    for (int i = 0; i < 10; i++)
        test[i] = i;
    link_list head;
    link_list_p Ptr = &head; //��Ϊ������ָ��,������������ָ��һ��ͷ�ڵ�
    int t = 0;
    while (number--)
    {
        int temp = test[t];
        t++;
        if (Ptr->next == NULL) //˵��Ҫ��Ҫ�����ڴ���
        {
            Ptr->next = new (link_list); //����ռ�
            Ptr->data = temp;            //��ʱPtr��ָ��Ľڵ������������������
            Ptr = Ptr->next;             //Ptr ָ��Ptr��ָ��Ľڵ��ָ������ָ�����Ƭ�ڴ�ռ�
        }
    }
    /*
        ����Ĵ����������������ģ�����һ������ָ�룬�������ߣ������������ڴ�����ң����һ��
        ����ȥץסÿһ���ӽڵ㣬Ȼ���ٰ��Լ���һ�£���ǰ��һ��֮������ظ����߲���
        ������������������β鿴����
    */
    link_list_p L_Ptr = &head; //����һ����Ϊ�鿴ָ���ָ�룬������ָ��ͷ�ڵ�
    if (L_Ptr->next == NULL)
    {
        cout << Ptr->data << endl; //˵�����һ��ͷ�ڵ㣬��Ȼ��һ���㵫�㻹��˵��������һ������
    }
    else //Ҳ���ǲ���ֻ��һ��ͷ�ڵ�����
    {
        while (L_Ptr->next != NULL) //��������ָ����ָ��Ľڵ��ָ������NULL�Ļ���˵�����滹�������ڵ�
        {
            cout << L_Ptr->data << endl; //���ָ����ָ��Ľڵ�������������
            L_Ptr = L_Ptr->next;         //ָ�����Žڵ�ǰ��
        }
    }

    /*
        ��������Ҫ�ڵ����͵��ĸ��ڵ�֮���ڼ�һ���µĽڵ��ȥ��������Ӧ����ô���أ�
    */
    cout << "���������������ɾ���ڵ�" << endl;
    link_list_p C_Ptr = &head;
    int cnt = 0; //�Ǹ���Ŷ
    while (C_Ptr->next != NULL)
    {
        if (cnt == 2) //����˵����ָ��ָ��������Ҫ���Ǹ��ڵ��ˣ�Ϊʲô����3����Ϊָ��ǰ�����Σ��ʹ�1��3��
        {
            link_list_p T_Ptr = C_Ptr->next; //�ȼ�¼һ�£���Ȼ���¶��˾��Ҳ�������Ķ�����
           // cout << "hello?" << endl;
            C_Ptr->next = new (link_list); //Ȼ��3�ڵ��ָ����Ͳ�ָ��4�ڵ��ˣ�����ָ�����������Ľڵ�
            C_Ptr->next->data = -1;        //��Ϊ�������ģ�����Ϊ�˱�ʾ�������ǽ�����ڵ��������ֵΪ-1
            C_Ptr->next->next = T_Ptr;     //�ѽڵ��ٸ�����
            cnt++;
        }
        else
        {
            cout << C_Ptr->data << endl; //����������������һ����
            C_Ptr = C_Ptr->next;         //ָ��ǰ��Ŷ
            cnt++;
        }
        //��������1
    }
    //��������Ĵ����ٴβ鿴���������Ҫ�²���Ϊʲô���ú���

    L_Ptr = &head; //����һ����Ϊ�鿴ָ���ָ�룬������ָ��ͷ�ڵ�
    if (L_Ptr->next == NULL)
    {
        cout << Ptr->data << endl; //˵�����һ��ͷ�ڵ㣬��Ȼ��һ���㵫�㻹��˵��������һ������
    }
    else //Ҳ���ǲ���ֻ��һ��ͷ�ڵ�����
    {
        while (L_Ptr->next != NULL) //��������ָ����ָ��Ľڵ��ָ������NULL�Ļ���˵�����滹�������ڵ�
        {
            cout << L_Ptr->data << endl; //���ָ����ָ��Ľڵ�������������
            L_Ptr = L_Ptr->next;         //ָ�����Žڵ�ǰ��
        }
    }
    //��һ�����������
    return 0;
}
