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
void decode(node_ptr root, node_ptr cnode, vector<int>& S, int i, vector<char>& ary);
node_ptr inorder(node_ptr root);
node_ptr preorder(node_ptr root);
int n, snum, cnum;
int main()
{
    PQ pq;
    string Ary;
    cin >> n;
    vector<char> x;
    vector<int> y;
    vector<char> cc;
    node_ptr Node = (node_ptr)malloc(sizeof(node));
    for (int i = 0; i < n; i++)
    {
        char b;
        cin >> b;
        x.push_back(b);
    }
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        y.push_back(c);
    }
    for (int i = 0; i < n; i++)
    {
        pq.push(create_node(x[i], y[i]));
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
        encode(pq.top(), code, m);
        for (int j = 0; j < Ary.length(); j++)
        {
            if (m.find(Ary[j]) != m.end())
            {
                for (int k = 0; k < m.find(Ary[j])->second.size(); k++)
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
        for (int i = 0; i < Num.length(); i++)
        {
            num.push_back(Num[i] - 48);
        }
        decode(pq.top(), pq.top(), num, 0, cc);
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
    while (pq.size() != 1)
    {
        node_ptr p = pq.top();
        pq.pop();
        node_ptr q = pq.top();
        pq.pop();
        node_ptr r = create_node('+', p->freq + q->freq);
        r->left = p;
        r->right = q;
        pq.push(r);
    }
}
void encode(node_ptr root, vector<int>& code, map<char, vector<int>>& decoder)
{
    if (root->symbol != '+')
    {
        vector<int> ret;
        ret.resize(code.size());
        copy(code.begin(), code.end(), ret.begin());
        decoder.insert(make_pair(root->symbol, ret));
    }
    else if (root != NULL)
    {
        code.push_back(0);
        encode(root->left, code, decoder);
        code.pop_back();
        code.push_back(1);
        encode(root->right, code, decoder);
        code.pop_back();
    }
}
void decode(node_ptr root, node_ptr cnode, vector<int>& S, int i, vector<char>& ary) //숫자를 문자
{
    if (cnode != NULL && i <= S.size())
    {
        if (cnode->symbol != '+')
        {
            ary.push_back(cnode->symbol);
            decode(root, root, S, i, ary);
        }
        else if (cnode->symbol == '+' && i < S.size())
        {
            if (S[i] == 0)
            {
                decode(root, cnode->left, S, i + 1, ary);
            }
            else if (S[i] == 1)
            {
                decode(root, cnode->right, S, i + 1, ary);
            }
        }
    }
}

node_ptr preorder(node_ptr root)
{
    if (root != NULL)
    {
        cout << root->symbol << ":" << root->freq << " ";
        preorder(root->left);
        preorder(root->right);
    }
    return root;
}
node_ptr inorder(node_ptr root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->symbol << ":" << root->freq << " ";
        inorder(root->right);
    }
    return root;
}