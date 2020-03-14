#include <bits/stdc++.h>
using namespace std;


class Point
{
public:
    int x, y;
};

int compareByX(const void* a, const void* b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareByY(const void* a, const void* b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

float calcDist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +(p1.y - p2.y)*(p1.y - p2.y));
}

float bruteForce(Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            if (calcDist(P[i], P[j]) < min)
                min = calcDist(P[i], P[j]);
        }
    }


    return min;
}

float min(float x, float y)
{
    return (x < y)? x : y;
}

float middlePoints(Point arr[], int size, float d)
{
    float min = d;

    qsort(arr, size, sizeof(Point), compareByY);

    for (int i = 0; i < size; ++i)
    {
        for (int j = i+1; j < size && (arr[j].y - arr[i].y) < min; ++j)
        {
            if (calcDist(arr[i],arr[j]) < min)
                min = calcDist(arr[i], arr[j]);
        }
    }



    return min;
}

float divideAndConquer(Point P[], int n)
{
    if (n <= 3)
        return bruteForce(P, n);

    int mid = n/2;
    Point midPoint = P[mid];

    float dl = divideAndConquer(P, mid);
    float dr = divideAndConquer(P + mid, n - mid);

    float d = min(dl, dr);

    Point arr[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(P[i].x - midPoint.x) < d)
        {
            arr[j] = P[i];
            j++;
        }

    }



    return min(d, middlePoints(arr, j, d) );
}

float getMinDistance(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareByX);
    return divideAndConquer(P, n);
}

int main()
{
    vector<float> ans;
    Point p;
    int n;
    cin>>n;
    Point points[n];
    while(true)
    {
        if(n==0)
            break;
        for(int i=0; i<n; i++)
        {
            cin>>p.x;
            cin>>p.y;
            points[i] = p;
        }
        ans.push_back(getMinDistance(points, n));
        cin>>n;
    }
    for(float x : ans)
    {
        if(x>10000)
        {
            cout<<"INFINITY"<<endl;
            continue;
        }
        cout<<fixed<<setprecision(4)<<x<<endl;
    }

    return 0;
}

