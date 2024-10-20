#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    string playerName;
    int totalScore;
    int ballsPlayed;
    int ballScores[100]; // Array to store the scores of each ball
    int ballCount;       // Counter to keep track of the number of balls

public:
    // Constructor
    Player() : playerName(""), totalScore(0), ballsPlayed(0), ballCount(0) {}

    // Setter and getter for playerName
    void setName(string name)
    {
        playerName = name;
    }

    string getName()
    {
        return playerName;
    }

    // Setter and getter for totalScore
    void setScore(int score)
    {
        totalScore += score;
    }

    int getScore()
    {
        return totalScore;
    }

    // Setter and getter for ballsPlayed
    void setBalls(int balls)
    {
        ballsPlayed = balls;
    }

    int getBalls()
    {
        return ballsPlayed;
    }

    // Add score for each ball
    void addBallScore(int score)
    {
        ballScores[ballCount++] = score;
    }

    // Get scores for each ball
    int *getBallScores()
    {
        return ballScores;
    }

    // Get the number of balls played
    int getBallCount()
    {
        return ballCount;
    }
};

// Function to simulate a player's turn
void playTurn(Player &player)
{
    int ballScore;
    while (true)
    {
        cout << "Enter score for the ball (-1 for OUT): ";
        cin >> ballScore;

        if (ballScore == -1)
        { // Player is out
            player.addBallScore(ballScore);
            break;
        }
        else
        {
            player.setScore(ballScore);
            player.addBallScore(ballScore);
        }

        player.setBalls(player.getBalls() + 1); // Increment balls played
    }
}

int main()
{
    // Array of player names
    string playerNames[11] = {
        "Babar Azam", "Naseem Shah", "Agha Salman", "Mohammad Amir", "Shaheen Afridi",
        "Shadab Khan", "Imad Wasim", "Fakhar Zaman", "Haris Rauf", "Mohammad Rizwan", "Iftikhar Ahmed"};

    // Array of Player objects
    Player players[11];

    // Set player names
    for (int i = 0; i < 11; i++)
    {
        players[i].setName(playerNames[i]);
    }

    // Simulate each player's turn and display their performance
    for (int i = 0; i < 11; i++)
    {
        cout << (i + 1) << ". " << players[i].getName() << " is batting." << endl;
        cout << "Scores per Ball :" << endl;
        playTurn(players[i]);

        int *ballScores = players[i].getBallScores();
        int ballCount = players[i].getBallCount();
        cout << "Performance: ";
        for (int j = 0; j < ballCount; j++)
        {
            if (ballScores[j] == -1)
            {
                cout << "OUT";
            }
            else
            {
                cout << ballScores[j];
            }
            if (j < ballCount - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
        cout << "Total Score: " << players[i].getScore() << endl;
        cout << "Balls Played: " << players[i].getBalls() << endl
             << endl;
    }

    // Display summary of the match
    cout << "Match Summary:" << endl;

    // Print column headers
    cout << "Player Name\tTotal Score\tBalls Played" << endl;

    // Print player data
    for (int i = 0; i < 11; i++)
    {
        cout << players[i].getName() << "\t\t" << players[i].getScore() << "\t\t" << players[i].getBalls() << endl;
    }

    // Determine man of the match
    Player manOfTheMatch;
    for (int i = 0; i < 11; i++)
    {
        if (players[i].getScore() > manOfTheMatch.getScore())
        {
            manOfTheMatch = players[i];
        }
    }

    // Display man of the match
    cout << endl;
    cout << "Man of the Match: " << manOfTheMatch.getName() << " with Score: " << manOfTheMatch.getScore() << endl;

    return 0;
}
