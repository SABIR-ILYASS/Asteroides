#ifndef SCORE_H
#define SCORE_H


class Score
{
protected:
    int score_;
    static int bestScore_;
public:
    static int getbestScore();
    void setScore(int n);
    void setBestScore(int n);
    int getScore();
    int getBestScore();
    void AddScore(int n);


};

#endif // SCORE_H
