#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Maximum number of candidates
#define MAX 9

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX];
int candidate_count;

bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Number of candidates
    candidate_count = argc - 1;

    // Check if the number of canidates pass the maximum or is lower them 2
    if (candidate_count > MAX || candidate_count < 2)
    {
        printf("Invalid number of candidates\n");
    }

    // Picking the canidates passed in cli arguments
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voters_number = get_int("Number of voters: ");

    // Voting
    for (int j = 0; j < voters_number; j++)
    {
        string name = get_string("Vote: ");

        vote(name);
    }

    print_winner();
}

// Adding the vote in the candidates array
bool vote(string name)
{
    for (int l = 0; l < candidate_count; l++)
    {
        if (strcmp(candidates[l].name, name) == 0)
        {
            candidates[l].votes += 1;
            return true;
        }
    }

    printf("Invalid vote\n");
    return false;
}

// Check who have the highest number of votes
void print_winner(void)
{
    int bigger = 0;

    // Picking the hightes number of votes
    for (int m = 0; m < candidate_count; m++)
    {
        if (candidates[m].votes > bigger)
        {
            bigger = candidates[m].votes;
        }
    }

    // Search for the winner(s)
    for (int n = 0; n < candidate_count; n++)
    {
        if (candidates[n].votes == bigger)
        {
            printf("%s\n", candidates[n].name);
        }
    }
}