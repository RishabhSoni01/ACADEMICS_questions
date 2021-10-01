#include<iostream>
#include<iomanip>
using namespace std;

class Time
{
  public :
    int h;
    int mm;
    int ss;

    Time(int h = 0, int m  = 0, int s = 0)
    {
      hh = h;
      mm = m;
      ss = s;
    }

    void setTime(int h, int m, int s)
    {
      hh = h;
      mm = m;
      ss = s;
    }

    void showTime()
    {
      cout << setw(2) << setfill('0') << hh << ":"
        << setw(2) << setfill('0') << mm << ":"
        << setw(2) << setfill('0') << ss << "\n";
    }

    Time addTime(Time a, Time b){
      Time tf;
      int totals = (a.hh + b.hh)*3600 +(a.mm + b.mm)*60 + a.ss+b.ss;
      int hf=totals/3600;
      totals%=3600;
      int mf=totals/60;
      totals%=60;
      int sf = totals;
      tf.hh=hf;
      tf.mm=mf;
      tf.ss=sf;
      return tf;
    }
    Time subtractTime(Time a, Time b){
      Time tf;
      int totals = (a.hh - b.hh)*3600 +(a.mm - b.mm)*60 + a.ss-b.ss;
      int hf=totals/3600;
      totals%=3600;
      int mf=totals/60;
      totals%=60;
      int sf = totals;
      tf.hh=hf;
      tf.mm=mf;
      tf.ss=sf;
      return tf;
    }
};
int main()
{
  cout<<"time 1\t:";
  Time t1(10, 50, 59);
  t1.showTime();  // 10:50:59
  cout<<"time 2\t:";
  Time t2(6,33,33);  
  t2.showTime();  // 06:33:33
  cout<<"sum\t:";
  t1.addTime(t1,t2).showTime();  
  cout<<"diff\t:";
  t1.subtractTime(t1,t2).showTime();  
  return 0;
}
