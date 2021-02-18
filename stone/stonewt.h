#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt{
private:
    enum { Lbs_per_stn = 14 };   // or static const int Lbs_per_stn = 14
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void show_lbs() const;  // show weight in pounds format
    void show_stn() const;  // show weight in stone format

    operator int() const;
    operator double() const;
};
#endif