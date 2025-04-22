#include <iostream>
using namespace std;
int main()
{
    string questions[] = {"1. What year was C++ created?",
                        "2. Who invented C++? ",
                        "3. What is the predecessor of C++?: ",
                        "4. Is the Earth flat?"};
    string options[][4] = {{"A. 1969", "B. 1975", "C. 1985", "D. 1989"},
                {"A. Guido van Rossum", "B. Bjarne Stroustrup", "C. John Cassidy", "D. Nischal Dhakal"},
                {"A. C", "B. C+", "C. C--", "D. B++"},
                {"A. yes", "B. no", "C. sometimes", "D. What's Earth"}};
    
    char answerKey[] = {'C', 'B', 'A', 'B'};

    int size = sizeof(questions)/sizeof(questions[0]);
    char guess;
    int score;

    for (int i = 0; i < size; i++){
        cout << "******************************"<< endl;
        cout << questions[i] << endl;
        cout << "******************************"<< endl;
        for (int j = 0; j < sizeof(options[i])/sizeof(options[i][0]); j++){
            cout << options[i][j] << endl;
        }
        cout << "******************************"<< endl;
        cin >> guess;
        guess = toupper(guess);
        if (guess == answerKey[i]){
            cout << "Correct answer" << endl;
            score++;
        }
        else{
            cout << "Incorrect answer" << endl;
        }

    }   
    cout << "No. of total questions: " << size << endl;
    cout << "No. of correct answers: " << score << endl;
    cout << "You scored " << (double(score)/size) * 100 << "%." << endl;

    

    return 0;
}