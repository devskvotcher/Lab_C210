#pragma once
template<typename T>
void print_element(const T& element) {
    std::cout << element << ' ';
}

// Шаблонная функция для изменения координат точек
template<typename T>
class ChangeCoordinates {
public:
    T dx, dy;

    ChangeCoordinates(T dx, T dy) : dx(dx), dy(dy) {}

    void operator()(Point& point) {
        point.SetPointX(point.GetPointX() + dx);
        point.SetPointY(point.GetPointY() + dy);
    }
};
class Diapason
{
    int n;
    int m;
public:
    Diapason(int x, int y) :n(x), m(y) {};
    const bool operator() (const Point& point) const
    {
        if ((n <= point.m_x && m >= point.m_x) && (n <= point.m_y && m >= point.m_y))
            return true;
        return false;
    }
};
template<typename T>
void print_container(const T& container) 
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it) 
    {
        std::cout << "{" << it->first << ", " << it->second << "} ";
    }
    std::cout << std::endl;
}

class Rect 
{
public:
    Rect(double x, double y, double w, double h) : m_x(x), m_y(y), m_w(w), m_h(h) {}
    double area() const { return m_w * m_h; }
    double centerX() const { return m_x + m_w / 2.0; }
    double centerY() const { return m_y + m_h / 2.0; }
    friend std::ostream& operator<<(std::ostream& os, const Rect& r);
private:
    double m_x, m_y, m_w, m_h;
};

std::ostream& operator<<(std::ostream& os, const Rect& r) {
    os << "Rect(" << r.m_x << ", " << r.m_y << ", " << r.m_w << ", " << r.m_h << ")";
    return os;
}

class CompareRectsByDistanceFromOrigin {
public:
    bool operator()(const Rect& r1, const Rect& r2) const {
        double dist1 = std::sqrt(r1.centerX() * r1.centerX() + r1.centerY() * r1.centerY());
        double dist2 = std::sqrt(r2.centerX() * r2.centerX() + r2.centerY() * r2.centerY());
        return dist1 < dist2;
    }
};