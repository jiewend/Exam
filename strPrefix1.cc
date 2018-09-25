#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<istream> 
#include<sstream> 
#include<iostream>

using namespace std;

#define MAX 256

template <typename T>
vector<T> splitSpace(std::string stri, T outType){
	string temp;
	vector<T>res;
	istringstream stream(stri);
	while (stream >> temp)
	{
		stringstream iss;
		iss << temp;
		T f;
		iss >> f;
		res.push_back(f);
	}
	return res;
}

// Maximum length of an input word
#define MAX_WORD_LEN 1000000

// Trie Node.
struct trieNode
{
    struct trieNode *child[MAX];
    int freq;  // To store frequency
};

// Function to create a new trie node.
struct trieNode *newTrieNode(void)
{
    struct trieNode *newNode = new trieNode;
    newNode->freq   = 1;
    for (int i = 0; i<MAX; i++)
        newNode->child[i] = NULL;
    return newNode;
}

// Method to insert a new string into Trie
void insert(struct trieNode *root, string str)
{
    // Length of the URL
    int len = str.length();
    struct trieNode *pCrawl = root;

    // Traversing over the length of given str.
    for (int level = 0; level<len; level++)
    {
        // Get index of child node from current character
        // in str.
        int index = str[level];

        // Create a new child if not exist already
        if (!pCrawl->child[index])
            pCrawl->child[index] = newTrieNode();
        else
           (pCrawl->child[index]->freq)++;

        // Move to the child
        pCrawl = pCrawl->child[index];
    }
}

// This function prints unique prefix for every word stored
// in Trie. Prefixes one by one are stored in prefix[].
// 'ind' is current index of prefix[]
void findPrefixesUtil(struct trieNode *root, char prefix[],
                      int ind)
{
    // Corner case
    if (root == NULL)
       return;

    // Base case
    if (root->freq == 1)
    {
        cout<<ind<<" ";
       prefix[ind] = '\0';
       cout << prefix <<endl;
       return;
    }

    for (int i=0; i<MAX; i++)
    {
       if (root->child[i] != NULL)
       {
           prefix[ind] = i;
           findPrefixesUtil(root->child[i], prefix, ind+1);
       }
    }
}

// Function to print all prefixes that uniquely
// represent all words in arr[0..n-1]
void findPrefixes(string arr[], int n)
{
    // Construct a Trie of all words
    struct trieNode *root = newTrieNode();
    root->freq = 0;
    for (int i = 0; i<n; i++)
        insert(root, arr[i]);

    // Create an array to store all prefixes
    char prefix[MAX_WORD_LEN];

    // Print all prefixes using Trie Traversal
    findPrefixesUtil(root, prefix, 0);
}

// Driver function.
int main()
{
    string inStr;
    int N;
    getline(cin, inStr);
    vector<int > inVec = splitSpace(inStr, N);
    N = inVec[0];
    string arr[N];
    for (unsigned i = 0; i < N; i++) { 
        getline(cin, inStr);
        vector<string > stringTemp = splitSpace(inStr, inStr);
        arr[i] = stringTemp[0];
    } 

    // string arr[] = {"zebra", "dog", "duck", "dove"};
    // int n = sizeof(arr)/sizeof(arr[0]);
    findPrefixes(arr, N);

    return 0;
}
