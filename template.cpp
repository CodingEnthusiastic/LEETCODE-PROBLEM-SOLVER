#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void yes()
{
    cout<<"YES\n";
}
void no()
{
    cout<<"NO\n";
}
struct TreeNode 
{
    int val;
    TreeNode* parent;
    vector<TreeNode*> children;

    TreeNode(int v) : val(v), parent(nullptr) {}
};

vector<int> sieve(int n) 
{
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; ++i) 
	{
        if (isPrime[i]) 
		{
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i <= n; ++i) 
	{
        if (isPrime[i]) 
			primes.push_back(i);
    }

    return primes;
}

bool isprime(long long n) 
{
    if (n <= 1) 
		return false;
    if (n <= 3)
		return true;
    if (n % 2 == 0 || n % 3 == 0) 
		return false;

    for (long long i = 5; i * i <= n; i += 6) 
	{
        if (n % i == 0 || n % (i + 2) == 0) 
			return false;
    }
    return true;
}



class Tree {
public:
    unordered_map<int, TreeNode*> nodes;
    TreeNode* root = nullptr;

    void buildFromEdges(int n, const vector<pair<int, int>>& edges) 
	{
        for (int i = 1; i <= n; ++i) 
		{
            nodes[i] = new TreeNode(i);
        }

        vector<int> indegree(n + 1, 0);
        for (auto [u, v] : edges) 
		{
            nodes[v]->parent = nodes[u];
            nodes[u]->children.push_back(nodes[v]);
            indegree[v]++;
        }

        for (int i = 1; i <= n; ++i) 
		{
            if (indegree[i] == 0) 
			{
                root = nodes[i];
                break;
            }
        }
    }

    void printTree() 
	{
        printNode(root, 0);
    }

    void printNode(TreeNode* node, int level) 
	{
        if (!node) 
			return;
        cout << string(level * 2, ' ') << "Node " << node->val;
        if (node->parent) 
			cout << " (Parent: " << node->parent->val << ")";
        cout << "\n";
        for (auto child : node->children) 
		{
            printNode(child, level + 1);
        }
    }

    ~Tree() 
	{
        for (auto& [_, node] : nodes) 
		{
            delete node;
        }
    }
};

int main()
{
	ll cases;
	cin>>cases;
	while(cases--)
	{
		ll n;
		cin>>n;
		//cout<<n<<endl;
		
	}
}
