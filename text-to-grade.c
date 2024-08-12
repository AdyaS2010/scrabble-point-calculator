#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Array of points assigned to each letter alphabetically as a constant
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
string compute_winner(int score1, int score2);

int main(void)
{
    // Prompt user(s) for 2 words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Compute score of each word
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    string winner = compute_winner(score1, score2);

    printf("%s\n", winner);
}

int compute_score(string word)
{
    // Compute & return score for word
    // ...

    // Track score
    int score = 0;

    // Compute score character-wise (for each character)
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}
