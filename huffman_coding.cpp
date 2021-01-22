#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode
{
    char data;
    unsigned freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};

void print_codes(struct MinHeapNode *root, string str)
{
    if (!root)
        return;

    if (root->data != '#')
        cout << root->data << "    : " << str << "\n";

    print_codes(root->left, str + "0");
    print_codes(root->right, str + "1");
}

void huffman_coding(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('#', left->freq + right->freq);

        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    cout << "Data : Freq" << endl;
    print_codes(minHeap.top(), "");
}

int32_t main()
{
    int n;
    cin >> n;

    char arr[n];
    int freq[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
        cin >> freq[i];

    huffman_coding(arr, freq, n);
    return 0;
}
/*char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 }; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    */

/*map<char,int> m;
    string s;
    getline(cin,s);
    //cin >> s;
    for(int i=0;i<s.length();i++)
    {
       m[s[i]-'a']++;
    }
    
    vector<char> arr;
    vector<int> freq;
    
    for(auto i:m)
    {
       arr.push_back(i.first);
       freq.push_back(i.second);
    }
    
    huffman_coding(arr, freq, freq.size());
    */