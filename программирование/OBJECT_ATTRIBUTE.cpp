#include<iostream>
#include<string>
#include<bitset>

//свойства либо да либо нет, установлены ли они, в 1 байте:
enum OBJECT_ATTRIBUTE : uint8_t {                       //свойства объекта
	DESTROYABLE = 1<<0,             // 0000 0001       //разрушаемый объект или нет
	MOVABLE     = 1 << 1,          // 0000 0010       //можно двигать или нет
	TRANSPARENT = 1 << 2,         // 0000 0100       //прозрачный или нет
	IS_LIGHT    = 1 << 3,        // 0000 1000       //является ли он светом или нет
	HAS_SHADOWS = 1 << 4,                          //имеет ли он тени
	RESERVED_1  = 1 << 5,                         //резервные 
	RESERVED_2  = 1 << 6,                        //резервные 
	RESERVED_3  = 1 << 7                        //резервные 
};
int main()
{
	uint8_t objectDescription = 0;      //описание объекта
	//наложение маски:
	objectDescription |= IS_LIGHT | MOVABLE;  //создадим объект и он является светом и его можно двигать
	  
	//накладываем маску 0000 1000
	//	      и эту     0000 0010    
	//	       получаем 0000 1010 биты не пересекаются, устанавливаются биты, которые нам и нужны
	//	в 1 байте можем сохранять разные значения.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	uint8_t objectDescription2 = DESTROYABLE;
	objectDescription2 |= IS_LIGHT | MOVABLE;

	//накладываем эти маски
	//  0000 0001
	//	0000 0010
	//	0000 1000
	//	получаем = 0000 1011

	//проверим какими свойства обладает наш объект:
	bool isDestroyble = objectDescription2 & DESTROYABLE;  //проверяем разрушаемый ли наш объект операция и-& наложим маску DESTROYABLE

	//	если мы наложили еще маску & DESTROYABLE через (и&) то
	//	&0000 0001
	//	получаем тот бит который соотвуствует нашей маски 
	//	= 0000 0001 будет тру т.к не равно нулю и значит маска DESTROYABLE есть

	bool isLight = objectDescription & IS_LIGHT;            //проверить есть ли свет
	bool hasShadows = objectDescription & HAS_SHADOWS;     //проверить есть ли тень

		//выведем на экран:
	std::cout << isDestroyble << std::endl;
	std::cout << isLight << std::endl;
	std::cout << hasShadows << std::endl;
	// 1- yes, 0-no

	getchar();
	return 0;
}