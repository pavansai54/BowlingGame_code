//updated code for below mnetioned cases 
//cin user input , it should take both the 2 tires in one input  
//->char is not allowed in user input, input is allowed from 0 to 10
//-> if the both entries are more than 10 it is invalid  eg-6+5
//->invalid case again need to ask input 
//->10 if 1st enrty , 0 for 2 direct 
//->0 if 1st entry , 10 for direct 


#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class BowlingGame {
private:
    vector<int> rolls;

public:
    void roll(int pins) {
        rolls.push_back(pins);
    }

    int scoreUpToFrame(int frameLimit) {
        int totalScore = 0;
        int rollIndex = 0;
        int frame = 0;

        while (frame < frameLimit && rollIndex < rolls.size()) {
            if (rolls[rollIndex] == 10) { // Strike time 
                totalScore += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
                rollIndex += 1;
            } else if (rolls[rollIndex] + rolls[rollIndex + 1] == 10) { // Spare time 
                totalScore += 10 + rolls[rollIndex + 2];
                rollIndex += 2;
            } else { // Open frame
                totalScore += rolls[rollIndex] + rolls[rollIndex + 1];
                rollIndex += 2;
            }
            frame++;
        }
        return totalScore;
    }

    int score() {
        return scoreUpToFrame(10);
    }

    void printRollsSummary() {
        cout << "\nRolls Summary: ";
        for (int pins : rolls) {
            cout << pins << ", ";
        }
        cout << endl;
    }
};

int main() {
    BowlingGame game;
    int frame = 1;

    while (frame <= 10) {
        int firstRoll, secondRoll = 0, thirdRoll = 0;

        cout << "Frame " << frame << ":\n";

        // First roll
        cout << "  Enter pins knocked down in first roll: ";
        cin >> firstRoll;
        while (firstRoll < 0 || firstRoll > 10) {
            cout << "  Invalid input. Enter a value between 0 and 10: ";
            cin >> firstRoll;
        }
        game.roll(firstRoll);

        if (frame == 10) {
            // Second roll
            cout << "  Enter pins knocked down in second roll: ";
            cin >> secondRoll;
            while (secondRoll < 0 || secondRoll > 10) {
                cout << "  Invalid input. Enter a value between 0 and 10: ";
                cin >> secondRoll;
            }
            game.roll(secondRoll);

            // Check for bonus roll
            if (firstRoll == 10 || firstRoll + secondRoll == 10) {
                cout << "  Enter pins knocked down in bonus roll: ";
                cin >> thirdRoll;
                while (thirdRoll < 0 || thirdRoll > 10) {
                    cout << "  Invalid input. Enter a value between 0 and 10: ";
                    cin >> thirdRoll;
                }
                game.roll(thirdRoll);
            }
        } else {
            if (firstRoll < 10) {
                // Second roll
                cout << "  Enter pins knocked down in second roll: ";
                cin >> secondRoll;
                while (secondRoll < 0 || firstRoll + secondRoll > 10) {
                    cout << "  Invalid input. Total pins in a frame cannot exceed 10. Re-enter: ";
                    cin >> secondRoll;
                }
                game.roll(secondRoll);
            }
        }

        cout << "  Cumulative Score after Frame " << frame << ": " << game.scoreUpToFrame(frame) << "\n\n";
        frame++;
    }

    cout << "\nFinal Total Score: " << game.score() << endl;
    game.printRollsSummary();

    return 0;
}
