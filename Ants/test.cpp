#include <iostream>
#include <list>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
#define INF (1<<21)


int UB[6] = {0, 4, 7, 10, 12, 15};  //B1から各Bの路線の駅までにかかる時間
int DB[6] = {15, 11, 8, 5, 3, 0};   //B5から各Bの路線の駅までにかかる時間
int UA[13] = {0, 3, 8, 10, 13, 17, 20, 24, 26, 28, 31, 37, 39};
int UA2[7] = {0, 4, 6, 8, 11, 17, 19};
int DA[13] = {39, 36, 31, 29, 26, 22, 19, 15, 13, 11, 8, 2, 0};
int DA2[7] = {20, 17, 12, 10, 7, 3, 0};


//A1~A7,A7~A13,B1~B5に分割して求めるためにそれぞれ以下のStationクラスを継承させる
class Station
{
    public:
    int StationNum;    //駅の番号　(例 A3ならば3)
    int arrivetime[60];     //指定された時間帯の到着時刻を格納

    Station(int num)
        : StationNum(num)
    {
        fill(arrivetime, arrivetime + 60, INF); //十分大きい値で初期化
    }
};




//指定された時間帯まで時間を加算させていく
void progresstime(int& t, int n, int time)
{
    while((time * 100) > t)
    {
        t += n; //電車が何分おきに来るか

        //60分を過ぎたら時間を1増やす処理
        if ((t % 100) >= 60)
        {
            t = (t / 100) * 100 + 100 + (t % 10);
        }
    }
}



//A1 ~ A7
class AlineStation1 :public Station
{
    public:

    AlineStation1(int num)
        : Station(num)
    {}

    void arrive(int time, char DIR)
    {
        //初めて電車が到着する時間(0で初期化)
        int inittime = 0;
        
        if (DIR == 'U')
        {
            inittime = UA[StationNum - 1] + 555;
            int t = inittime;
            
            progresstime(t, 5, time);

            for(int i = 0; (t % 100) < 60; i++)
            {
                arrivetime[i] = t % 100;
                t += 5;
            }
        } else if (DIR == 'D')
        {
            inittime = DA[StationNum - 1] + 552;
            int t = inittime;
            
            progresstime(t, 10, time);

            int i = 0;
            for(i = 0; (t % 100) < 60; i++)
            {
                arrivetime[i] = t % 100;
                t += 10;
            }

            inittime = DA2[StationNum - 1] + 606;
            t = inittime;
            
            progresstime(t, 10, time);
            
            for(i += 0; (t % 100) < 60; i++)
            {
                arrivetime[i] = t % 100;
                t += 10;
            }

            sort(arrivetime, arrivetime + i);

        }
            
        

    }


};



//A7 ~ A13
class AlineStation2 :public Station
{
    public:
    AlineStation2(int num)
        : Station(num)
    {}

    void arrive(int time, char DIR)
    {
            int inittime = INF;
            if (DIR == 'U')
            {
                inittime = UA[StationNum - 1] + 600;
            } else if (DIR == 'D')
            {
                inittime = DA[StationNum - 1] + 552;
            }
            int t = inittime;
           
            progresstime(t, 10, time);
            int i = 0;
            for(i = 0; (t % 100) < 60; i++)
            {
                arrivetime[i] = t % 100;
                t += 10;
            }
            
    }

};




//B1 ~ B5
class BlineStation
{
    public:
    int StationNum;
    int arrivetime[60];

    BlineStation(int num)
        : StationNum(num)
    {
        fill(arrivetime, arrivetime + 60, INF);
    }

    void arrive(int time, char DIR){
            int inittime = INF;
            if (DIR == 'U')
            {
                inittime = UB[StationNum - 1] + 600;
            } else if (DIR == 'D')
            {
                inittime = DB[StationNum - 1] + 611;
            }
            int t = inittime;
            
            progresstime(t, 6, time);

            for(int i = 0; (t % 100) < 60; i++)
            {
                arrivetime[i] = t % 100;
                t += 6;
            }
    }
};

int main()
{
    char line;
    string station;
    char DIR;
    int time;
    
    cin >> line >> station >> DIR >> time;

    if (time >= 23 || time < 5)
    {
        cout << "No train" << endl;
        return 0;
    }

    station = station[1];

    int stnum = atoi(station.c_str());

    if (line == 'B')
    {
        //Bの路線は5時に電車は走らない
        if (time == 5)
        {
            cout << "No train" << endl;
            return 0;
        }
        BlineStation x(stnum);
        x.arrive(time, DIR);
        cout << setfill('0')  << right << setw(2) << time << ':' << " ";
        for (int i = 0; x.arrivetime[i] != INF; i ++)
        {
            cout << setfill('0')  << right << setw(2) << x.arrivetime[i] << " ";
        }
        cout << endl;

    } else if (line == 'A')
    {
        if (stnum >= 1 && stnum <= 6)
        {
            if (time == 5 && DIR == 'D')
            {
                cout << "No train" << endl;
                return 0;
            }

            AlineStation1 x(stnum);
            x.arrive(time, DIR);
            cout << setfill('0')  << right << setw(2) << time << ':' << " ";
            for (int i = 0; x.arrivetime[i] != INF; i ++)
            {    
                cout << setfill('0')  << right << setw(2) << x.arrivetime[i] << " ";
            }
            cout << endl;

        } else if (stnum >= 7 && stnum <= 13)
        {
            if (time == 5 && DIR == 'U')
            {
                cout << "No train" << endl;
                return 0;
            }
            AlineStation2 x(stnum);
            x.arrive(time, DIR);
            cout << setfill('0')  << right << setw(2) << time << ':' << " ";
            //6時の時間帯は例外的に始発が走る
            if (time == 6)
            {
                 cout << 10 + UA2[stnum - 7] << " ";
            }
            for (int i = 0; x.arrivetime[i] != INF; i ++)
            {
                cout << setfill('0')  << right << setw(2) << x.arrivetime[i] << " ";
            }
            cout << endl;
        } 

    }
    
}