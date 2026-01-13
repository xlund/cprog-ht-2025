#ifndef SCORE_H
#define SCORE_H
class Score {
public:
  void add(int score);
  int value() const;
  void reset();

private:
  int score_{0};
};

#endif
