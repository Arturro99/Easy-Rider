#ifndef TRAFFIC_H
#define TRAFFIC_H


class Traffic
{

private:
    int trafficIntensity;

public:
    Traffic();
    void changeTraffficIntensity(int);

    int getTrafficIntensity() const;
    void setTrafficIntensity(int newTrafficIntensity);
};

#endif // TRAFFIC_H
