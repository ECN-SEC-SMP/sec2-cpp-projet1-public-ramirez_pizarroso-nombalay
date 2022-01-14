#ifndef _POINT_2D_H_
#define _POINT_2D_H_

template<typename T>
class point2D;

template<typename T>
std::ostream& operator<<(std::ostream &, point2D<T> const&);

template<typename T>
class point2D{
private:
    T x;
    T y;
public:
    //constructeurs
    point2D(T x, T y);
    point2D();
    point2D(const point2D<T> &p);

    //accesseurs
    T getX() const;
    T getY() const;

    void setX(T x);
    void setY(T y);

    //méthodes
    void translate(T x, T y);

    friend std::ostream& operator<< <T>(std::ostream &, point2D const&);
};

template<typename T>
point2D<T>::point2D(T x, T y){
    this->x = x;
    this->y = y;
}

template<typename T>
point2D<T>::point2D(){
    this->x = 0;
    this->y = 0;
}

template<typename T>
point2D<T>::point2D(const point2D<T> &p){
    this->x = p.getX();
    this->y = p.getY();
}

template<typename T>
T point2D<T>::getX() const{
    return this->x;
}

template<typename T>
T point2D<T>::getY() const{
    return this->y;
}

template<typename T>
void point2D<T>::setX(T x){
    this->x = x;
}

template<typename T>
void point2D<T>::setY(T y){
    this->y = y;
}

template<typename T>
void point2D<T>::translate(T x, T y){
    this->x += x;
    this->y += y;
}

template<typename	T>
std::ostream& operator<<(std::ostream &s, point2D<T> const &p){
    s << "X: " << p.x << "  Y: " << p.getY();
    return s;
}

#endif