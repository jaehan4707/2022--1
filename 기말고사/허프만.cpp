/*
�켱���� ť�� �󵵼��� �����͵�� �־���.
�󵵼��� ������ 2���� �����ؼ� Ʈ���� �̾����.���� �� �ٿ��ٸ� ������.
�������� ���� ū���� �����ʿ� ��.

*/

/*
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;
typedef struct node* node_ptr;
typedef struct node
{
    char symbol;
    int freq;
    node_ptr left;
    node_ptr right;
} node;
struct compare
{
    bool operator()(node_ptr p, node_ptr q)
    {
        return p->freq > q->freq;
    }
};
typedef priority_queue<node_ptr, vector<node_ptr>, compare> PQ;
node_ptr create_node(char Symbol, int freq);
void huffman(int n, PQ& pq);
void encode(node_ptr root, vector<int>& code, map<char, vector<int>>& decoder);
void decode(node_ptr root, node_ptr cnode, string S, int i, vector<char>& ary);
node_ptr inorder(node_ptr root);
node_ptr preorder(node_ptr root);
int n, snum, cnum;
int main()
{
    PQ pq; //�켱����ť����
    string Ary;
    cin >> n; //������ ���� n
    vector<char> x;
    vector<int> y;
    vector<char> cc;
    node_ptr Node = (node_ptr)malloc(sizeof(node)); //�����Ҵ�
    for (int i = 0; i < n; i++)
    {
        char b;
        cin >> b;
        x.push_back(b); //���ڿ� x���ٰ� ���ڸ� �־���.
    }
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        y.push_back(c); //�󵵰��� y�� �־���.
    }
    for (int i = 0; i < n; i++)
    {
        pq.push(create_node(x[i], y[i]));
        // pq.push(Node);
    }

    huffman(n, pq);
    preorder(pq.top());
    cout << endl;
    inorder(pq.top());
    cout << endl;
    cin >> snum;
    vector<int> code;
    map<char, vector<int>> m;
    vector<int> ary;
    for (int i = 0; i < snum; i++)
    {
        cin >> Ary;
        encode(pq.top(), code, m); //���ڿ��� ���ڷ� �ٲ��ִ� �Լ�. 
        //m���� �ش� ���ĺ��� ���� ���� ��ΰ� ����. //Ary�� ���� �Է��� ���ڿ���.
        for (int j = 0; j < Ary.length(); j++)
        {
            if (m.find(Ary[j]) != m.end()) //map�� ary�� ������ for���� ���ư��� �ƴϸ� continue��.
            {
                for (int k = 0; k < m.find(Ary[j])->second.size(); k++) //���� ã�� key�� ��θ� �������. ��δ� �迭�̴ϱ� size��ŭ ���ָ� ��.
                {
                    cout << m.find(Ary[j])->second[k];
                }
            }
        }
        cout << "\n";
    }
    cin >> cnum;
    vector<int> num;
    for (int i = 0; i < cnum; i++)
    {
        string Num;
        cin >> Num;

        decode(pq.top(), pq.top(), Num, 0, cc); //�Է¹��� ���ڸ� ���ڿ��� ��ȯ�ؾ���.
        for (int i = 0; i < cc.size(); i++)
        {
            cout << cc[i];
        }
        if (i < cnum - 1)
            cout << endl;
        num.resize(0);
        cc.resize(0);
    }
}
node_ptr create_node(char Symbol, int freq)
{
    node_ptr Node = new node;
    Node->symbol = Symbol;
    Node->freq = freq;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}
void huffman(int n, PQ& pq)
{
    while (pq.size() != 1) //pq�� 1�� �ɶ����� �̾����.
    {
        node_ptr p = pq.top(); //�ش� ť���� ���� ���� �󵵼��� p
        pq.pop();
        node_ptr q = pq.top(); //�ش� ť���� �ι����� ���� �󵵼��� q
        pq.pop();
        node_ptr r = create_node('+', p->freq + q->freq); //p�� q�� �󵵼��� ������ ���ο� ��带 ����.
        r->left = p; //�� ��忡�� �������� ���� ū���� �������� �־��ְ�
        r->right = q;
        pq.push(r); //ť�� �־���.
    }
}
//huffman�� ������ Ʈ���� �ϼ���.
void encode(node_ptr root, vector<int>& code, map<char, vector<int>>& decoder) //���ڿ��� ���ڷ� �ٲ��ִ� �Լ� 
{
    if (root->symbol != '+') //+�� �ƴ϶�� ret�� �ش� ���ĺ��� �־���.
    {
        vector<int> ret;
        ret.resize(code.size());
        copy(code.begin(), code.end(), ret.begin());
        decoder.insert(make_pair(root->symbol, ret)); //map���ٰ� �� ��ο� �׶��� ���ĺ��� �־���.
    }
    else if (root != NULL) //��Ʈ�� ���� �ƴ϶�� == +���?
    {
        code.push_back(0);  //�������� �̵��ϱ� ���� ��� 0����.
        encode(root->left, code, decoder); //�������� �̵��� 
        code.pop_back(); //���� Ż���ϸ� ���������� �̵��� �����̴� 1�� ��� ���������� �̵���. 
        code.push_back(1);
        encode(root->right, code, decoder);
        code.pop_back(); //���� Ż���ϸ� ��� �ʱ�ȭ
    }
}
void decode(node_ptr root, node_ptr cnode, string S, int i, vector<char>& ary) //���ڸ� ����
{
    if (cnode != NULL && i <= S.size()) //��������Ͱ� ���� ����Ű�� �ȵǰ� i�� �Է¹��� ���ڿ� ����������� �ݺ���
    {
        if (cnode->symbol != '+') //���ڸ� �����ٸ� ���ڸ� �迭�� �־��ְ� ��Ʈ�� �ٽ� �ǵ��ư�����.
        {
            ary.push_back(cnode->symbol);
            decode(root, root, S, i, ary);
        }
        else if (cnode->symbol == '+' && i <= S.size()) //���ĺ��� �ƴ϶�� 
        {
            if (S[i] == '0') //��ΰ� 0�϶��� �������� �Ű���.
            {
                decode(root, cnode->left, S, i + 1, ary);
            }
            else if (S[i] == '1') //��ΰ� 1�϶��� ���������� �Ű���. 
            {
                decode(root, cnode->right, S, i + 1, ary);
            }
        }
    }
}
node_ptr preorder(node_ptr root) //root��� ���� �ݺ� ������ �ٽ� ������ 
{
    if (root != NULL)
    {
        cout << root->symbol << ":" << root->freq << " ";
        preorder(root->left);
        preorder(root->right);
    }
    return root;
}
node_ptr inorder(node_ptr root) //���ʿ��ʿ��ʿ��ʸ����� ��� ������ ������ ������ ���οö�.
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->symbol << ":" << root->freq << " ";
        inorder(root->right);
    }
    return root;
}
*/