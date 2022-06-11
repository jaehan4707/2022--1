/*
우선순위 큐에 빈도수가 낮은것들로 넣어줌.
빈도수가 낮은거 2개를 선정해서 트리를 이어붙임.만약 다 붙엿다면 종료함.
작은것이 왼쪽 큰것이 오른쪽에 들어감.

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
    PQ pq; //우선순위큐설정
    string Ary;
    cin >> n; //문자의 개수 n
    vector<char> x;
    vector<int> y;
    vector<char> cc;
    node_ptr Node = (node_ptr)malloc(sizeof(node)); //동적할당
    for (int i = 0; i < n; i++)
    {
        char b;
        cin >> b;
        x.push_back(b); //문자열 x에다가 문자를 넣어줌.
    }
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        y.push_back(c); //빈도값을 y에 넣어줌.
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
        encode(pq.top(), code, m); //문자열을 숫자로 바꿔주는 함수. 
        //m에는 해당 알파벳과 그의 따른 경로가 있음. //Ary는 내가 입력한 문자열임.
        for (int j = 0; j < Ary.length(); j++)
        {
            if (m.find(Ary[j]) != m.end()) //map에 ary가 있으면 for문이 돌아가고 아니면 continue임.
            {
                for (int k = 0; k < m.find(Ary[j])->second.size(); k++) //내가 찾은 key의 경로를 출력해줌. 경로는 배열이니까 size만큼 해주면 됨.
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

        decode(pq.top(), pq.top(), Num, 0, cc); //입력받은 숫자를 문자열로 교환해야함.
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
    while (pq.size() != 1) //pq가 1이 될때까지 이어붙임.
    {
        node_ptr p = pq.top(); //해당 큐에서 가장 작은 빈도수를 p
        pq.pop();
        node_ptr q = pq.top(); //해당 큐에서 두번쨰로 작은 빈도수를 q
        pq.pop();
        node_ptr r = create_node('+', p->freq + q->freq); //p와 q의 빈도수를 더해준 새로운 노드를 만듬.
        r->left = p; //그 노드에서 작은것이 왼쪽 큰것이 오른쪽을 넣어주고
        r->right = q;
        pq.push(r); //큐에 넣어줌.
    }
}
//huffman이 끝나면 트리가 완성됨.
void encode(node_ptr root, vector<int>& code, map<char, vector<int>>& decoder) //문자열을 숫자로 바꿔주는 함수 
{
    if (root->symbol != '+') //+가 아니라면 ret에 해당 알파벳을 넣어줌.
    {
        vector<int> ret;
        ret.resize(code.size());
        copy(code.begin(), code.end(), ret.begin());
        decoder.insert(make_pair(root->symbol, ret)); //map에다가 간 경로와 그때의 알파벳을 넣어줌.
    }
    else if (root != NULL) //루트가 널이 아니라면 == +라면?
    {
        code.push_back(0);  //왼쪽으로 이동하기 전에 경로 0찍음.
        encode(root->left, code, decoder); //왼쪽으로 이동후 
        code.pop_back(); //왼쪽 탈출하면 오른쪽으로 이동할 예정이니 1을 찍고 오른쪽으로 이동함. 
        code.push_back(1);
        encode(root->right, code, decoder);
        code.pop_back(); //만약 탈출하면 경로 초기화
    }
}
void decode(node_ptr root, node_ptr cnode, string S, int i, vector<char>& ary) //숫자를 문자
{
    if (cnode != NULL && i <= S.size()) //노드포인터가 널을 가리키면 안되고 i는 입력받은 숫자열 사이즈까지만 반복함
    {
        if (cnode->symbol != '+') //문자를 만난다면 문자를 배열에 넣어주고 루트로 다시 되돌아가야함.
        {
            ary.push_back(cnode->symbol);
            decode(root, root, S, i, ary);
        }
        else if (cnode->symbol == '+' && i <= S.size()) //알파벳이 아니라면 
        {
            if (S[i] == '0') //경로가 0일때는 왼쪽으로 옮겨줌.
            {
                decode(root, cnode->left, S, i + 1, ary);
            }
            else if (S[i] == '1') //경로가 1일때는 오른쪽으로 옮겨줌. 
            {
                decode(root, cnode->right, S, i + 1, ary);
            }
        }
    }
}
node_ptr preorder(node_ptr root) //root출력 왼쪽 반복 막히면 다시 오른쪽 
{
    if (root != NULL)
    {
        cout << root->symbol << ":" << root->freq << " ";
        preorder(root->left);
        preorder(root->right);
    }
    return root;
}
node_ptr inorder(node_ptr root) //왼쪽왼쪽왼쪽왼쪽막히면 출력 오른쪽 오른쪽 마히면 위로올라감.
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