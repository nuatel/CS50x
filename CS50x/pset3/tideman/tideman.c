#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];  // To hop chap 2 cua Max

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

void swap(pair *xp, pair *yp);
bool hasCycle(int winner, int loser);


int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // Representation reference in diffirence way
    for (int i = 0 ; i < candidate_count ; i++)
    {
        if (!strcmp(candidates[i], name))
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // In a 1d array ranks, linear search is use O(n^2)
    for (int i = 0 ; i < candidate_count ; i++)
    {
        for (int j = i + 1 ; j < candidate_count ; j++)
        {
            preferences[ranks[i]][ranks[j]] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    // Not optimal loops, because it's take double look at index set i-j and j-i
    for (int i = 0 ; i < candidate_count ; i++)
    {
        for (int j = i + 1 ; j < candidate_count ; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO: implement an O(n^2) sorting algorithm

    for (int i = 0 ; i < pair_count ; i++)
    {

        for (int j = i + 1 ; j < pair_count ; j++)
        {
            int x1 = pairs[i].winner;
            int y1 = pairs[i].loser;
            int max1 = preferences[x1][y1] - preferences[y1][x1];

            int x2 = pairs[j].winner;
            int y2 = pairs[j].loser;
            int max2 = preferences[x2][y2] - preferences[y2][x2];

            if (max2 > max1)
            {

                swap(&pairs[i], &pairs[j]);

            }
        }


    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0 ; i < pair_count ; i++)
    {
        if (!hasCycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    for (int col = 0 ; col < candidate_count ; col++)
    {
        bool found_source = true;

        for (int row = 0 ; row < candidate_count ; row++)
        {
            if (locked[row][col] == true)
            {
                found_source = false;
                break;
            }

        }
        if (found_source)
        {
            printf("%s\n", candidates[col]);
        }
    }
    return;
}

void swap(pair *xp, pair *yp)
{
    pair temp = *xp;
    *xp = *yp;
    *yp = temp;
}

bool hasCycle(int winner, int loser)
{
    while (winner != -1 && winner != loser)
    {
        bool found = false;
        for (int i = 0 ; i < candidate_count ; i ++)
        {
            if (locked[i][winner])
            {
                found = true;
                winner = i;
            }
        }
        if (!found)
        {
            winner = -1;
        }

    }

    if (loser == winner)
    {
        return true;
    }
    return false;
}