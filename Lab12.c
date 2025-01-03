/*12. Given a File of N employee records with a set K of Keys (4-digit) which uniquely determine 
the records in file F. Assume that file F is maintained in memory by a Hash Table (HT) of m 
memory locations with L as the set of memory addresses (2-digit) of locations in HT. Let the 
keys in K and addresses in L are Integers. Develop a Program in C that uses Hash function H: 
K →L as H(K)=K mod m (remainder method), and implement hashing 
technique to map a given key K to the address space L. Resolve the collision (if any) using 
linear probing. 
*/
#include <stdio.h>
#include <stdlib.h>

// Global variables
int *ht, m, n,count;  //n is number of keys ,m is the size of the hashtable,
const char *filename = "hash.txt";      //filename is a pointer has it is storing address of string literal
int keys[20];

// Function prototypes
void insert(int key);
void insertfile();
void displayfile();

int main()
{

    printf("Enter number of keys (n):\n");
    scanf("%d", &n);

    printf("Enter size of hash table (m):\n");
    scanf("%d", &m);

    if (m < n)
    {
        printf("Insertion not possible. Hash table size must be at least n.\n");
        exit(0);
    }

    // Allocate memory for the hash table
    ht = (int *)malloc(sizeof(int) * m);

    // Initialize hash table with -1
    for (int i = 0; i < m; i++)
        ht[i] = -1;

    // Input keys
    printf("Enter the keys:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &keys[i]);
        insert(keys[i]);
    }
    
    printf("No of index:%d\n",count);

    // Write to file and display contents
    insertfile();
    displayfile();

    // Free allocated memory
    free(ht);
    return 0;
}

void insert(int key)
{
    count++;
    int index = key % m;
    while (ht[index] != -1)
        index = (index + 1) % m; // Linear probing, Index is used to make use of the updated values 
    ht[index] = key;
}

void insertfile()
{
    FILE *fp = fopen(filename, "w");
    if (!fp)
    {
        printf("File could not be opened.\n");
        return;
    }
    for (int i = 0; i < m; i++)
    {                               //"%d " is formating the file 
        fprintf(fp, "%d ", ht[i]); // Add space for separation and fprintf is used to write on the file 
    }
    printf("Successfully written to the file.\n");
    fclose(fp);
}

void displayfile()
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Could not open file.\n");
        return;
    }
    int temp;
    for (int i = 0; i < m; i++)
    {
        fscanf(fp, "%d", &temp);    
        printf("H[%d] = %d\n", i, temp);
    }
    fclose(fp);
}
