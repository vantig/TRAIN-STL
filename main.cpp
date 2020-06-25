#include"Train.h"
#include<vector>
#include<fstream>
#include<iterator>
#include<set>
#include <algorithm>


using std::set;
using std::vector;
int main()
{
	vector<Train>array;
	set<Train>trains;
	std::ifstream in("Train.txt");
	std::istream_iterator<Train> input(in), cur;
	std::copy(input, cur, inserter(trains ,trains.begin()));//читаем данные в контейнер где они отсортируются по ключу на этапе добавления
	std::copy(trains.begin(), trains.end(), std::ostream_iterator<Train>(std::cout));
	std::cout << "vector" << std::endl;
	std::copy(trains.begin(), trains.end(), back_inserter(array));
	string city;
	std::cin >> city;
	std::copy_if(array.begin(), array.end(), std::ostream_iterator<Train>(std::cout), [city](const Train&obj) 
	{
		return obj.getDestination() == city;
		

	});
	std::cout<<std::endl;

	/*std::sort(array.begin(), array.end(), [](const Train& obj1, const Train& obj2) 
	{
		if (obj1.getHours()<obj2.getHours())
		{
			return true;
		}
		else if (obj1.getHours() ==obj2.getHours())
		{
			return obj1.getMinutes() < obj2.getMinutes() ? true:false ;
		}
		else
		{
			return false;
		}

	});*/
	string city1;
	std::cin >> city;
	std::cin >> city1;
	std::replace_if(array.begin(), array.end(), [city](const Train&obj) 
	{
		return obj.getDestination()==city ;

	}, city1);
	std::copy(array.begin(), array.end(), std::ostream_iterator<Train>(std::cout));

	system("pause");
	return 0;
}