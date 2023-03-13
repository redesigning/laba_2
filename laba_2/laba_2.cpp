#include <iostream>
using namespace std;

class Rectangle { // класс прямоугольник
public: //публичные 
    int a; //свойства прямоугольник, а - 1 сторона прямоугульника
    int b; //вторая сторона прямоугольника

    Rectangle() { // метод пустой конструктор
        printf("Rectangle()\n");
        a = 0; //мы работаем с х типа поинт
        b = 0;
    }
    Rectangle(int a, int b) { //конструктор с параметрами
        printf("Rectangle(int a, int b)\n");
        this->a = a; //указывает на обьект класса
        this->b = b;
    }
    Rectangle(const Rectangle&p) { //конструктор копирования
        printf("Rectangle(const Rectangle&p) \n");
        this->a = p.a;
        this->b = p.b;
    }
    ~Rectangle() {
        printf("%d %d\n", a, b);
        printf("~Rectangle()\n");
    }
};
class ColorRectangle : public Rectangle { // класс цветов 
public:
    string color; //цвет 
    ColorRectangle() : Rectangle() { //какой конструктор предка должен казываться(пустой)
        printf("ColorRectangle()\n");
        color = "black";
    }
    ColorRectangle(int a, int b, string color): Rectangle(a, b) { //конструктор с параметрами
        printf("ColorRectangle(int a, int b)\n");
        this->color = color;
    }
    ColorRectangle(const ColorRectangle&p) : Rectangle(p) { //конструктор копирования
        printf("ColorRectangle(const ColorRectangle&p)\n");
        this->color = p.color;

    }
    ~ColorRectangle() {
        printf("%d %d color = %s\n", a, b, color.c_str());
        printf("~ColorRectangle()\n");
    }
};
class MergeRect { // композиция, обьединение двух прямоугольников
public:
    Rectangle* r1;
    Rectangle* r2;
    MergeRect() {
        printf("MergeRect()\n");
        r1 = new Rectangle;
        r2 = new Rectangle;
    }
    MergeRect(int a1, int b1, int a2, int b2) {
        printf("MergeRect(int a1, int b1, int a2, int b2)\n");
        r1 = new Rectangle(a1, b1);
        r2 = new Rectangle(a2, b2);
    }
    MergeRect(const MergeRect &m) {
        printf("MergeRect(const MergeRect &m)\n");
        r1 = new Rectangle(*(m.r1));
        r2 = new Rectangle(*(m.r2));
    }
    ~MergeRect(){
        delete r1;
        delete r2;
        printf("~MergeRect()");
    }
    int merge() { // соединение двух прямоугольников
        int s1 = r1->a+r2->a; 
        int s2 = r2->b+r1->b;
        return s1 * s2;
    }
};
void Static_Object_Rectangle() { //статическое создание обьектов
    Rectangle p;
    Rectangle p1(5, 6);
    Rectangle p2(p1);
}
void Dinamic_Object_Rectangle() { //динамическое создание обьектов (сами создаем обьект)
    Rectangle* p = new Rectangle;
    Rectangle* p1 = new Rectangle(5, 6);
    Rectangle* p2 = new Rectangle(*p1);
    delete p1;
    delete p2;
    delete p;
}
void Static_Object_ColorRectangle() { //статическое создание обьектов
    ColorRectangle p;
    ColorRectangle p1(5, 6, "white");
    ColorRectangle p2(p1);
}
void Dinamic_Object_ColorRectangle() { //динамическое создание обьектов (сами создаем обьект)
    ColorRectangle* p = new ColorRectangle;
    ColorRectangle* p1 = new ColorRectangle(5, 6, "white");
    ColorRectangle* p2 = new ColorRectangle(*p1);
    delete p1;
    delete p2;
    delete p;
}
void ColorRectangle_Descen() { //помещение объектов в переменные различных типов 

    Rectangle* p2 = new ColorRectangle(1, 2, "black"); //обьект поинт(предк) указывает на колор поинт(потомок)
    delete p2;

}
void Static_Object_MergeRect() {
    MergeRect p;
    MergeRect p1(5, 6, 2, 8);
    MergeRect p2(p1);
}
void Dinamic_Object_MergeRect() {
    MergeRect *p = new MergeRect;
    MergeRect *p1= new MergeRect(5, 6, 2, 8);
    MergeRect *p2= new MergeRect(*p1);
    delete p;
    delete p1;
    delete p2;
}

int main()
{
    setlocale(0, "");
    int c;
    do {
        system("cls");
        printf("1)Static_Object_Rectangle\n2)Dinamic_Object_Rectangle\n3)Static_Object_ColorRectangle\n4)Dinamic_Object_ColorRectangle\n5)ColorRectangle_Descen\n6)Static_Object_MergeRect\n7)Dinamic_Object_MergeRect\n");
        printf("Выберете функцию проверки: ");
        int k;
        scanf_s("%d", &k);
        switch (k) {
        case 1:
            Static_Object_Rectangle();
            break;
        case 2:
            Dinamic_Object_Rectangle();
            break;
        case 3:
            Static_Object_ColorRectangle();
            break;
        case 4:
            Dinamic_Object_ColorRectangle();
            break;
        case 5:
            ColorRectangle_Descen();
            break;
        case 6:
            Static_Object_MergeRect();
            break;
        case 7:
            Dinamic_Object_MergeRect();
            break;
        }
        printf("\nЧто бы продолжить введите: 1\nЧто бы выйти введите любую цифру\n");
        scanf_s("%d", &c);
        printf("\n");
    } while (c == 1);
    return 0;
}