//7장-13.CIRCLE.H
//class Circle의 정의
#include<iostream>
using namespace std;
class Circle{
public:
    Circle(int x, int y, int r = 20) :
        X_center(x), Y_center(y), radius(r) {
        cout << endl << "Circle ::constructor: X_center = " << X_center<<" Y_center = "<< Y_center<<" radius = "<<radius<<endl;
    }
	
    //센터의 위치를 변경한다
    void Center (int x, int y){
        X_center = x ;
        Y_center = y ;
    }
	
    //반경을 변경한다
    void Radius (int r){
        radius = r ;
    }

    //private 데이터를 return하는 함수
    int Radius (){
        return radius ;
    }

    int XCenter (){
        return X_center ;
    }

    int YCenter (){
        return Y_center ;
    }
    //circle를 paint한다(그래픽을 사용하여 그것을 paint 칠해야 한다).
    void Paint (){
        cout << "Circle in (" << X_center << ", " << Y_center
             << "), radius is " << radius ;
    }

    //위치와 크기를 증가시킨다
    void operator ++ (){
        radius ++ ;
        X_center ++ ;
        Y_center++ ;
    }

//private 데이터는 센터의 x, y 좌표와 반경이다
private:	
    int X_center, Y_center ;
    int radius ;
};

