#include <iostream>
#include <vector>

void fieldSection(const std::vector<std::vector <std::vector<int>>> v, int sectionNumber ){
    std::cout << std::endl;
    for(int i = 0; i < v.size(); ++i)
    {
        for(int j = 0; j < v[i].size(); ++j)
        {
            std::cout << v[i][j][sectionNumber] << " ";
        }
        std::cout << std::endl;
    }
}

void fillField(std::vector<std::vector <std::vector<int>>> &v){
    int height;
    for(int i = 0; i < v.size(); ++i){
        for(int j = 0; j < v[i].size(); ++j){
            std::cout << "post height " << i << ":" << j << " - ";
            std::cin >> height;

            while(height > 10 || height < 0){
                std::cout << "Incorrect input!!!" << std::endl;
                std::cin >> height;
            }
            for(int k = 0; k < height; ++k){
                v[i][j][k] = 1;
            }
        }
    }
}

int main()
{
   std::cout << "Almost-Minecraft" << std::endl;
     std::vector<std::vector <std::vector<int>>> buildings(5, std::vector<std::vector<int>>(5, std::vector <int> (10)) );

     fillField(buildings);
     std::cout << std::endl << "Enter section number: ";
     int sectionNumber;
     std::cin >> sectionNumber;
     while(sectionNumber > 9 || sectionNumber < 0){
         std::cout << "Incorrect section number!" << std::endl;
         std::cin >> sectionNumber;
     }
     fieldSection(buildings, sectionNumber);

    return 0;
}


// Почти-Майнкрафт

// Нам всё-таки предстоит сделать некое подобие Майнкрафта. 
// Миллионов не обещаю, но это довольно интересная задача 
// на пространственное мышление.   У нас есть небольшой 
// квадратный ландшафт, размером 5х5 секторов. В каждом 
// секторе располагается блок (столбик) ландшафта, 
// максимальная высота которого — это 10 блоков. 
// Текущая высота каждого такого блока задаётся 
// пользователем вначале программы. Итоговая задача — используя 
// трёхмерный массив вывести в стандартный вывод 
// горизонтальное сечение (или горизонтальный срез) нашего 
// небольшого мира. Сам мир как раз должен быть представлен 
// в виде трёхмерного массива. Его горизонтальный срез 
// стало быть — это двумерный массив, который надо отобразить 
// в виде единиц и нулей. 0 — это отсутствие элемента на 
// данном уровне в данной точке, 1 — элемент есть. 
// Уровень среза от 0 до 9 включительно — также задаётся 
// в стандартном вводе.