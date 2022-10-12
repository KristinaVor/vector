#include <iostream>
#include <cmath>

class vector
{
public:

	double x = {};
	double y = {};
	double z = {};

	vector() = default;

	vector(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;

	}
	~vector() {}

	vector operator = (vector v) //присвоение
	{
		vector vec_temp = {};
		vec_temp.x = this->x = v.x;
		vec_temp.y = this->y = v.y;
		vec_temp.z = this->z = v.z;

		return vec_temp;
	}

	vector operator + (vector v) //сумма векторов
	{
		vector vec_temp = {};
		vec_temp.x = this->x + v.x;
		vec_temp.y = this->y + v.y;
		vec_temp.z = this->z + v.z;

		return vec_temp;
	}

	vector operator - (vector v) //разность векторов
	{
		vector vec_temp = {};
		vec_temp.x = this->x - v.x;
		vec_temp.y = this->y - v.y;
		vec_temp.z = this->z - v.z;

		return vec_temp;
	}

	vector operator * (double num) // умножение вектора на число
	{
		vector vec_temp = {};
		vec_temp.x = this->x * num;
		vec_temp.y = this->y * num;
		vec_temp.z = this->z * num;

		return vec_temp;
	}

	vector operator / (double num) // деление вектора на число
	{
		vector vec_temp = {};
		vec_temp.x = this->x / num;
		vec_temp.y = this->y / num;
		vec_temp.z = this->z / num;

		return vec_temp;
	}

	void show()
	{
		std::cout << x << " " << y << " " << z << std::endl;
	}

	vector sum(vector v) // сумма векторов
	{
		vector vec_temp = {};
		vec_temp.x = this->x + v.x;
		vec_temp.y = this->y + v.y;
		vec_temp.z = this->z + v.z;
		return vec_temp;
	}

	double scal(vector a) //скалярное произведение
	{
		double value = a.x*x + a.y*y + a.z*z;
		return value;
	}

	vector vec_proizv(vector a) //векторное произведение
	{
		vector temp = {};
		temp.x = a.y*this->z - a.z*this->y;
		temp.y = a.z*this->x - a.x*this->z;
		temp.z = a.x*this->y + a.y*this->x;
		return temp;
	}

	double abc()// модуль
	{
		double value = std::sqrt(x*x + y * y + z * z);
		return value;
	}
	vector vector_proection(vector b )//векторная проекция двух векторов
	{
		double scalar_value = (x * b.x + y * b.y + z * b.z) / b.abc();
		vector proection = b.norm() * scalar_value;
		return proection;
	}
	vector norm() //нормаль
	{
		vector tmp(x, y, z);
		return tmp / tmp.abc();
	}

	double scalar_proec(vector a)//скалярная проекция
	{
		double value = (x*a.x + y * a.y + z * a.z) / a.abc();
		return value;
	}

};

int main()
{
	vector a = vector(2.0, 0.0, 0.0);
	vector b = vector(0.0, 1.0, 0.0);
	(a + b).show();
	a.vec_proizv(b).show();

	std::cout << a.abc() << std::endl;
	std::cout << a.scalar_proec(a) << std::endl;
	return 0;
}