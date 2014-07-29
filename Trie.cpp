#include <cstdio>
#include <cstdlib>
#include <cstring>
 
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
 
// Alphabet size (# of symbols)
 
#define ALPHABET_SIZE (26)
#define INDEX(c) ((int)c - (int)'a')
  
// forward declration
typedef struct trie_node trie_node_t;
 
// trie node
struct trie_node
{
    // int words;
    int prefixes;
    int value; // non zero if leaf
    trie_node_t *children[ALPHABET_SIZE];
};
 
// trie ADT
typedef struct trie trie_t;
 
struct trie
{
    trie_node_t *root;
    int count;
};
 
trie_node_t *getNode(void)
{
    trie_node_t *pNode = new trie_node_t;

 
    pNode->value   = 0;
    // pNode->words = 0;
    pNode->prefixes = 0;
 
    for(int i = 0; i < ALPHABET_SIZE; i++)
    {
        pNode->children[i] = NULL;
    }
    
    return pNode;
}
 
void initialize(trie_t *pTrie)
{
    pTrie->root = getNode();
    pTrie->count = 0;
}
 
void insert(trie_t *pTrie, char key[])
{
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
 
    pTrie->count++;
    pCrawl = pTrie->root;
    
    // printf("%s\n",key);
    for(int level = 0; level < length; level++ )
    {
        index = INDEX(key[level]);
 
        if( pCrawl->children[index] )
        {
            // Skip current node
            pCrawl = pCrawl->children[index];
            pCrawl->prefixes += 1;
            // printf("1 %c %d\n",key[level],pCrawl->prefixes);
            // pCrawl->prefixes += 1;
        }
        else
        {
            // Add new node
            pCrawl->children[index] = getNode();            
            pCrawl = pCrawl->children[index];
            pCrawl->prefixes += 1;
            // printf("2 %c %d\n",key[level],pCrawl->prefixes);
            
        }
    }
 
    // mark last node as leaf (non zero)
    pCrawl->value = pTrie->count;
}

int search(trie_t *pTrie, char key[])
{
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
 
    pCrawl = pTrie->root;
 
    for(int level = 0; level < length; level++ )
    {
        index = INDEX(key[level]);
 
        if( !pCrawl->children[index] )
        {
            return 0;
        }
 
        pCrawl = pCrawl->children[index];
    }
 
    return (0 != pCrawl && pCrawl->value);
}

 
int countPrefixes(trie_t *pTrie, char key[])
{
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
 
    pCrawl = pTrie->root;
 
    for(int level = 0; level < length; level++ )
    {
        index = INDEX(key[level]);
 
        if( !pCrawl->children[index] )
        {
            return 0;
        }
 
        pCrawl = pCrawl->children[index];
        // printf("%c %d\n",key[level],pCrawl->prefixes);
    }
    return pCrawl->prefixes;
    // return (0 != pCrawl && pCrawl->prefixes);
}
 
int leafNode(trie_node_t *pNode)
{
    return (pNode->value != 0);
}
 
int isItFreeNode(trie_node_t *pNode)
{
    int i;
    for(i = 0; i < ALPHABET_SIZE; i++)
    {
        if( pNode->children[i] )
            return 0;
    }
 
    return 1;
}
 
bool deleteHelper(trie_node_t *pNode, char key[], int level, int len)
{
    if( pNode )
    {
        // Base case
        if( level == len )
        {
            if( pNode->value )
            {
                // Unmark leaf node
                pNode->value = 0;
 
                // If empty, node to be deleted
                if( isItFreeNode(pNode) )
                {
                    return true;
                }
 
                return false;
            }
        }
        else // Recursive case
        {
            int index = INDEX(key[level]);
 
            if( deleteHelper(pNode->children[index], key, level+1, len) )
            {
                // last node marked, delete it
                // FREE(pNode->children[index]);
 
                // recursively climb up, and delete eligible nodes
                return ( !leafNode(pNode) && isItFreeNode(pNode) );
            }
        }
    }
 
    return false;
}
 
void deleteKey(trie_t *pTrie, char key[])
{
    int len = strlen(key);
 
    if( len > 0 )
    {
        deleteHelper(pTrie->root, key, 0, len);
    }
}
 
int main()
{
    char keys[][8] = {"she", "sells", "sea", "shore", "the", "by", "sheer"};
    trie_t trie;
 
    initialize(&trie);
    for(int i = 0; i < ARRAY_SIZE(keys); i++)
    {
        insert(&trie, keys[i]);
    }
 
    // deleteKey(&trie, keys[0]);
    char str[] = "s";
    printf("%d\n",countPrefixes(&trie, str));
    printf("%s %s\n", str, search(&trie, str) ? "Present in trie" : "Not present in trie");
 
    return 0;
}